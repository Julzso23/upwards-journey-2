#include "Gamepad.h"

Gamepad::Gamepad(int id)
{
	this->id = id;
}

int Gamepad::getId()
{
	return id;
}

sf::Joystick::Identification Gamepad::getIdentification()
{
	return sf::Joystick::getIdentification(id);
}

bool Gamepad::isDown(XBoxButtons button)
{
	return sf::Joystick::isButtonPressed(id, button);
}

float Gamepad::getAxis(XBoxAxes axis)
{
	if (sf::Joystick::hasAxis(id, sf::Joystick::Axis(axis)))
		return sf::Joystick::getAxisPosition(id, sf::Joystick::Axis(axis));
	return 0.f;
}