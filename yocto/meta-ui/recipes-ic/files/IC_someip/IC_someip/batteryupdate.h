#ifndef BATTERYUPDATE_H
#define BATTERYUPDATE_H

#include <QObject>
#include <memory>
#include "battery.h"  // Battery 클래스 포함

class BatteryUpdate : public QObject {
    Q_OBJECT
public:
    explicit BatteryUpdate(std::shared_ptr<Battery> battery, QObject *parent = nullptr);

public slots:
    void updateBatteryValue(int newValue);  // 배터리 값을 업데이트하는 슬롯

private:
    std::shared_ptr<Battery> m_battery;  // Battery 객체의 스마트 포인터
};

#endif // BATTERYUPDATE_H
