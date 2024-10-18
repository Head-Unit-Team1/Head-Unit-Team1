#ifndef ICSTUBIMPL_H
#define ICSTUBIMPL_H
#include <QObject>
#include "vehiclecomponents.h"
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/ICStubDefault.hpp>
class ICStubImpl: public QObject, public v0::commonapi::ICStubDefault
{
    Q_OBJECT
public:
    explicit ICStubImpl(VehicleComponents components, QObject *parent = nullptr);
    virtual ~ICStubImpl();
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _gear, setGearReply_t _reply);
    virtual void getBattery(const std::shared_ptr<CommonAPI::ClientId> _client, getBatteryReply_t _reply);
signals:
    void signalGear(std::string);
    //void signalBattery(int32_t);
private:
    VehicleComponents components_;
};

#endif // ICSTUBIMPL_H

