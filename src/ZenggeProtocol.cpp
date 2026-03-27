#include "ZenggeProtocol.h"
#include <QDebug>

ZenggeProtocol::ZenggeProtocol(QObject* parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
    connect(m_socket, &QTcpSocket::connected, this, &ZenggeProtocol::connected);
    connect(m_socket, &QTcpSocket::disconnected, this, &ZenggeProtocol::disconnected);
    connect(m_socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, [this](QAbstractSocket::SocketError) {
        emit error(m_socket->errorString());
    });
}

ZenggeProtocol::~ZenggeProtocol()
{
    disconnectFromBulb();
}

// ─── Connection ────────────────────────────────────────────

bool ZenggeProtocol::connectToBulb(const QString& ip, uint16_t port)
{
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        disconnectFromBulb();
    }

    m_socket->connectToHost(ip, port);
    if (!m_socket->waitForConnected(CONNECT_TIMEOUT_MS)) {
        emit error(QString("Failed to connect to %1:%2 - %3")
                   .arg(ip).arg(port).arg(m_socket->errorString()));
        return false;
    }
    return true;
}

void ZenggeProtocol::disconnectFromBulb()
{
    if (m_socket->state() != QAbstractSocket::UnconnectedState) {
        m_socket->disconnectFromHost();
        if (m_socket->state() != QAbstractSocket::UnconnectedState) {
            m_socket->waitForDisconnected(1000);
        }
    }
}

bool ZenggeProtocol::isConnected() const
{
    return m_socket->state() == QAbstractSocket::ConnectedState;
}

// ─── Checksum Utilities ────────────────────────────────────

uint8_t ZenggeProtocol::calculateChecksum(const QByteArray& data)
{
    uint32_t sum = 0;
    for (int i = 0; i < data.size(); ++i) {
        sum += static_cast<uint8_t>(data[i]);
    }
    return static_cast<uint8_t>(sum & 0xFF);
}

QByteArray ZenggeProtocol::appendChecksum(const QByteArray& data)
{
    QByteArray result = data;
    result.append(static_cast<char>(calculateChecksum(data)));
    return result;
}

uint8_t ZenggeProtocol::speedToDelay(uint8_t speed)
{
    // Speed 0-100 maps to delay 0x1F (fastest) to 0x01 (slowest)
    // Based on flux_led: delay = (100 - speed) * 0x1E / 100 + 1
    if (speed > 100) speed = 100;
    int delay = static_cast<int>((100 - speed) * 0x1E) / 100 + 1;
    return static_cast<uint8_t>(delay);
}

// ─── Send / Receive ────────────────────────────────────────

bool ZenggeProtocol::sendCommand(const QByteArray& command)
{
    if (!isConnected()) {
        emit error("Not connected to bulb");
        return false;
    }

    qint64 written = m_socket->write(command);
    if (written != command.size()) {
        emit error("Failed to write full command");
        return false;
    }
    m_socket->flush();
    return true;
}

QByteArray ZenggeProtocol::sendAndReceive(const QByteArray& command, int expectedResponseLen)
{
    if (!sendCommand(command)) {
        return QByteArray();
    }

    if (!m_socket->waitForReadyRead(READ_TIMEOUT_MS)) {
        emit error("Timeout waiting for response");
        return QByteArray();
    }

    QByteArray response;
    while (response.size() < expectedResponseLen && m_socket->bytesAvailable() > 0) {
        response.append(m_socket->readAll());
        if (response.size() < expectedResponseLen) {
            m_socket->waitForReadyRead(500);
        }
    }

    return response;
}

// ─── Power Commands ────────────────────────────────────────

QByteArray ZenggeProtocol::buildPowerOn()
{
    QByteArray cmd;
    cmd.append(static_cast<char>(0x71));
    cmd.append(static_cast<char>(0x23));
    cmd.append(static_cast<char>(0x0F));
    return appendChecksum(cmd);
}

QByteArray ZenggeProtocol::buildPowerOff()
{
    QByteArray cmd;
    cmd.append(static_cast<char>(0x71));
    cmd.append(static_cast<char>(0x24));
    cmd.append(static_cast<char>(0x0F));
    return appendChecksum(cmd);
}

// ─── State Query ───────────────────────────────────────────

QByteArray ZenggeProtocol::buildStateQuery()
{
    QByteArray cmd;
    cmd.append(static_cast<char>(0x81));
    cmd.append(static_cast<char>(0x8A));
    cmd.append(static_cast<char>(0x8B));
    return appendChecksum(cmd);
}

BulbState ZenggeProtocol::parseStateResponse(const QByteArray& data)
{
    BulbState state;
    if (data.size() < 14) {
        qWarning() << "Invalid state response length:" << data.size();
        return state;
    }

    state.head          = static_cast<uint8_t>(data[0]);
    state.modelNum      = static_cast<uint8_t>(data[1]);
    state.powerState    = static_cast<uint8_t>(data[2]);
    state.presetPattern = static_cast<uint8_t>(data[3]);
    state.mode          = static_cast<uint8_t>(data[4]);
    state.speed         = static_cast<uint8_t>(data[5]);
    state.red           = static_cast<uint8_t>(data[6]);
    state.green         = static_cast<uint8_t>(data[7]);
    state.blue          = static_cast<uint8_t>(data[8]);
    state.warmWhite     = static_cast<uint8_t>(data[9]);
    state.versionNum    = static_cast<uint8_t>(data[10]);
    state.coolWhite     = static_cast<uint8_t>(data[11]);
    state.colorMode     = static_cast<uint8_t>(data[12]);
    state.checkSum      = static_cast<uint8_t>(data[13]);

    // Validate checksum
    uint8_t expected = calculateChecksum(data.left(13));
    if (expected != state.checkSum) {
        qWarning() << "State response checksum mismatch: expected"
                    << expected << "got" << state.checkSum;
    }

    return state;
}

