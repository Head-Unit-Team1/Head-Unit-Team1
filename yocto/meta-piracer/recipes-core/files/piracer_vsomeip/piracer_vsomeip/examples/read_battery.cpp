#include "../PiRacer/PiRacer.hpp"
#include <iostream>

void print_energy_report(PiRacer& racer)
{
	float voltage = racer.getBatteryVoltage();
	float current = racer.getBatteryCurrent();
	float power = racer.getPowerConsumption();
	std::cout << "Battery "
			<< "Voltage: " << voltage
			<< ", Current: " << current
			<< ", Power: " << power
			<< std::endl;
}

int main()
{
	// Ensure GPIO is initialized
	if (gpioInitialise() < 0)
	{
		std::cerr << "pigpio initialization failed" << std::endl;
		return 1;
	}

	// Create PiRacer Instance
	PiRacer racer;

	std::cout << "Powertrain off" << std::endl;
	print_energy_report(racer);
	sleep(1);

	std::cout << "Powertrain at 30%" << std::endl;
	racer.setThrottlePercent(0.3);
	sleep(3);
	print_energy_report(racer);

	std::cout << "Powertrain at 100%" << std::endl;
	racer.setThrottlePercent(1.0);
	sleep(3);
	print_energy_report(racer);

	std::cout << "Powertrain off" << std::endl;
	racer.setThrottlePercent(0.0);
	sleep(3);
	print_energy_report(racer);

	gpioTerminate();
	return 0;
}