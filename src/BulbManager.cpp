#include "BulbManager.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QGuiApplication>

BulbManager::BulbManager(QObject* parent)
    : QAbstractListModel(parent)
    , m_scanner(new BulbScanner(this))
{
    connect(m_scanner, &BulbScanner::bulbFound, this, &BulbManager::onBulbFound);
    connect(m_scanner, &BulbScanner::scanFinished, this, &BulbManager::onScanFinished);

    loadConfig();
}

BulbManager::~BulbManager()
{
    saveConfig();
    disconnectAll();
}

// ─── QAbstractListModel ───────────────────────────────────

int BulbManager::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_bulbs.size();
}

QVariant BulbManager::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= m_bulbs.size())
        return QVariant();

    const Bulb* bulb = m_bulbs.at(index.row());
    switch (role) {
        case IpRole: return bulb->ip();
        case MacRole: return bulb->mac();
        case LabelRole: return bulb->label();
        case ModelRole: return bulb->model();
        case PowerRole: return bulb->power();
        case RedRole: return bulb->red();
        case GreenRole: return bulb->green();
        case BlueRole: return bulb->blue();
        case WarmWhiteRole: return bulb->warmWhite();
        case CoolWhiteRole: return bulb->coolWhite();
        case PosXRole: return bulb->posX();
        case PosYRole: return bulb->posY();
        case PosZRole: return bulb->posZ();
        case ConnectedRole: return bulb->isConnected();
        case SelectedRole: return bulb->isSelected();
        case DisplayColorRole: return bulb->displayColor();
        case BulbObjectRole: return QVariant::fromValue(const_cast<Bulb*>(bulb));
        default: return QVariant();
    }
}

bool BulbManager::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid() || index.row() >= m_bulbs.size())
        return false;

    Bulb* bulb = m_bulbs.at(index.row());
    switch (role) {
        case LabelRole: bulb->setLabel(value.toString()); break;
        case PosXRole: bulb->setPosX(value.toFloat()); break;
        case PosYRole: bulb->setPosY(value.toFloat()); break;
        case PosZRole: bulb->setPosZ(value.toFloat()); break;
        case SelectedRole: bulb->setSelected(value.toBool()); break;
        default: return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags BulbManager::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable | QAbstractListModel::flags(index);
}

QHash<int, QByteArray> BulbManager::roleNames() const
{
    return {
        {IpRole, "ip"},
        {MacRole, "mac"},
        {LabelRole, "label"},
        {ModelRole, "model"},
        {PowerRole, "power"},
        {RedRole, "red"},
        {GreenRole, "green"},
        {BlueRole, "blue"},
        {WarmWhiteRole, "warmWhite"},
        {CoolWhiteRole, "coolWhite"},
        {PosXRole, "posX"},
        {PosYRole, "posY"},
        {PosZRole, "posZ"},
        {ConnectedRole, "connected"},
        {SelectedRole, "selected"},
        {DisplayColorRole, "displayColor"},
        {BulbObjectRole, "bulbObject"},
    };
}

// ─── Scanning ─────────────────────────────────────────────

bool BulbManager::isScanning() const
{
    return m_scanner->isScanning();
}

void BulbManager::discover()
{
    m_scanner->startScan();
    emit scanningChanged();
    emit discoveredCountChanged();
}

void BulbManager::stopScan()
{
    m_scanner->stopScan();
    emit scanningChanged();
}

void BulbManager::onBulbFound(const DiscoveredBulb& bulb)
{
    // Check if already registered
    for (const auto* existing : m_bulbs) {
        if (existing->mac() == bulb.mac || existing->ip() == bulb.ip) {
            return;
        }
    }
    emit discoveredCountChanged();
    emit bulbDiscovered(bulb.ip, bulb.mac, bulb.model);
}

void BulbManager::onScanFinished()
{
    emit scanningChanged();
    emit discoveredCountChanged();
    emit scanFinished();
}

int BulbManager::discoveredCount() const
{
    return m_scanner->discoveredBulbs().size();
}

QString BulbManager::discoveredIp(int index) const
{
    auto list = m_scanner->discoveredBulbs();
    if (index >= 0 && index < list.size()) return list[index].ip;
    return QString();
}

