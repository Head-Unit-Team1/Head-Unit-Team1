#ifndef GET_BATTERY_H
#define GET_BATTERY_H

#include <cstdint>
#include <QDebug>

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/i2c-dev.h>
#include <cmath>

#define I2C_BUS "/dev/i2c-1"
#define INA219_ADDRESS 0x41
#define REG_BUS_VOLTAGE 0x02
#define REG_CURRENT 0x04
#define REG_POWER 0x03

#define MAX_VOLTAGE 13.5
#define MIN_VOLTAGE 5.0

int readRegister(int fd, uint8_t reg);
double readVoltage(int fd);
double readCurrent(int fd);
double readPower(int fd);
int calculateBatteryPercentage(double voltage);

#endif // GET_BATTERY_H
