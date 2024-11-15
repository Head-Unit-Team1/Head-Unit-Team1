#ifndef GEAR_H
#define GEAR_H
#include <QObject>
#include <QString>
#include <iostream>
#include <unistd.h>
#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/IC_interProxy.hpp>
using namespace v0::commonapi;
class Gear:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString gearValue READ gearValue NOTIFY gearValueChanged)
public:
    explicit Gear(QObject *parent = nullptr);
    QString gearValue() const { return qt_gear;}
    std::shared_ptr < CommonAPI::Runtime > runtime;
    std::shared_ptr<IC_interProxy<>> myProxy;
public slots:
    Q_INVOKABLE void changeGear(QString changedGear);
signals:
    void gearValueChanged();
private:
    QString qt_gear;
};
#endif // GEAR_H
