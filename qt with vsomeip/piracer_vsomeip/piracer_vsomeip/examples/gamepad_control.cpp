#include "../PiRacer/PiRacer.hpp"
#include "../Gamepad/ShanwanGamepad.hpp"
#include "../vsomeip.h"
#include <string>
int main()
{
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
    while (true)
    {
        ShanWanGamepadInput input = gamepad.read_data();

        float steering = input.analog_stick_left.x;
        float throttle = input.analog_stick_right.y * 0.5; // limit throtle to 50%
        std::string = gear = "P";
        if(input.button_a == 243){
            communication.changeGear("P");
            input.button_a = -1;
        }else if(input.button_b == 243){
            communication.changeGear("R");
            input.button_b = -1;
        }else if(input.button_x == 243){
            communication.changeGear("N");
            input.button_x = -1;
        }else if(input.button_y == 243){
            communication.changeGear("D");
            input.button_y = -1;
        }else if(input.button_r1 == 243){
            if(r1_state == true){
                communication.changeLRsign(0);
                r1_state = false;
            }else{
                communication.changeLRsign(3);
                r1_state = true;
            }
        }else if(input.button_l1 == 243){
            if(l1_state == true){
                communication.changeLRsign(0);
                l1_state = false;
            }else{
                communication.changeLRsign(2);
                l1_state = true;
            }
        }else if(input.button_select == 243){
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
        input.button_r1 = -1;
        input.button_l1 = -1;
        input.button_select = -1;

        std::cout << "Throttle: " << throttle
                << ", Steering: " << steering
                << std::endl;

        racer.setSteeringPercent(steering);
        racer.setThrottlePercent(throttle);
    }

	return 0;
}
