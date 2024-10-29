#ifndef ICSTUBIMPL_H
#define ICSTUBIMPL_H
#include <QObject>
#include "battery.h"
#include "gear.h"
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/ICStubDefault.hpp>
class ICStubImpl: public QObject, public v0::commonapi::ICStubDefault
{
    Q_OBJECT
public:
    explicit ICStubImpl(Gear* gear, Battery* battery, QObject *parent = nullptr);
    virtual ~ICStubImpl();
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _gear, setGearReply_t _reply);
    virtual void getBattery(const std::shared_ptr<CommonAPI::ClientId> _client, getBatteryReply_t _reply);
    virtual void notifyBatteryStatusChanged(int32_t batteryValue);
signals:
    void signalGear(std::string);
    //void signalBattery(int32_t);
private:
    Gear * gear_;
    Battery * battery_;
};

#endif // ICSTUBIMPL_H

