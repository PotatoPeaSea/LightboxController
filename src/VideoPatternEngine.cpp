#include "VideoPatternEngine.h"
#include <QFileInfo>
#include <QUrl>
#include <QImage>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardPaths>
#include <algorithm>

// ═══════════════════════════════════════════════════════════
//  Construction
// ═══════════════════════════════════════════════════════════

VideoPatternEngine::VideoPatternEngine(QObject* parent)
    : QAbstractVideoSurface(parent)
    , m_player(new QMediaPlayer(this))
    , m_playbackTimer(new QTimer(this))
{
    m_player->setVideoOutput(this);
    m_player->setMuted(true);

    connect(m_player, &QMediaPlayer::mediaStatusChanged,
            this, &VideoPatternEngine::onMediaStatusChanged);
    connect(m_player,
            QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),
            this, &VideoPatternEngine::onPlayerError);
    connect(m_player, &QMediaPlayer::positionChanged,
            this, &VideoPatternEngine::onPlayerPositionChanged);
    connect(m_player, &QMediaPlayer::durationChanged,
            this, [this](qint64 d) { m_videoDurationMs = d; });

    m_playbackTimer->setInterval(33); // ~30 fps
    connect(m_playbackTimer, &QTimer::timeout,
            this, &VideoPatternEngine::onPlaybackTick);
}

VideoPatternEngine::~VideoPatternEngine()
{
    stop();
    m_player->stop();
}

// ═══════════════════════════════════════════════════════════
//  QAbstractVideoSurface
// ═══════════════════════════════════════════════════════════

QList<QVideoFrame::PixelFormat> VideoPatternEngine::supportedPixelFormats(
    QAbstractVideoBuffer::HandleType type) const
{
    Q_UNUSED(type);
    return {
        QVideoFrame::Format_RGB32,
        QVideoFrame::Format_ARGB32,
        QVideoFrame::Format_ARGB32_Premultiplied,
        QVideoFrame::Format_RGB24,
        QVideoFrame::Format_BGR32,
        QVideoFrame::Format_BGRA32,
    };
}

bool VideoPatternEngine::present(const QVideoFrame& frame)
{
    if (!m_extracting || !frame.isValid())
        return false;

    // Throttle extraction to 5fps (every 200ms)
    qint64 currentPosMs = m_player->position();
    if (m_lastExtractedTimestampMs != -1 && (currentPosMs - m_lastExtractedTimestampMs) < 200) {
        return true; // we "handled" it but didn't extract
    }
    m_lastExtractedTimestampMs = currentPosMs;

    QVector<QColor> colors = sampleFrame(frame);
    if (colors.isEmpty())
        return false;

    PatternFrame pf;
    pf.timestampMs = m_player->position();
    pf.colors = colors;
    m_patternFrames.append(pf);

    // Update status every 10 frames to avoid spamming
    if (m_patternFrames.size() % 10 == 1) {
        int pct = (m_videoDurationMs > 0)
            ? static_cast<int>(100.0 * m_player->position() / m_videoDurationMs)
            : 0;
        setStatus(QString("Extracting... %1 frames captured (%2%)")
                  .arg(m_patternFrames.size()).arg(pct));
    }

    updateCurrentColors(colors);
    return true;
}

// ═══════════════════════════════════════════════════════════
//  Property getters
// ═══════════════════════════════════════════════════════════

QString VideoPatternEngine::source() const { return m_source; }

QString VideoPatternEngine::fileName() const
{
    if (m_source.isEmpty()) return QString();
    QUrl url(m_source);
    if (url.isLocalFile())
        return QFileInfo(url.toLocalFile()).fileName();
    return QFileInfo(m_source).fileName();
}

int VideoPatternEngine::sampleCount() const { return m_sampleCount; }
bool VideoPatternEngine::isExtracting() const { return m_extracting; }
bool VideoPatternEngine::isPatternReady() const { return m_patternReady; }
bool VideoPatternEngine::isPlaying() const { return m_playing; }
bool VideoPatternEngine::isPaused() const { return m_paused; }
bool VideoPatternEngine::isLooping() const { return m_looping; }
qreal VideoPatternEngine::playbackSpeed() const { return m_playbackSpeed; }

