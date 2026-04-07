#include "Bulb.h"
#include <QJsonObject>
#include <QDebug>

Bulb::Bulb(QObject* parent)
    : QObject(parent)
    , m_protocol(new ZenggeProtocol(this))
{
    connect(m_protocol, &ZenggeProtocol::connected, this, &Bulb::onProtocolConnected);
    connect(m_protocol, &ZenggeProtocol::disconnected, this, &Bulb::onProtocolDisconnected);
    connect(m_protocol, &ZenggeProtocol::error, this, &Bulb::onProtocolError);
}

Bulb::Bulb(const QString& ip, const QString& mac, const QString& model, QObject* parent)
    : Bulb(parent)
{
    m_ip = ip;
    m_mac = mac;
    m_model = model;
}

Bulb::~Bulb()
{
    disconnectFromBulb();
}

// ─── Getters that compute ──────────────────────────────────

bool Bulb::isConnected() const
{
    return m_protocol && m_protocol->isConnected();
}

QColor Bulb::displayColor() const
{
    if (!m_power) {
        return QColor(40, 40, 40);  // Dark gray when off
    }
    return QColor(m_red, m_green, m_blue);
}

// ─── Setters ───────────────────────────────────────────────

void Bulb::setIp(const QString& ip)
{
    if (m_ip != ip) { m_ip = ip; emit ipChanged(); }
}

void Bulb::setMac(const QString& mac)
{
    if (m_mac != mac) { m_mac = mac; emit macChanged(); }
}

void Bulb::setLabel(const QString& label)
{
    if (m_label != label) { m_label = label; emit labelChanged(); }
}

void Bulb::setModel(const QString& model)
{
    if (m_model != model) { m_model = model; emit modelChanged(); }
}

void Bulb::setPower(bool on)
{
    if (m_power != on) {
        m_power = on;
        emit powerChanged();
        emit colorChanged();  // displayColor depends on power
    }
}

void Bulb::setRed(int r)
{
    r = qBound(0, r, 255);
    if (m_red != r) { m_red = r; emit colorChanged(); }
}

void Bulb::setGreen(int g)
{
    g = qBound(0, g, 255);
    if (m_green != g) { m_green = g; emit colorChanged(); }
}

void Bulb::setBlue(int b)
{
    b = qBound(0, b, 255);
    if (m_blue != b) { m_blue = b; emit colorChanged(); }
}

void Bulb::setWarmWhite(int ww)
{
    ww = qBound(0, ww, 255);
    if (m_warmWhite != ww) { m_warmWhite = ww; emit whiteChanged(); }
}

void Bulb::setCoolWhite(int cw)
{
    cw = qBound(0, cw, 255);
    if (m_coolWhite != cw) { m_coolWhite = cw; emit whiteChanged(); }
}

void Bulb::setPosX(float x)
{
    if (!qFuzzyCompare(m_posX, x)) { m_posX = x; emit positionChanged(); }
}

void Bulb::setPosY(float y)
{
    if (!qFuzzyCompare(m_posY, y)) { m_posY = y; emit positionChanged(); }
}

void Bulb::setPosZ(float z)
{
    if (!qFuzzyCompare(m_posZ, z)) { m_posZ = z; emit positionChanged(); }
}

void Bulb::setIsLeft(bool isLeft)
{
    if (m_isLeft != isLeft) { m_isLeft = isLeft; emit isLeftChanged(); }
}

void Bulb::setDepth(int depth)
{
    if (m_depth != depth) { m_depth = depth; emit depthChanged(); }
}

void Bulb::setSelected(bool selected)
{
    if (m_selected != selected) { m_selected = selected; emit selectedChanged(); }
}

// ─── Commands ──────────────────────────────────────────────

void Bulb::connectToBulb()
{
    if (m_ip.isEmpty()) {
        emit error("No IP address set");
        return;
    }
    m_protocol->connectToBulb(m_ip);
}

void Bulb::disconnectFromBulb()
{
    if (m_protocol) {
        m_protocol->disconnectFromBulb();
    }
}