QString BulbManager::discoveredMac(int index) const
{
    auto list = m_scanner->discoveredBulbs();
    if (index >= 0 && index < list.size()) return list[index].mac;
    return QString();
}

QString BulbManager::discoveredModel(int index) const
{
    auto list = m_scanner->discoveredBulbs();
    if (index >= 0 && index < list.size()) return list[index].model;
    return QString();
}

// ─── Bulb Management ──────────────────────────────────────

void BulbManager::addBulb(const QString& ip, const QString& mac, const QString& model)
{
    // Don't add duplicates
    for (const auto* existing : m_bulbs) {
        if (existing->mac() == mac || existing->ip() == ip) {
            return;
        }
    }

    int row = m_bulbs.size();
    beginInsertRows(QModelIndex(), row, row);

    Bulb* bulb = new Bulb(ip, mac, model, this);
    // Offset new bulbs so they don't stack
    bulb->setPosX(row * 2.5f);
    bulb->setPosY(0.0f);
    bulb->setPosZ(0.0f);

    // Connect signals for model updates
    connect(bulb, &Bulb::colorChanged, this, &BulbManager::onBulbDataChanged);
    connect(bulb, &Bulb::powerChanged, this, &BulbManager::onBulbDataChanged);
    connect(bulb, &Bulb::positionChanged, this, &BulbManager::onBulbDataChanged);
    connect(bulb, &Bulb::labelChanged, this, &BulbManager::onBulbDataChanged);
    connect(bulb, &Bulb::connectionChanged, this, &BulbManager::onBulbDataChanged);
    connect(bulb, &Bulb::selectedChanged, this, &BulbManager::onBulbDataChanged);

    m_bulbs.append(bulb);
    endInsertRows();

    emit countChanged();
    saveConfig();
}

void BulbManager::addBulbManual(const QString& ip)
{
    addBulb(ip, QString("manual_%1").arg(ip), "Manual");
}

void BulbManager::removeBulb(int index)
{
    if (index < 0 || index >= m_bulbs.size()) return;

    beginRemoveRows(QModelIndex(), index, index);
    Bulb* bulb = m_bulbs.takeAt(index);

    if (m_selectedBulb == bulb) {
        m_selectedBulb = nullptr;
        emit selectedBulbChanged();
    }

    bulb->disconnectFromBulb();
    bulb->deleteLater();
    endRemoveRows();

    emit countChanged();
    saveConfig();
}

Bulb* BulbManager::bulbAt(int index) const
{
    if (index >= 0 && index < m_bulbs.size())
        return m_bulbs.at(index);
    return nullptr;
}

void BulbManager::selectBulb(int index)
{
    // Single-click: deselect all others, select this one
    for (auto* bulb : m_bulbs) {
        bulb->setSelected(false);
    }

    if (index >= 0 && index < m_bulbs.size()) {
        m_selectedBulb = m_bulbs.at(index);
        m_selectedBulb->setSelected(true);
    } else {
        m_selectedBulb = nullptr;
    }
    emit selectedBulbChanged();
}

void BulbManager::toggleBulbSelection(int index)
{
    if (index < 0 || index >= m_bulbs.size()) return;

    Bulb* bulb = m_bulbs.at(index);
    bulb->setSelected(!bulb->isSelected());

    // Update selectedBulb to reflect latest action
    if (bulb->isSelected()) {
        m_selectedBulb = bulb;
    } else if (m_selectedBulb == bulb) {
        // Find another selected bulb for the inspector
        m_selectedBulb = nullptr;
        for (auto* b : m_bulbs) {
            if (b->isSelected()) { m_selectedBulb = b; break; }
        }
    }
    emit selectedBulbChanged();
}

void BulbManager::handleBulbClick(int index)
{
    // Check Ctrl modifier from the OS — works for both QML MouseArea and Qt3D ObjectPicker
    if (QGuiApplication::keyboardModifiers() & Qt::ControlModifier) {
        toggleBulbSelection(index);
    } else {
        selectBulb(index);
    }
}

