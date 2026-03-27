#pragma once

#include <QAbstractListModel>
#include <QList>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "Bulb.h"
#include "BulbScanner.h"

class BulbManager : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(bool scanning READ isScanning NOTIFY scanningChanged)
    Q_PROPERTY(Bulb* selectedBulb READ selectedBulb NOTIFY selectedBulbChanged)
    Q_PROPERTY(int discoveredCount READ discoveredCount NOTIFY discoveredCountChanged)

public:
    enum BulbRoles {
        IpRole = Qt::UserRole + 1,
        MacRole,
        LabelRole,
        ModelRole,
        PowerRole,
        RedRole,
        GreenRole,
        BlueRole,
        WarmWhiteRole,
        CoolWhiteRole,
        PosXRole,
        PosYRole,
        PosZRole,
        ConnectedRole,
        SelectedRole,
        DisplayColorRole,
        BulbObjectRole  // Returns the Bulb* itself
    };

    explicit BulbManager(QObject* parent = nullptr);
    ~BulbManager();

    // QAbstractListModel interface
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QHash<int, QByteArray> roleNames() const override;

    // Properties
    int count() const { return m_bulbs.size(); }
    bool isScanning() const;
    Bulb* selectedBulb() const { return m_selectedBulb; }

    // Management
    Q_INVOKABLE void discover();
    Q_INVOKABLE void stopScan();
    Q_INVOKABLE void addBulb(const QString& ip, const QString& mac, const QString& model);
    Q_INVOKABLE void addBulbManual(const QString& ip);
    Q_INVOKABLE void removeBulb(int index);
    Q_INVOKABLE Bulb* bulbAt(int index) const;
    Q_INVOKABLE void selectBulb(int index);
    Q_INVOKABLE void deselectAll();
    Q_INVOKABLE void connectAll();
    Q_INVOKABLE void disconnectAll();

    // Bulk operations on selected
    Q_INVOKABLE void setSelectedColor(int r, int g, int b);
    Q_INVOKABLE void setSelectedWhite(int warm, int cool);
    Q_INVOKABLE void setSelectedPower(bool on);

    // Persistence
    Q_INVOKABLE void saveConfig();
    Q_INVOKABLE void loadConfig();

    // Discovery results
    int discoveredCount() const;
    Q_INVOKABLE QString discoveredIp(int index) const;
    Q_INVOKABLE QString discoveredMac(int index) const;
    Q_INVOKABLE QString discoveredModel(int index) const;

signals:
    void countChanged();
    void scanningChanged();
    void selectedBulbChanged();
    void discoveredCountChanged();
    void bulbDiscovered(const QString& ip, const QString& mac, const QString& model);
    void scanFinished();
    void configError(const QString& message);

private slots:
    void onBulbFound(const DiscoveredBulb& bulb);
    void onScanFinished();
    void onBulbDataChanged();

private:
    QString configFilePath() const;

    QList<Bulb*> m_bulbs;
    BulbScanner* m_scanner = nullptr;
    Bulb* m_selectedBulb = nullptr;
};