qreal VideoPatternEngine::extractionProgress() const
{
    if (m_videoDurationMs <= 0) return 0.0;
    return static_cast<qreal>(m_player->position()) / m_videoDurationMs;
}

int VideoPatternEngine::patternDurationMs() const
{
    if (m_patternFrames.isEmpty()) return 0;
    return static_cast<int>(m_patternFrames.last().timestampMs);
}

int VideoPatternEngine::patternFrameCount() const
{
    return m_patternFrames.size();
}

int VideoPatternEngine::playbackPositionMs() const
{
    if (!m_playing) return 0;
    if (m_paused) return static_cast<int>(m_playbackOffsetMs);
    return static_cast<int>(m_playbackOffsetMs + (m_playbackClock.elapsed() * m_playbackSpeed));
}

QVariantList VideoPatternEngine::currentColors() const { return m_currentColors; }
int VideoPatternEngine::targetBulbCount() const { return m_targetBulbs.size(); }
QString VideoPatternEngine::statusMessage() const { return m_statusMessage; }

// ═══════════════════════════════════════════════════════════
//  Property setters
// ═══════════════════════════════════════════════════════════

void VideoPatternEngine::setSampleCount(int count)
{
    count = qBound(1, count, 20);
    if (m_sampleCount != count) {
        m_sampleCount = count;
        emit sampleCountChanged();
    }
}

void VideoPatternEngine::setLooping(bool loop)
{
    if (m_looping != loop) {
        m_looping = loop;
        emit loopingChanged();
    }
}

void VideoPatternEngine::setPlaybackSpeed(qreal speed)
{
    // Clamp speed to a reasonable range
    speed = qBound(0.1, speed, 10.0);
    if (!qFuzzyCompare(m_playbackSpeed, speed)) {
        // If currently playing, bake the elapsed time at the old speed into the offset
        if (m_playing && !m_paused) {
            m_playbackOffsetMs += static_cast<qint64>(m_playbackClock.elapsed() * m_playbackSpeed);
            m_playbackClock.restart();
        }
        m_playbackSpeed = speed;
        emit playbackSpeedChanged();
    }
}

void VideoPatternEngine::setPlaybackPositionMs(int ms)
{
    if (!m_patternReady || m_patternFrames.isEmpty()) return;

    ms = qBound(0, ms, patternDurationMs());

    m_playbackOffsetMs = ms;
    if (m_playing && !m_paused) {
        m_playbackClock.restart();
    }

    int frameIndex = 0;
    while (frameIndex + 1 < m_patternFrames.size()
           && m_patternFrames[frameIndex + 1].timestampMs <= ms) {
        ++frameIndex;
    }

    if (frameIndex != m_currentFrameIndex) {
        m_currentFrameIndex = frameIndex;
        const auto& colors = m_patternFrames[frameIndex].colors;
        updateCurrentColors(colors);
        dispatchColors(colors);
    }

    emit playbackPositionChanged();
}


// ═══════════════════════════════════════════════════════════
//  Commands
// ═══════════════════════════════════════════════════════════

void VideoPatternEngine::loadVideo(const QString& url)
{
    stop();
    m_player->stop();
    m_patternFrames.clear();
    m_patternReady = false;
    m_currentColors.clear();

    QUrl mediaUrl(url);
    if (mediaUrl.scheme().isEmpty()) {
        // Treat as a local file path
        m_source = QUrl::fromLocalFile(url).toString();
    } else {
        m_source = url;
    }

    m_player->setMedia(QUrl(m_source));

    emit sourceChanged();
    emit patternReadyChanged();
    emit currentColorsChanged();

    setStatus("Video loaded: " + fileName());
    qDebug() << "[Pattern] Video loaded:" << m_source;
}

void VideoPatternEngine::extractPattern()
{
    if (m_source.isEmpty()) {
        emit errorOccurred("No video loaded");
        return;
    }

    stop();
    m_patternFrames.clear();
    m_patternReady = false;
    m_extracting = true;
    m_currentColors.clear();
    m_lastExtractedTimestampMs = -1;

    emit extractingChanged();
    emit patternReadyChanged();
    emit currentColorsChanged();

    m_player->setPosition(0);
    m_player->play();

    setStatus("Starting extraction (" + QString::number(m_sampleCount) + " sample points)...");
    qDebug() << "[Pattern] Extraction started, sampleCount =" << m_sampleCount;
}

