#include "get_battery.h"

int readRegister(int fd, uint8_t reg) {
    uint8_t buf[2];
    buf[0] = 0;
    buf[1] = 0;
    if (write(fd, &reg, 1) != 1) {
        std::cerr << "Failed to select register: " << static_cast<int>(reg) << std::endl;
        return -1;
    }
   if (read(fd, buf, 2) != 2) {
       qDebug() << "bettery fff";

       std::cerr << "Failed to read data from I2C device." << std::endl;
       return -1;
   }

    return (buf[0] << 8) | buf[1];
}

double readVoltage(int fd) {
    int raw_voltage = readRegister(fd, REG_BUS_VOLTAGE);
    if (raw_voltage == -1) return -1;

    return (raw_voltage >> 3) * 0.004;
}

double readCurrent(int fd) {
    int raw_current = readRegister(fd, REG_CURRENT);
    if (raw_current == -1) return -1;
    return raw_current * 0.001;
}

double readPower(int fd) {
    int raw_power = readRegister(fd, REG_POWER);
    if (raw_power == -1) return -1;
    return raw_power * 0.02;
}

int calculateBatteryPercentage(double voltage) {
    if (voltage >= MAX_VOLTAGE) {
        return 100;
    } else if (voltage <= MIN_VOLTAGE) {
        return 0;
    } else {
        return round(((voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * 100);
    }
}
