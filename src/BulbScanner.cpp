#include "BulbScanner.h"
#include <QNetworkDatagram>
#include <QHostAddress>
#include <QDebug>

const QByteArray BulbScanner::DISCOVER_MESSAGE = QByteArrayLiteral("HF-A11ASSISTHREAD");
const QByteArray BulbScanner::VERSION_MESSAGE = QByteArrayLiteral("AT+LVER\r");

BulbScanner::BulbScanner(QObject* parent)
    : QObject(parent)
    , m_socket(new QUdpSocket(this))
    , m_broadcastTimer(new QTimer(this))
    , m_timeoutTimer(new QTimer(this))
{
    connect(m_socket, &QUdpSocket::readyRead, this, &BulbScanner::onReadyRead);
    connect(m_broadcastTimer, &QTimer::timeout, this, &BulbScanner::onBroadcastTick);
    connect(m_timeoutTimer, &QTimer::timeout, this, &BulbScanner::onScanTimeout);

    m_broadcastTimer->setInterval(BROADCAST_INTERVAL_MS);
    m_timeoutTimer->setSingleShot(true);
    m_timeoutTimer->setInterval(SCAN_TIMEOUT_MS);
}

BulbScanner::~BulbScanner()
{
    stopScan();
}

void BulbScanner::startScan()
{
    if (m_scanning) return;

    m_discovered.clear();
    m_scanning = true;

    // Bind to any available port for receiving responses
    if (!m_socket->bind(QHostAddress::Any, DISCOVERY_PORT,
                        QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
        emit scanError(QString("Failed to bind UDP socket: %1").arg(m_socket->errorString()));
        m_scanning = false;
        return;
    }

    // Send first broadcast immediately, then repeat
    sendBroadcast();
    m_broadcastTimer->start();
    m_timeoutTimer->start();
}

void BulbScanner::stopScan()
{
    m_broadcastTimer->stop();
    m_timeoutTimer->stop();

    if (m_socket->state() != QAbstractSocket::UnconnectedState) {
        m_socket->close();
    }

    if (m_scanning) {
        m_scanning = false;
        emit scanFinished();
    }
}

void BulbScanner::sendBroadcast()
{
    QHostAddress broadcast = QHostAddress::Broadcast;

    m_socket->writeDatagram(DISCOVER_MESSAGE, broadcast, DISCOVERY_PORT);
    m_socket->writeDatagram(VERSION_MESSAGE, broadcast, DISCOVERY_PORT);
}

void BulbScanner::onBroadcastTick()
{
    sendBroadcast();
}

void BulbScanner::onScanTimeout()
{
    stopScan();
}

void BulbScanner::onReadyRead()
{
    while (m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        QByteArray data = datagram.data();
        QHostAddress sender = datagram.senderAddress();

        // Skip our own broadcast messages
        if (data == DISCOVER_MESSAGE || data == VERSION_MESSAGE) {
            continue;
        }

        QString decoded = QString::fromLatin1(data);

        if (decoded.startsWith("+ok=")) {
            processVersionResponse(data, sender);
        } else if (decoded.contains(",")) {
            processDiscoveryResponse(data, sender);
        }
    }
}

void BulbScanner::processDiscoveryResponse(const QByteArray& data, const QHostAddress& sender)
{
    // Response format: "IP,MAC,MODEL"
    // e.g. "192.168.1.100,B4E842E10588,AK001-ZJ2145"
    QString decoded = QString::fromLatin1(data);
    QStringList parts = decoded.split(",");

    if (parts.size() < 3) return;

    QString ip = parts[0].trimmed();
    QString mac = parts[1].trimmed();
    QString model = parts[2].trimmed();

    // Check if already discovered
    for (const auto& bulb : m_discovered) {
        if (bulb.mac == mac) return;
    }

    DiscoveredBulb bulb;
    bulb.ip = ip;
    bulb.mac = mac;
    bulb.model = model;

    m_discovered.append(bulb);
    emit bulbFound(bulb);

    qDebug() << "Discovered bulb:" << ip << mac << model;
}

void BulbScanner::processVersionResponse(const QByteArray& data, const QHostAddress& sender)
{
    // Response format: "+ok=07_06_20210106_ZG-BL\r"
    QString decoded = QString::fromLatin1(data);
    QString versionData = decoded.mid(4).trimmed();
    QStringList parts = versionData.split("_");

    if (parts.size() < 2) return;

    QString senderIp = sender.toString();
    // Remove IPv6 prefix if present
    if (senderIp.startsWith("::ffff:")) {
        senderIp = senderIp.mid(7);
    }

    // Find matching discovered bulb and update version info
    for (auto& bulb : m_discovered) {
        if (bulb.ip == senderIp) {
            bool ok1 = false, ok2 = false;
            bulb.modelNum = parts[0].toInt(&ok1, 16);
            bulb.versionNum = parts[1].toInt(&ok2, 16);
            break;
        }
    }
}
