#include "ShanwanGamepad.hpp"

ShanWanGamepad::ShanWanGamepad():
	Joystick("/dev/input/js0", false)
{
	if (!Joystick::init())
		std::cerr << "Gamepad not found" << std::endl;	
};

ShanWanGamepad::ShanWanGamepad(const std::string& dev_fn = "/dev/input/js0"):
	Joystick("/dev/input/js0", false)
{
	if (!Joystick::init())
		std::cerr << "Gamepad not found" << std::endl;	
};

ShanWanGamepad::ShanWanGamepad(const std::string& dev_fn = "/dev/input/js0", bool non_block = false):
	Joystick(dev_fn, non_block)
{
	if (!Joystick::init())
		std::cerr << "Gamepad not found" << std::endl;
}

ShanWanGamepadInput ShanWanGamepad::read_data()
{
	auto [button_name, button_number, button_state, axis_name, axis_number, axis_val] = Joystick::poll();
	// Joysticks
	if (axis_number == 0) {
		gamepad_input.analog_stick_left.x = -axis_val;
	} else if (axis_number == 1) {
		gamepad_input.analog_stick_left.y = axis_val;
	} else if (axis_number == 2) {
		gamepad_input.analog_stick_right.x = axis_val;
	} else if (axis_number == 3) {
		gamepad_input.analog_stick_right.y = -axis_val;
	} 
	
	else if (axis_number == 4) {
		gamepad_input.button_r2 = (axis_val == 1);
	} else if (axis_number == 5) {
		gamepad_input.button_l2 = (axis_val == 1);
	} else if (axis_number == 6) {
		gamepad_input.button_left = (axis_val == -1);
		gamepad_input.button_right = (axis_val == 1);
	} else if (axis_number == 7) {
		gamepad_input.button_up = (axis_val == -1);
		gamepad_input.button_down = (axis_val == 1);
	}
	// Buttons
	else if (button_number == 0) {
        if (gamepad_input.button_a == 1){
            gamepad_input.button_a = 0;
        }else{
            gamepad_input.button_a = 1;
        }
	} else if (button_number == 1) {
		if (gamepad_input.button_b == 1){
            gamepad_input.button_b = 0;
        }else{
            gamepad_input.button_b = 1;
        }
	} else if (button_number == 2) {
		// Do nothing (pass)
	} else if (button_number == 3) {
		if (gamepad_input.button_x == 1){
            gamepad_input.button_x = 0;
        }else{
            gamepad_input.button_x = 1;
        }
	} else if (button_number == 4) {
		if (gamepad_input.button_y == 1){
            gamepad_input.button_y = 0;
        }else{
            gamepad_input.button_y = 1;
        }
	} else if (button_number == 5) {
		// Do nothing (pass)
	} else if (button_number == 6) {
		if (gamepad_input.button_l1 == 1){
            gamepad_input.button_l1 = 0;
        }else{
            gamepad_input.button_l1 = 1;
        }
	} else if (button_number == 7) {
		if (gamepad_input.button_r1 == 1){
            gamepad_input.button_r1 = 0;
        }else{
            gamepad_input.button_r1 = 1;
        }
	} /*else if (button_number == 8) {
		gamepad_input.button_l2 = button_state;
	} else if (button_number == 9) {
		gamepad_input.button_r2 = button_state;
	}*/
	else if (button_number == 10) {
		if (gamepad_input.button_select == 1){
            gamepad_input.button_select = 0;
        }else{
            gamepad_input.button_select = 1;
        }
	} else if (button_number == 11) {
		gamepad_input.button_start = button_state;
	} else if (button_number == 12) {
		gamepad_input.button_home = button_state;
	} /*else if (button_number == 13) {
		gamepad_input.analog_stick_left.z = button_state;
	} else if (button_number == 14) {
		gamepad_input.analog_stick_right.z = button_state;
	}*/
	std::cout << "Button: " << button_number << ", State: " << button_state << std::endl;
	std::cout << "Axis: " << axis_number << ", Value: " << axis_val << std::endl;

	return gamepad_input;
}