void BulbManager::deselectAll()
{
    for (auto* bulb : m_bulbs) {
        bulb->setSelected(false);
    }
    m_selectedBulb = nullptr;
    emit selectedBulbChanged();
}

void BulbManager::connectAll()
{
    for (auto* bulb : m_bulbs) {
        bulb->connectToBulb();
    }
}

void BulbManager::disconnectAll()
{
    for (auto* bulb : m_bulbs) {
        bulb->disconnectFromBulb();
    }
}

// ─── Bulk Selected Operations ─────────────────────────────

void BulbManager::setSelectedColor(int r, int g, int b)
{
    for (auto* bulb : m_bulbs) {
        if (bulb->isSelected()) {
            bulb->setColor(r, g, b);
        }
    }
}

void BulbManager::setSelectedWhite(int warm, int cool)
{
    for (auto* bulb : m_bulbs) {
        if (bulb->isSelected()) {
            bulb->setWhite(warm, cool);
        }
    }
}

void BulbManager::setSelectedPower(bool on)
{
    for (auto* bulb : m_bulbs) {
        if (bulb->isSelected()) {
            if (on) bulb->turnOn();
            else bulb->turnOff();
        }
    }
}

// ─── Bulb List Accessors ──────────────────────────────────

QVariantList BulbManager::allBulbsList() const
{
    QVariantList list;
    for (auto* bulb : m_bulbs)
        list.append(QVariant::fromValue(bulb));
    return list;
}

QVariantList BulbManager::selectedBulbsList() const
{
    QVariantList list;
    for (auto* bulb : m_bulbs) {
        if (bulb->isSelected())
            list.append(QVariant::fromValue(bulb));
    }
    return list;
}

// ─── Model Update Notifications ───────────────────────────

void BulbManager::onBulbDataChanged()
{
    Bulb* bulb = qobject_cast<Bulb*>(sender());
    if (!bulb) return;

    int row = m_bulbs.indexOf(bulb);
    if (row >= 0) {
        QModelIndex idx = index(row);
        emit dataChanged(idx, idx);
    }
}

// ─── Persistence ──────────────────────────────────────────

QString BulbManager::configFilePath() const
{
    QString appData = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appData);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    return dir.filePath("config.json");
}

void BulbManager::saveConfig()
{
    QJsonArray bulbArray;
    for (const auto* bulb : m_bulbs) {
        bulbArray.append(bulb->toJson());
    }

    QJsonObject root;
    root["bulbs"] = bulbArray;
    root["version"] = 1;

    QFile file(configFilePath());
    if (!file.open(QIODevice::WriteOnly)) {
        emit configError(QString("Failed to save config: %1").arg(file.errorString()));
        return;
    }

    file.write(QJsonDocument(root).toJson());
    file.close();

    qDebug() << "Config saved to:" << configFilePath();
}

void BulbManager::loadConfig()
{
    QString path = configFilePath();
    QFile file(path);

    if (!file.exists()) {
        qDebug() << "No config file found at:" << path;
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        emit configError(QString("Failed to load config: %1").arg(file.errorString()));
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isObject()) {
        emit configError("Invalid config file format");
        return;
    }

    QJsonObject root = doc.object();
    QJsonArray bulbArray = root["bulbs"].toArray();

    beginResetModel();
    qDeleteAll(m_bulbs);
    m_bulbs.clear();

    for (const auto& val : bulbArray) {
        Bulb* bulb = Bulb::fromJson(val.toObject(), this);

        connect(bulb, &Bulb::colorChanged, this, &BulbManager::onBulbDataChanged);
        connect(bulb, &Bulb::powerChanged, this, &BulbManager::onBulbDataChanged);
        connect(bulb, &Bulb::positionChanged, this, &BulbManager::onBulbDataChanged);
        connect(bulb, &Bulb::labelChanged, this, &BulbManager::onBulbDataChanged);
        connect(bulb, &Bulb::connectionChanged, this, &BulbManager::onBulbDataChanged);
        connect(bulb, &Bulb::selectedChanged, this, &BulbManager::onBulbDataChanged);

        m_bulbs.append(bulb);
    }

    endResetModel();
    emit countChanged();

    qDebug() << "Loaded" << m_bulbs.size() << "bulbs from config";
}
