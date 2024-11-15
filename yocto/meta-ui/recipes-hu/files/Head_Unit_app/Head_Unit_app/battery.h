#ifndef BATTERY_H
#define BATTERY_H
#include <QObject>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/ICProxy.hpp>
#include <QDebug>
using namespace v0::commonapi;
class Battery : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int batteryValue READ batteryValue NOTIFY batteryValueChanged)
public:
    explicit Battery(QObject *parent = nullptr);
    int batteryValue() const { return qt_battery;}
    std::shared_ptr < CommonAPI::Runtime > runtime;
    std::shared_ptr<ICProxy<>> myProxy;
public slots:
    void getBattery();
signals:
    void batteryValueChanged();
private:
    int qt_battery;
};

#endif // BATTERY_H
