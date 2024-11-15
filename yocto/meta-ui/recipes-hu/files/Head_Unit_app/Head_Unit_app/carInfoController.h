#ifndef CARINFOCONTROLLER_H
#define CARINFOCONTROLLER_H

#include <QObject>
#include <QString>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/ICProxy.hpp>
#include <QDebug>
using namespace v0::commonapi;

class CarInfoController : public QObject {
    Q_OBJECT
    Q_PROPERTY(int batteryLevel READ batteryLevel WRITE setBatteryLevel NOTIFY batteryLevelChanged)
    Q_PROPERTY(QString modeColor READ modeColor WRITE setModeColor NOTIFY modeColorChanged)
    Q_PROPERTY(QString blinkDirection READ blinkDirection WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int batteryValue READ batteryValue NOTIFY batteryValueChanged)

public:
    explicit CarInfoController(QObject *parent = nullptr);

    int batteryLevel() const;
    Q_INVOKABLE void setBatteryLevel(int level);

    QString modeColor() const;
    Q_INVOKABLE void setModeColor(const QString& color);

    QString blinkDirection() const;
    Q_INVOKABLE void setDirection(const QString& direction);

    int batteryValue() const;

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<ICProxy<>> myProxy;
    void connectedValue() const;
public slots:
    void getBattery();

signals:
    void batteryLevelChanged();
    void modeColorChanged();
    void directionChanged();
    void batteryValueChanged();


private:
    int m_batteryLevel;
    QString m_modeColor;
    int int_mode=0;
    QString m_direction;
    int qt_battery;
};

#endif // CARINFOCONTROLLER_H
