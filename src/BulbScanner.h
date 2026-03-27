#pragma once

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QList>
#include "ZenggeProtocol.h"

class BulbScanner : public QObject
{
    Q_OBJECT

public:
    static constexpr uint16_t DISCOVERY_PORT = 48899;
    static constexpr int SCAN_TIMEOUT_MS = 5000;
    static constexpr int BROADCAST_INTERVAL_MS = 1000;

    static const QByteArray DISCOVER_MESSAGE;
    static const QByteArray VERSION_MESSAGE;

    explicit BulbScanner(QObject* parent = nullptr);
    ~BulbScanner();

    Q_INVOKABLE void startScan();
    Q_INVOKABLE void stopScan();
    Q_INVOKABLE bool isScanning() const { return m_scanning; }

    QList<DiscoveredBulb> discoveredBulbs() const { return m_discovered; }

signals:
    void bulbFound(const DiscoveredBulb& bulb);
    void scanFinished();
    void scanError(const QString& message);

private slots:
    void onReadyRead();
    void onBroadcastTick();
    void onScanTimeout();

private:
    void sendBroadcast();
    void processDiscoveryResponse(const QByteArray& data, const QHostAddress& sender);
    void processVersionResponse(const QByteArray& data, const QHostAddress& sender);

    QUdpSocket* m_socket = nullptr;
    QTimer* m_broadcastTimer = nullptr;
    QTimer* m_timeoutTimer = nullptr;
    QList<DiscoveredBulb> m_discovered;
    bool m_scanning = false;
};
