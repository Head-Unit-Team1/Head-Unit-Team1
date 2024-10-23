#include "Adafruit_INA219.hpp"

INA219::INA219(int i2c_bus, int addr):
	i2c_bus(i2c_bus), addr(addr)
{
	handle = i2cOpen(i2c_bus, addr, 0);
	if (handle < 0) 
	{
		std::cerr << "Failed to open I2C bus" << std::endl;
		exit(1);
	}
	setCalibration32V2A();
}

INA219::~INA219()
{
	if (gpioInitialise() >= 0)
		i2cClose(handle);
}

void INA219::setCalibration32V2A()
{
	// Calibration value
	int calValue = 4096;
	// Write calibration value to register
	writeRegister(REG_CALIBRATION, calValue);

	// Config register
	int config = (BUS_VOLTAGE_RANGE_32V << 13) |
				(GAIN_DIV_8_320MV << 11) |
				(ADC_RES_12BIT_1S << 7) |
				(ADC_RES_12BIT_1S << 3) |
				MODE_SANDBVOLT_CONTINUOUS;
	writeRegister(REG_CONFIG, config);
}

float INA219::getBusVoltage()
{
	int rawBusVoltage = readRegister(REG_BUSVOLTAGE);
	return (rawBusVoltage >> 3) * 0.004;
}

float INA219::getShuntVoltage()
{
	int rawShuntVoltage = readRegister(REG_SHUNTVOLTAGE);
	return rawShuntVoltage * 0.00001;
}

float INA219::getCurrent()
{
	int rawCurrent = readRegister(REG_CURRENT);
	return rawCurrent * currentLSB;
}

float INA219::getPower()
{
	int rawPower = readRegister(REG_POWER);
	return rawPower * powerLSB;
}

void INA219::writeRegister(int reg, int value)
{
	i2cWriteWordData(handle, reg, (value >> 8) | ((value & 0xFF) << 8));
}

int INA219::readRegister(int reg)
{
	int result = i2cReadWordData(handle, reg);
	return (result >> 8) | ((result & 0xFF) << 8);
}