void Bulb::turnOn()
{
    if (!isConnected()) connectToBulb();
    if (!isConnected()) return;

    m_protocol->sendCommand(m_protocol->buildPowerOn());
    setPower(true);
}

void Bulb::turnOff()
{
    if (!isConnected()) connectToBulb();
    if (!isConnected()) return;

    m_protocol->sendCommand(m_protocol->buildPowerOff());
    setPower(false);
}

void Bulb::setColor(int r, int g, int b)
{
    if (!isConnected()) connectToBulb();
    if (!isConnected()) return;

    setRed(r);
    setGreen(g);
    setBlue(b);

    m_protocol->sendCommand(m_protocol->buildSetColor(
        static_cast<uint8_t>(r),
        static_cast<uint8_t>(g),
        static_cast<uint8_t>(b)));
}

void Bulb::setWhite(int warm, int cool)
{
    if (!isConnected()) connectToBulb();
    if (!isConnected()) return;

    setWarmWhite(warm);
    setCoolWhite(cool);

    m_protocol->sendCommand(m_protocol->buildSetWhite(
        static_cast<uint8_t>(warm),
        static_cast<uint8_t>(cool)));
}

void Bulb::setColorAndWhite(int r, int g, int b, int warm, int cool)
{
    if (!isConnected()) connectToBulb();
    if (!isConnected()) return;

    setRed(r);
    setGreen(g);
    setBlue(b);
    setWarmWhite(warm);
    setCoolWhite(cool);

    m_protocol->sendCommand(m_protocol->buildSetColorAndWhite(
        static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b),
        static_cast<uint8_t>(warm), static_cast<uint8_t>(cool)));
}

void Bulb::queryState()
{
    if (!isConnected()) connectToBulb();
    if (!isConnected()) return;

    QByteArray response = m_protocol->sendAndReceive(m_protocol->buildStateQuery(), 14);
    if (response.size() >= 14) {
        BulbState state = m_protocol->parseStateResponse(response);
        if (state.isValid()) {
            setPower(state.isOn());
            setRed(state.red);
            setGreen(state.green);
            setBlue(state.blue);
            setWarmWhite(state.warmWhite);
            setCoolWhite(state.coolWhite);
        }
    }
}

// ─── Protocol Callbacks ───────────────────────────────────

void Bulb::onProtocolConnected()
{
    emit connectionChanged();
    qDebug() << "Connected to bulb:" << m_ip;

    // Query state on connect
    queryState();
}

void Bulb::onProtocolDisconnected()
{
    emit connectionChanged();
    qDebug() << "Disconnected from bulb:" << m_ip;
}

void Bulb::onProtocolError(const QString& message)
{
    qWarning() << "Bulb" << m_label << "(" << m_ip << ") error:" << message;
    emit error(message);
}

// ─── Serialization ────────────────────────────────────────

QJsonObject Bulb::toJson() const
{
    QJsonObject json;
    json["ip"] = m_ip;
    json["mac"] = m_mac;
    json["label"] = m_label;
    json["model"] = m_model;
    json["posX"] = static_cast<double>(m_posX);
    json["posY"] = static_cast<double>(m_posY);
    json["posZ"] = static_cast<double>(m_posZ);
    json["isLeft"] = m_isLeft;
    json["depth"] = m_depth;
    return json;
}

Bulb* Bulb::fromJson(const QJsonObject& json, QObject* parent)
{
    Bulb* bulb = new Bulb(parent);
    bulb->setIp(json["ip"].toString());
    bulb->setMac(json["mac"].toString());
    bulb->setLabel(json["label"].toString("New Bulb"));
    bulb->setModel(json["model"].toString());
    bulb->setPosX(static_cast<float>(json["posX"].toDouble(0)));
    bulb->setPosY(static_cast<float>(json["posY"].toDouble(0)));
    bulb->setPosZ(static_cast<float>(json["posZ"].toDouble(0)));
    if (json.contains("isLeft")) {
        bulb->setIsLeft(json["isLeft"].toBool());
    }
    if (json.contains("depth")) {
        bulb->setDepth(json["depth"].toInt());
    }
    return bulb;
}
