

#ifndef IC_INTERSTUBIMPL_H
#define IC_INTERSTUBIMPL_H
#include <QObject>
#include <string>
#include "gear.h"
#include "lrsign.h"
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/IC_interStubDefault.hpp>
class IC_interStubImpl: public QObject, public v0::commonapi::IC_interStubDefault
{
    Q_OBJECT
public:
    explicit IC_interStubImpl(Gear* gear, LRSign* lrsign, QObject *parent = nullptr);
    virtual ~IC_interStubImpl();
    virtual void setGear_inter(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _gear, setGear_interReply_t _reply);
    virtual void setLrsign_inter(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _lrsign, setLrsign_interReply_t _relay);
    virtual void notifyGearStatusChanged(std::string gearValue);

signals:
    void signalGear_inter(std::string);
    void signalLrsign_inter(int32_t);
private:
    Gear * gear_;
    LRSign* lrsign_;
};

#endif // IC_INTERSTUBIMPL_H


//*/