void VideoPatternEngine::cancelExtraction()
{
    if (m_extracting) {
        m_player->stop();
        m_extracting = false;
        m_patternFrames.clear();
        emit extractingChanged();
        setStatus("Extraction cancelled");
        qDebug() << "[Pattern] Extraction cancelled";
    }
}

void VideoPatternEngine::play()
{
    if (!m_patternReady || m_patternFrames.isEmpty()) {
        emit errorOccurred("No pattern extracted yet");
        return;
    }

    if (m_paused) {
        // Resume
        m_paused = false;
        m_playbackClock.restart();
        m_playbackTimer->start();
    } else {
        // Fresh start
        m_currentFrameIndex = 0;
        m_playbackOffsetMs = 0;
        m_playing = true;
        m_paused = false;
        m_playbackClock.restart();
        m_playbackTimer->start();
    }
    emit playStateChanged();
    setStatus(m_paused ? "Resumed playback" : "Playing pattern (" + QString::number(m_patternFrames.size()) + " frames)");
}

void VideoPatternEngine::pause()
{
    if (m_playing && !m_paused) {
        m_paused = true;
        m_playbackOffsetMs += static_cast<qint64>(m_playbackClock.elapsed() * m_playbackSpeed);
        m_playbackTimer->stop();
        emit playStateChanged();
        setStatus("Paused at " + QString::number(m_playbackOffsetMs / 1000.0, 'f', 1) + "s");
    }
}

void VideoPatternEngine::stop()
{
    m_playing = false;
    m_paused = false;
    m_playbackTimer->stop();
    m_currentFrameIndex = 0;
    m_playbackOffsetMs = 0;
    m_currentColors.clear();
    emit playStateChanged();
    emit playbackPositionChanged();
    emit currentColorsChanged();
    setStatus("Stopped");
}

void VideoPatternEngine::setTargetBulbs(QVariantList bulbs)
{
    m_targetBulbs.clear();
    m_leftBulbs.clear();
    m_rightBulbs.clear();
    for (const auto& v : bulbs) {
        Bulb* b = qobject_cast<Bulb*>(v.value<QObject*>());
        if (b) {
            m_targetBulbs.append(b);
            if (b->isLeft()) {
                m_leftBulbs.append(b);
            } else {
                m_rightBulbs.append(b);
            }
        }
    }

    // Sort by depth ascending
    std::sort(m_leftBulbs.begin(), m_leftBulbs.end(),
              [](Bulb* a, Bulb* b) { return a->depth() < b->depth(); });
    std::sort(m_rightBulbs.begin(), m_rightBulbs.end(),
              [](Bulb* a, Bulb* b) { return a->depth() < b->depth(); });

    emit targetBulbsChanged();
    setStatus(QString("%1 bulb(s) assigned (Left: %2, Right: %3)")
              .arg(m_targetBulbs.size())
              .arg(m_leftBulbs.size())
              .arg(m_rightBulbs.size()));
    qDebug() << "[Pattern] Target bulbs:" << m_targetBulbs.size() << "Left:" << m_leftBulbs.size() << "Right:" << m_rightBulbs.size();
}

void VideoPatternEngine::clearTargetBulbs()
{
    m_targetBulbs.clear();
    m_leftBulbs.clear();
    m_rightBulbs.clear();
    emit targetBulbsChanged();
}

// ═══════════════════════════════════════════════════════════
//  Private slots
// ═══════════════════════════════════════════════════════════

