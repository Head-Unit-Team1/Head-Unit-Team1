#ifndef VEHICLECOMPONENTS_H
#define VEHICLECOMPONENTS_H
#include "battery.h"
#include "gear.h"
#include <memory>
struct VehicleComponents {
    std::shared_ptr<Gear> gear;
    std::shared_ptr<Battery> battery;
};
#endif // VEHICLECOMPONENTS_H
