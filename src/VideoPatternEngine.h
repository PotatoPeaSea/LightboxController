#pragma once

#include <QObject>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QVideoFrame>
#include <QMediaPlayer>
#include <QTimer>
#include <QElapsedTimer>
#include <QVector>
#include <QVariantList>
#include <QColor>
#include "Bulb.h"

struct PatternFrame {
    qint64 timestampMs;
    QVector<QColor> colors; // sampled top-to-bottom
};

class VideoPatternEngine : public QAbstractVideoSurface
{
    Q_OBJECT

    // Video source
    Q_PROPERTY(QString source READ source NOTIFY sourceChanged)
    Q_PROPERTY(QString fileName READ fileName NOTIFY sourceChanged)

    // Configuration
    Q_PROPERTY(int sampleCount READ sampleCount WRITE setSampleCount NOTIFY sampleCountChanged)
    Q_PROPERTY(bool looping READ isLooping WRITE setLooping NOTIFY loopingChanged)

    // Extraction state
    Q_PROPERTY(bool extracting READ isExtracting NOTIFY extractingChanged)
    Q_PROPERTY(qreal extractionProgress READ extractionProgress NOTIFY extractionProgressChanged)

    // Pattern data
    Q_PROPERTY(bool patternReady READ isPatternReady NOTIFY patternReadyChanged)
    Q_PROPERTY(int patternDurationMs READ patternDurationMs NOTIFY patternReadyChanged)
    Q_PROPERTY(int patternFrameCount READ patternFrameCount NOTIFY patternReadyChanged)

    // Playback state
    Q_PROPERTY(bool playing READ isPlaying NOTIFY playStateChanged)
    Q_PROPERTY(bool paused READ isPaused NOTIFY playStateChanged)
    Q_PROPERTY(int playbackPositionMs READ playbackPositionMs NOTIFY playbackPositionChanged)

    // Live output
    Q_PROPERTY(QVariantList currentColors READ currentColors NOTIFY currentColorsChanged)
    Q_PROPERTY(int targetBulbCount READ targetBulbCount NOTIFY targetBulbsChanged)
    Q_PROPERTY(QString statusMessage READ statusMessage NOTIFY statusMessageChanged)
    Q_PROPERTY(QStringList savedPatterns READ savedPatterns NOTIFY savedPatternsChanged)

public:
    explicit VideoPatternEngine(QObject* parent = nullptr);
    ~VideoPatternEngine();

    // ─── QAbstractVideoSurface ────────────────────────
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
        QAbstractVideoBuffer::HandleType type = QAbstractVideoBuffer::NoHandle) const override;
    bool present(const QVideoFrame& frame) override;

    // ─── Property getters ─────────────────────────────
    QString source() const;
    QString fileName() const;
    int sampleCount() const;
    bool isExtracting() const;
    bool isPatternReady() const;
    bool isPlaying() const;
    bool isPaused() const;
    bool isLooping() const;
    qreal extractionProgress() const;
    int patternDurationMs() const;
    int patternFrameCount() const;
    int playbackPositionMs() const;
    QVariantList currentColors() const;
    int targetBulbCount() const;
    QString statusMessage() const;
    QStringList savedPatterns() const;

    // ─── Property setters ─────────────────────────────
    void setSampleCount(int count);
    void setLooping(bool loop);

    // ─── Commands (Q_INVOKABLE for QML) ───────────────
    Q_INVOKABLE void loadVideo(const QString& url);
    Q_INVOKABLE void extractPattern();
    Q_INVOKABLE void cancelExtraction();
    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void setTargetBulbs(QVariantList bulbs);
    Q_INVOKABLE void clearTargetBulbs();
    Q_INVOKABLE void saveCurrentPattern(const QString& name);
    Q_INVOKABLE void loadPattern(const QString& name);
    Q_INVOKABLE void deletePattern(const QString& name);

signals:
    void sourceChanged();
    void sampleCountChanged();
    void extractingChanged();
    void extractionProgressChanged();
    void patternReadyChanged();
    void playStateChanged();
    void loopingChanged();
    void playbackPositionChanged();
    void currentColorsChanged();
    void targetBulbsChanged();
    void extractionComplete(int frameCount);
    void errorOccurred(const QString& message);
    void statusMessageChanged();
    void savedPatternsChanged();

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void onPlayerError(QMediaPlayer::Error error);
    void onPlayerPositionChanged(qint64 position);
    void onPlaybackTick();

private:
    QVector<QColor> sampleFrame(const QVideoFrame& frame);
    void dispatchColors(const QVector<QColor>& colors);
    void updateCurrentColors(const QVector<QColor>& colors);
    void setStatus(const QString& msg);
    QString patternsDir() const;

    QMediaPlayer* m_player = nullptr;
    QString m_source;
    int m_sampleCount = 3;
    bool m_extracting = false;
    bool m_patternReady = false;
    bool m_playing = false;
    bool m_paused = false;
    bool m_looping = true;

    // Extraction storage
    QVector<PatternFrame> m_patternFrames;
    qint64 m_videoDurationMs = 0;

    // Playback
    QTimer* m_playbackTimer = nullptr;
    QElapsedTimer m_playbackClock;
    qint64 m_playbackOffsetMs = 0;
    int m_currentFrameIndex = 0;
    QVariantList m_currentColors;

    // Target bulbs sorted by Z ascending (farthest first)
    QList<Bulb*> m_targetBulbs;

    QString m_statusMessage;
};