void VideoPatternEngine::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    // Always log status transitions for debugging
    static const char* names[] = {
        "UnknownMediaStatus", "NoMedia", "LoadingMedia", "LoadedMedia",
        "StalledMedia", "BufferingMedia", "BufferedMedia",
        "EndOfMedia", "InvalidMedia"
    };
    const char* name = (status >= 0 && status <= 8) ? names[status] : "???";
    qDebug() << "[Pattern] Media status:" << name << "(" << status << ")"
             << " extracting=" << m_extracting
             << " frames=" << m_patternFrames.size();

    if (status == QMediaPlayer::EndOfMedia && m_extracting) {
        m_extracting = false;
        m_patternReady = !m_patternFrames.isEmpty();
        m_player->stop();

        emit extractingChanged();
        emit patternReadyChanged();
        emit extractionComplete(m_patternFrames.size());

        setStatus(QString("Extraction complete: %1 frames, %2s")
                  .arg(m_patternFrames.size())
                  .arg(patternDurationMs() / 1000.0, 0, 'f', 1));
        qDebug() << "[Pattern] Extraction done:" << m_patternFrames.size()
                 << "frames," << patternDurationMs() << "ms";

    } else if (status == QMediaPlayer::InvalidMedia) {
        QString msg = m_player->errorString();
        if (msg.isEmpty()) msg = "Media format not supported";
        qWarning() << "[Pattern] Invalid media:" << msg;

        if (m_extracting) {
            m_extracting = false;
            m_patternFrames.clear();
            emit extractingChanged();
        }
        setStatus("Error: " + msg);
        emit errorOccurred(msg);

    } else if (status == QMediaPlayer::LoadedMedia) {
        setStatus(QString("Media loaded (%1ms). Ready to extract.")
                  .arg(m_videoDurationMs));

    } else if (status == QMediaPlayer::BufferedMedia && m_extracting) {
        setStatus(QString("Extracting... buffered, %1 frames so far")
                  .arg(m_patternFrames.size()));
    }
}

void VideoPatternEngine::onPlayerError(QMediaPlayer::Error error)
{
    Q_UNUSED(error);
    QString msg = m_player->errorString();
    qWarning() << "Media error:" << msg;

    if (m_extracting) {
        m_extracting = false;
        emit extractingChanged();
    }
    setStatus("Error: " + msg);
    emit errorOccurred(msg);
}

void VideoPatternEngine::onPlayerPositionChanged(qint64 position)
{
    Q_UNUSED(position);
    if (m_extracting)
        emit extractionProgressChanged();
}

void VideoPatternEngine::onPlaybackTick()
{
    if (!m_playing || m_paused || m_patternFrames.isEmpty())
        return;

    qint64 elapsedMs = m_playbackOffsetMs + static_cast<qint64>(m_playbackClock.elapsed() * m_playbackSpeed);
    int duration = patternDurationMs();

    if (duration <= 0) { stop(); return; }

    // Handle looping / end
    if (elapsedMs >= duration) {
        if (m_looping) {
            m_playbackOffsetMs = elapsedMs % duration;
            m_playbackClock.restart();
            elapsedMs = m_playbackOffsetMs;
        } else {
            stop();
            return;
        }
    }

    // Binary-ish search for nearest frame at or before elapsedMs
    int frameIndex = m_currentFrameIndex;
    // Fast-forward
    while (frameIndex + 1 < m_patternFrames.size()
           && m_patternFrames[frameIndex + 1].timestampMs <= elapsedMs) {
        ++frameIndex;
    }
    // Rewind (in case of loop reset)
    if (m_patternFrames[frameIndex].timestampMs > elapsedMs) {
        frameIndex = 0;
        while (frameIndex + 1 < m_patternFrames.size()
               && m_patternFrames[frameIndex + 1].timestampMs <= elapsedMs) {
            ++frameIndex;
        }
    }

    if (frameIndex != m_currentFrameIndex || m_currentColors.isEmpty()) {
        m_currentFrameIndex = frameIndex;
        const auto& colors = m_patternFrames[frameIndex].colors;
        updateCurrentColors(colors);
        dispatchColors(colors);
    }

    emit playbackPositionChanged();
}

// ═══════════════════════════════════════════════════════════
//  Frame sampling
// ═══════════════════════════════════════════════════════════