// ─── Color / Level Control (9-byte LEDENET) ────────────────

QByteArray ZenggeProtocol::buildSetLevels(bool persist, uint8_t r, uint8_t g, uint8_t b,
                                           uint8_t warmWhite, uint8_t coolWhite, WriteMode mode)
{
    // 9-byte format:
    //  0: 0x31 (persist) or 0x41 (volatile)
    //  1: Red
    //  2: Green
    //  3: Blue
    //  4: Warm White
    //  5: Cool White
    //  6: Write Mode (0xF0 color, 0x0F white, 0x00 both)
    //  7: 0x0F terminator
    //  8: checksum
    QByteArray cmd;
    cmd.append(static_cast<char>(persist ? 0x31 : 0x41));
    cmd.append(static_cast<char>(r));
    cmd.append(static_cast<char>(g));
    cmd.append(static_cast<char>(b));
    cmd.append(static_cast<char>(warmWhite));
    cmd.append(static_cast<char>(coolWhite));
    cmd.append(static_cast<char>(static_cast<uint8_t>(mode)));
    cmd.append(static_cast<char>(0x0F));
    return appendChecksum(cmd);
}

QByteArray ZenggeProtocol::buildSetColor(uint8_t r, uint8_t g, uint8_t b, bool persist)
{
    return buildSetLevels(persist, r, g, b, 0, 0, WriteMode::ColorOnly);
}

QByteArray ZenggeProtocol::buildSetWarmWhite(uint8_t level, bool persist)
{
    return buildSetLevels(persist, 0, 0, 0, level, 0, WriteMode::WhiteOnly);
}

QByteArray ZenggeProtocol::buildSetCoolWhite(uint8_t level, bool persist)
{
    return buildSetLevels(persist, 0, 0, 0, 0, level, WriteMode::WhiteOnly);
}

QByteArray ZenggeProtocol::buildSetWhite(uint8_t warm, uint8_t cool, bool persist)
{
    return buildSetLevels(persist, 0, 0, 0, warm, cool, WriteMode::WhiteOnly);
}

QByteArray ZenggeProtocol::buildSetColorAndWhite(uint8_t r, uint8_t g, uint8_t b,
                                                   uint8_t warm, uint8_t cool, bool persist)
{
    return buildSetLevels(persist, r, g, b, warm, cool, WriteMode::Both);
}

// ─── Preset Patterns ──────────────────────────────────────

QByteArray ZenggeProtocol::buildPresetPattern(uint8_t patternCode, uint8_t speed)
{
    // [0x61, pattern, delay, 0x0F, checksum]
    QByteArray cmd;
    cmd.append(static_cast<char>(0x61));
    cmd.append(static_cast<char>(patternCode));
    cmd.append(static_cast<char>(speedToDelay(speed)));
    cmd.append(static_cast<char>(0x0F));
    return appendChecksum(cmd);
}

// ─── Custom Effects ───────────────────────────────────────

QByteArray ZenggeProtocol::buildCustomEffect(const QVector<RGBColor>& colors,
                                               uint8_t speed, TransitionType transition)
{
    QByteArray cmd;

    // Build color entries (up to 16)
    bool first = true;
    for (const auto& color : colors) {
        if (first) {
            cmd.append(static_cast<char>(0x51));  // lead byte for first color
            first = false;
        } else {
            cmd.append(static_cast<char>(0x00));  // lead byte for subsequent
        }
        cmd.append(static_cast<char>(color.r));
        cmd.append(static_cast<char>(color.g));
        cmd.append(static_cast<char>(color.b));
    }

    // Pad empty slots to 16 total
    int remaining = 16 - colors.size();
    for (int i = 0; i < remaining; ++i) {
        cmd.append(static_cast<char>(0x00));
        cmd.append(static_cast<char>(0x01));
        cmd.append(static_cast<char>(0x02));
        cmd.append(static_cast<char>(0x03));
    }

    cmd.append(static_cast<char>(0x00));  // padding
    cmd.append(static_cast<char>(speedToDelay(speed)));
    cmd.append(static_cast<char>(static_cast<uint8_t>(transition)));
    cmd.append(static_cast<char>(0xFF));
    cmd.append(static_cast<char>(0x0F));

    return appendChecksum(cmd);
}

// ─── Music Mode ───────────────────────────────────────────

QByteArray ZenggeProtocol::buildMusicModeOn(uint8_t sensitivity)
{
    // [0x73, 0x01, sensitivity, 0x0F, checksum]
    if (sensitivity > 100) sensitivity = 100;
    QByteArray cmd;
    cmd.append(static_cast<char>(0x73));
    cmd.append(static_cast<char>(0x01));
    cmd.append(static_cast<char>(sensitivity));
    cmd.append(static_cast<char>(0x0F));
    return appendChecksum(cmd);
}

QByteArray ZenggeProtocol::buildMusicModeOff()
{
    // [0x73, 0x00, 0x59, 0x0F, checksum]
    QByteArray cmd;
    cmd.append(static_cast<char>(0x73));
    cmd.append(static_cast<char>(0x00));
    cmd.append(static_cast<char>(0x59));
    cmd.append(static_cast<char>(0x0F));
    return appendChecksum(cmd);
}

QByteArray ZenggeProtocol::buildMicEffect(MicEffect effect)
{
    // [0x37, effect, 0x00, checksum]
    QByteArray cmd;
    cmd.append(static_cast<char>(0x37));
    cmd.append(static_cast<char>(static_cast<uint8_t>(effect)));
    cmd.append(static_cast<char>(0x00));
    return appendChecksum(cmd);
}
