#ifndef CONTROLS_GAMEPAD_H
#define CONTROLS_GAMEPAD_H

#include <SFML\Window\Joystick.hpp>

enum XBoxAxes
{
	LeftX,
	LeftY,
	Triggers,
	RightY,
	RightX,
	Unknown,
	DPadX,
	DPadY
};
enum XBoxButtons
{
	A,
	B,
	X,
	Y,
	LeftBumper,
	RightBumper,
	Back,
	Start,
	LeftStick,
	RightStick
};

class Gamepad
{
private:
	int id;
public:
	Gamepad(int id);

	int getId();
	sf::Joystick::Identification getIdentification();

	bool isDown(XBoxButtons button);
	float getAxis(XBoxAxes axis);
};

#endif