QVector<QColor> VideoPatternEngine::sampleFrame(const QVideoFrame& frame)
{
    QVideoFrame f(frame);
    QVector<QColor> colors;

    if (!f.map(QAbstractVideoBuffer::ReadOnly)) {
        qWarning() << "Failed to map video frame";
        return colors;
    }

    int w = f.width();
    int h = f.height();
    if (w <= 0 || h <= 0) { f.unmap(); return colors; }

    // Build a QImage view over the mapped buffer
    QImage::Format imgFmt =
        QVideoFrame::imageFormatFromPixelFormat(f.pixelFormat());

    if (imgFmt == QImage::Format_Invalid) {
        qWarning() << "Unsupported pixel format" << f.pixelFormat();
        f.unmap();
        return colors;
    }

    // Zero-copy image wrapper
    QImage img(f.bits(), w, h, f.bytesPerLine(), imgFmt);

    int leftCount = std::ceil(m_sampleCount / 2.0);
    int rightCount = std::floor(m_sampleCount / 2.0);

    auto extractGridAverage = [&](int startX, int endX, int count, int totalHeight) {
        if (count <= 0) return;
        int cols = std::ceil(std::sqrt(count));
        int rows = std::ceil(static_cast<float>(count) / cols);

        int cellWidth = (endX - startX) / cols;
        int cellHeight = totalHeight / rows;

        int chunksExtracted = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (chunksExtracted >= count) break;

                int chunkCx = startX + col * cellWidth + cellWidth / 2;
                int chunkCy = row * cellHeight + cellHeight / 2;

                // Center 10% of area -> scale width and height by sqrt(0.1) ~= 0.316
                int coreWidth = std::max(1, static_cast<int>(cellWidth * 0.316));
                int coreHeight = std::max(1, static_cast<int>(cellHeight * 0.316));

                int cxStart = chunkCx - coreWidth / 2;
                int cxEnd = chunkCx + coreWidth / 2;
                int cyStart = chunkCy - coreHeight / 2;
                int cyEnd = chunkCy + coreHeight / 2;

                int strideX = std::max(1, coreWidth / 5);
                int strideY = std::max(1, coreHeight / 5);

                long rSum = 0, gSum = 0, bSum = 0;
                int samplePoints = 0;

                for (int y = cyStart; y < cyEnd; y += strideY) {
                    for (int x = cxStart; x < cxEnd; x += strideX) {
                        QColor c = img.pixelColor(x, y);
                        rSum += c.red();
                        gSum += c.green();
                        bSum += c.blue();
                        samplePoints++;
                    }
                }

                if (samplePoints > 0) {
                    colors.append(QColor(rSum / samplePoints, gSum / samplePoints, bSum / samplePoints));
                } else {
                    colors.append(QColor(0, 0, 0));
                }
                chunksExtracted++;
            }
        }
    };

    int midX = w / 2;
    extractGridAverage(0, midX, leftCount, h);
    extractGridAverage(midX, w, rightCount, h);

    f.unmap();
    return colors;
}

// ═══════════════════════════════════════════════════════════
//  Color dispatch
// ═══════════════════════════════════════════════════════════

void VideoPatternEngine::dispatchColors(const QVector<QColor>& colors)
{
    if (colors.isEmpty())
        return;

    int leftCount = std::ceil(m_sampleCount / 2.0);
    int rightCount = std::floor(m_sampleCount / 2.0);

    int leftLimit = qMin(leftCount, static_cast<int>(colors.size()));
    int rightLimit = qMin(rightCount, static_cast<int>(colors.size()) - leftLimit);

    int lBulbs = qMin(leftLimit, static_cast<int>(m_leftBulbs.size()));
    for (int i = 0; i < lBulbs; ++i) {
        const QColor& c = colors[i];
        m_leftBulbs[i]->setColor(c.red(), c.green(), c.blue());
    }

    int rBulbs = qMin(rightLimit, static_cast<int>(m_rightBulbs.size()));
    for (int i = 0; i < rBulbs; ++i) {
        const QColor& c = colors[leftCount + i];
        m_rightBulbs[i]->setColor(c.red(), c.green(), c.blue());
    }
}

void VideoPatternEngine::updateCurrentColors(const QVector<QColor>& colors)
{
    m_currentColors.clear();
    for (const auto& c : colors)
        m_currentColors.append(QVariant::fromValue(c));
    emit currentColorsChanged();
}

