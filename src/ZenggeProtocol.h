#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <QVector>
#include <QString>
#include <cstdint>

// Transition types for custom effects
enum class TransitionType : uint8_t {
    Gradual = 0x3A,
    Jump    = 0x3B,
    Strobe  = 0x3C
};

// Mic effect types
enum class MicEffect : uint8_t {
    FadeIn  = 0x00,
    Gradual = 0x01,
    Jump    = 0x02,
    Strobe  = 0x03
};

// Write mode for color/white commands
enum class WriteMode : uint8_t {
    ColorOnly = 0xF0,
    WhiteOnly = 0x0F,
    Both      = 0x00
};

// Parsed bulb state from query response
struct BulbState {
    uint8_t head = 0;
    uint8_t modelNum = 0;
    uint8_t powerState = 0;     // 0x23 = on, 0x24 = off
    uint8_t presetPattern = 0;
    uint8_t mode = 0;
    uint8_t speed = 0;
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    uint8_t warmWhite = 0;
    uint8_t versionNum = 0;
    uint8_t coolWhite = 0;
    uint8_t colorMode = 0;
    uint8_t checkSum = 0;

    bool isOn() const { return powerState == 0x23; }
    bool isValid() const { return head == 0x81; }
};

// Discovered bulb info from UDP scan
struct DiscoveredBulb {
    QString ip;
    QString mac;
    QString model;
    int modelNum = 0;
    int versionNum = 0;
};

// Color tuple
struct RGBColor {
    uint8_t r, g, b;
};


class ZenggeProtocol : public QObject
{
    Q_OBJECT

public:
    static constexpr uint16_t CONTROL_PORT = 5577;
    static constexpr int CONNECT_TIMEOUT_MS = 3000;
    static constexpr int READ_TIMEOUT_MS = 2000;

    explicit ZenggeProtocol(QObject* parent = nullptr);
    ~ZenggeProtocol();

    // Connection management
    bool connectToBulb(const QString& ip, uint16_t port = CONTROL_PORT);
    void disconnectFromBulb();
    bool isConnected() const;

    // Power control
    QByteArray buildPowerOn();
    QByteArray buildPowerOff();

    // State query
    QByteArray buildStateQuery();
    BulbState parseStateResponse(const QByteArray& data);

    // Color & brightness (9-byte LEDENET)
    QByteArray buildSetColor(uint8_t r, uint8_t g, uint8_t b, bool persist = true);
    QByteArray buildSetWarmWhite(uint8_t level, bool persist = true);
    QByteArray buildSetCoolWhite(uint8_t level, bool persist = true);
    QByteArray buildSetWhite(uint8_t warm, uint8_t cool, bool persist = true);
    QByteArray buildSetColorAndWhite(uint8_t r, uint8_t g, uint8_t b,
                                      uint8_t warm, uint8_t cool, bool persist = true);
    QByteArray buildSetLevels(bool persist, uint8_t r, uint8_t g, uint8_t b,
                               uint8_t warmWhite, uint8_t coolWhite, WriteMode mode);

    // Preset patterns
    QByteArray buildPresetPattern(uint8_t patternCode, uint8_t speed);

    // Custom effects (up to 16 colors)
    QByteArray buildCustomEffect(const QVector<RGBColor>& colors, uint8_t speed,
                                  TransitionType transition);

    // Music mode
    QByteArray buildMusicModeOn(uint8_t sensitivity);
    QByteArray buildMusicModeOff();
    QByteArray buildMicEffect(MicEffect effect);

    // Send command and optionally read response
    bool sendCommand(const QByteArray& command);
    QByteArray sendAndReceive(const QByteArray& command, int expectedResponseLen);

    // Utilities
    static uint8_t calculateChecksum(const QByteArray& data);
    static QByteArray appendChecksum(const QByteArray& data);
    static uint8_t speedToDelay(uint8_t speed);

signals:
    void connected();
    void disconnected();
    void error(const QString& message);

private:
    QTcpSocket* m_socket = nullptr;
};
