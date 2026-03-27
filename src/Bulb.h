#pragma once

#include <QObject>
#include <QString>
#include <QColor>
#include <QVector3D>
#include <QTimer>
#include "ZenggeProtocol.h"

class Bulb : public QObject
{
    Q_OBJECT

    // Identity
    Q_PROPERTY(QString ip READ ip WRITE setIp NOTIFY ipChanged)
    Q_PROPERTY(QString mac READ mac WRITE setMac NOTIFY macChanged)
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QString model READ model WRITE setModel NOTIFY modelChanged)

    // State
    Q_PROPERTY(bool power READ power WRITE setPower NOTIFY powerChanged)
    Q_PROPERTY(int red READ red WRITE setRed NOTIFY colorChanged)
    Q_PROPERTY(int green READ green WRITE setGreen NOTIFY colorChanged)
    Q_PROPERTY(int blue READ blue WRITE setBlue NOTIFY colorChanged)
    Q_PROPERTY(int warmWhite READ warmWhite WRITE setWarmWhite NOTIFY whiteChanged)
    Q_PROPERTY(int coolWhite READ coolWhite WRITE setCoolWhite NOTIFY whiteChanged)
    Q_PROPERTY(QColor displayColor READ displayColor NOTIFY colorChanged)

    // 3D Position
    Q_PROPERTY(float posX READ posX WRITE setPosX NOTIFY positionChanged)
    Q_PROPERTY(float posY READ posY WRITE setPosY NOTIFY positionChanged)
    Q_PROPERTY(float posZ READ posZ WRITE setPosZ NOTIFY positionChanged)

    // Connection
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectionChanged)
    Q_PROPERTY(bool selected READ isSelected WRITE setSelected NOTIFY selectedChanged)

public:
    explicit Bulb(QObject* parent = nullptr);
    explicit Bulb(const QString& ip, const QString& mac, const QString& model,
                  QObject* parent = nullptr);
    ~Bulb();

    // Getters
    QString ip() const { return m_ip; }
    QString mac() const { return m_mac; }
    QString label() const { return m_label; }
    QString model() const { return m_model; }
    bool power() const { return m_power; }
    int red() const { return m_red; }
    int green() const { return m_green; }
    int blue() const { return m_blue; }
    int warmWhite() const { return m_warmWhite; }
    int coolWhite() const { return m_coolWhite; }
    float posX() const { return m_posX; }
    float posY() const { return m_posY; }
    float posZ() const { return m_posZ; }
    bool isConnected() const;
    bool isSelected() const { return m_selected; }
    QColor displayColor() const;

    // Setters
    void setIp(const QString& ip);
    void setMac(const QString& mac);
    void setLabel(const QString& label);
    void setModel(const QString& model);
    void setPower(bool on);
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void setWarmWhite(int ww);
    void setCoolWhite(int cw);
    void setPosX(float x);
    void setPosY(float y);
    void setPosZ(float z);
    void setSelected(bool selected);

    // Commands — called from QML or BulbManager
    Q_INVOKABLE void turnOn();
    Q_INVOKABLE void turnOff();
    Q_INVOKABLE void setColor(int r, int g, int b);
    Q_INVOKABLE void setWhite(int warm, int cool);
    Q_INVOKABLE void setColorAndWhite(int r, int g, int b, int warm, int cool);
    Q_INVOKABLE void queryState();
    Q_INVOKABLE void connectToBulb();
    Q_INVOKABLE void disconnectFromBulb();

    // Serialization
    QJsonObject toJson() const;
    static Bulb* fromJson(const QJsonObject& json, QObject* parent = nullptr);

signals:
    void ipChanged();
    void macChanged();
    void labelChanged();
    void modelChanged();
    void powerChanged();
    void colorChanged();
    void whiteChanged();
    void positionChanged();
    void connectionChanged();
    void selectedChanged();
    void error(const QString& message);

private slots:
    void onProtocolConnected();
    void onProtocolDisconnected();
    void onProtocolError(const QString& message);

private:
    void sendColorUpdate();

    ZenggeProtocol* m_protocol = nullptr;

    // Identity
    QString m_ip;
    QString m_mac;
    QString m_label = "New Bulb";
    QString m_model;

    // State
    bool m_power = false;
    int m_red = 255;
    int m_green = 255;
    int m_blue = 255;
    int m_warmWhite = 0;
    int m_coolWhite = 0;

    // 3D position
    float m_posX = 0.0f;
    float m_posY = 0.0f;
    float m_posZ = 0.0f;

    bool m_selected = false;
};
