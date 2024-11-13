#include "../PiRacer/PiRacer.hpp"
#include "../Gamepad/ShanwanGamepad.hpp"
#include "../vsomeip.h"
#include <string>
int main()
{
    CommonAPI::Runtime::setProperty("LogContext", "E01C");
    CommonAPI::Runtime::setProperty("LogApplication", "E01C");
    CommonAPI::Runtime::setProperty("LibraryBase", "gamepad_control");
	// Ensure GPIO is initialized
	if (gpioInitialise() < 0)
	{
		std::cerr << "pigpio initialization failed" << std::endl;
		return 1;
	}
	atexit(gpioTerminate);

	// Create instances
	PiRacer racer;
	ShanWanGamepad gamepad;
    vsomeip communication;
    bool r1_state = false, l1_state = false, select_state = false;
    int gear = 0;
    while (true)
    {
        ShanWanGamepadInput input = gamepad.read_data();

        float steering = input.analog_stick_left.x;
        float throttle = input.analog_stick_right.y * 0.5; // limit throtle to 50%

        if(input.button_a == 1){
            communication.changeGear("P");
            gear = 0;
            input.button_a = 0;
        }else if(input.button_b == 1){
            communication.changeGear("R");
            gear = 1;
            input.button_b = 0;
        }else if(input.button_x == 1){
            communication.changeGear("N");
            gear = 2;
            input.button_x = 0;
        }else if(input.button_y == 1){
            communication.changeGear("D");
            gear = 3;
            input.button_y = 0;
        }else if(input.button_r1 == 1){
            if(r1_state == true){
                communication.changeLRsign(0);
                r1_state = false;
            }else{
                communication.changeLRsign(3);
                r1_state = true;
            }
        }else if(input.button_l1 == 1){
            if(l1_state == true){
                communication.changeLRsign(0);
                l1_state = false;
            }else{
                communication.changeLRsign(2);
                l1_state = true;
            }
        }else if(input.button_select == 1){
            if(select_state == true){
                communication.changeLRsign(0);
                select_state = false;
            }else{
                communication.changeLRsign(1);
                select_state = true;
            }
        }else{
            std::cout<<"invalid button"<<std::endl;
        }


        std::cout << "Throttle: " << throttle
                << ", Steering: " << steering
                << ", button_a: " << input.button_a 
                << ", button_b: " << input.button_b 
                << ", button_x: " << input.button_x 
                << ", button_y: " << input.button_y 
                << ", button_l1: " << input.button_l1 
                << ", button_r1: " << input.button_r1
                << std::endl;
        input.button_r1 = 0;
        input.button_l1 = 0;
        input.button_select = 0;
        if (throttle < 0.0){
            throttle = 0.0;
        }
        if (communication.gearValue() == "P" || communication.gearValue() == "N"){
            throttle = 0.0;
        }else if (communication.gearValue() == "R" ){
            throttle *= -1;
        }else{
        }
        
        racer.setSteeringPercent(steering);
        racer.setThrottlePercent(throttle);
    }

	return 0;
}