void VideoPatternEngine::setStatus(const QString& msg)
{
    m_statusMessage = msg;
    emit statusMessageChanged();
    qDebug() << "[Pattern Status]" << msg;
}

QString VideoPatternEngine::patternsDir() const
{
    QString appData = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    return appData + "/patterns";
}

// ═══════════════════════════════════════════════════════════
//  Pattern Library
// ═══════════════════════════════════════════════════════════

QStringList VideoPatternEngine::savedPatterns() const
{
    QDir dir(patternsDir());
    QStringList names;
    for (const auto& fi : dir.entryInfoList({"*.json"}, QDir::Files, QDir::Name)) {
        QFile file(fi.absoluteFilePath());
        if (file.open(QIODevice::ReadOnly)) {
            QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
            names.append(doc.object()["name"].toString(fi.baseName()));
        }
    }
    return names;
}

void VideoPatternEngine::saveCurrentPattern(const QString& name)
{
    if (!m_patternReady || m_patternFrames.isEmpty()) {
        emit errorOccurred("No pattern to save");
        return;
    }

    QDir dir(patternsDir());
    if (!dir.exists()) dir.mkpath(".");

    QJsonObject root;
    root["name"] = name;
    root["sampleCount"] = m_sampleCount;
    root["durationMs"] = patternDurationMs();

    QJsonArray frames;
    for (const auto& pf : m_patternFrames) {
        QJsonObject frame;
        frame["t"] = static_cast<double>(pf.timestampMs);
        QJsonArray colors;
        for (const auto& c : pf.colors)
            colors.append(c.name());  // "#rrggbb"
        frame["c"] = colors;
        frames.append(frame);
    }
    root["frames"] = frames;

    // Sanitize filename
    QString safeName = name;
    safeName.replace(' ', '_');
    for (QChar& ch : safeName) {
        if (!ch.isLetterOrNumber() && ch != '_' && ch != '-')
            ch = '_';
    }
    QString path = dir.filePath(safeName + ".json");

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        emit errorOccurred("Failed to save: " + file.errorString());
        return;
    }
    file.write(QJsonDocument(root).toJson(QJsonDocument::Compact));
    file.close();

    setStatus("Pattern saved: " + name);
    emit savedPatternsChanged();
    qDebug() << "[Pattern] Saved pattern" << name << "to" << path;
}

void VideoPatternEngine::loadPattern(const QString& name)
{
    QDir dir(patternsDir());
    for (const auto& fi : dir.entryInfoList({"*.json"}, QDir::Files)) {
        QFile file(fi.absoluteFilePath());
        if (!file.open(QIODevice::ReadOnly)) continue;

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject root = doc.object();
        file.close();

        if (root["name"].toString() != name) continue;

        // Found — load frames
        stop();
        m_patternFrames.clear();
        m_sampleCount = root["sampleCount"].toInt(3);

        QJsonArray frames = root["frames"].toArray();
        for (const auto& fv : frames) {
            QJsonObject fo = fv.toObject();
            PatternFrame pf;
            pf.timestampMs = static_cast<qint64>(fo["t"].toDouble());
            QJsonArray colors = fo["c"].toArray();
            for (const auto& cv : colors)
                pf.colors.append(QColor(cv.toString()));
            m_patternFrames.append(pf);
        }

        m_patternReady = !m_patternFrames.isEmpty();
        emit sampleCountChanged();
        emit patternReadyChanged();
        setStatus("Loaded: " + name + " (" + QString::number(m_patternFrames.size()) + " frames)");

        // Auto-play
        play();
        return;
    }

    emit errorOccurred("Pattern not found: " + name);
}

void VideoPatternEngine::deletePattern(const QString& name)
{
    QDir dir(patternsDir());
    for (const auto& fi : dir.entryInfoList({"*.json"}, QDir::Files)) {
        QFile file(fi.absoluteFilePath());
        if (!file.open(QIODevice::ReadOnly)) continue;
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        if (doc.object()["name"].toString() == name) {
            QFile::remove(fi.absoluteFilePath());
            setStatus("Deleted: " + name);
            emit savedPatternsChanged();
            return;
        }
    }
}
