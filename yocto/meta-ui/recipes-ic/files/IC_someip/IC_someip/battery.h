#ifndef BATTERY_H
#define BATTERY_H
#include <QObject>
#include <QDebug>
class ICStubImpl;

class Battery : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int batteryValue READ batteryValue NOTIFY batteryValueChanged)
public:
    explicit Battery(QObject *parent = nullptr);
    int batteryValue() const{return qt_battery;}
    void setBatteryValue(int value);
    void setICStubImpl(ICStubImpl* icStubImpl);
    Q_INVOKABLE void q_setBatteryValue(int value);
signals:
    void batteryValueChanged();
private:
    int qt_battery = 77;
    ICStubImpl* icStubImpl_;
};

#endif // BATTERY_H
