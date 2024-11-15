#ifndef LRSIGN_H
#define LRSIGN_H
#include <QObject>
#include <QString>
#include <iostream>
#include <unistd.h>
#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/IC_interProxy.hpp>
using namespace v0::commonapi;

class LRsign : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int32_t lrValue READ lrValue NOTIFY lrValueChanged)
public:
    explicit LRsign(QObject *parent = nullptr);
    int32_t lrValue() const {return qt_lrsign;}
    std::shared_ptr < CommonAPI::Runtime > runtime;
    std::shared_ptr<IC_interProxy<>> myProxy;
public slots:
    Q_INVOKABLE void changeLRsign(int32_t changedSign);
signals:
    void lrValueChanged();
private:
    int32_t qt_lrsign;

};

#endif // LRSIGN_H

