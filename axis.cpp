#include "Axis.h"

ControlSet::ControlSet()
{
	this->key = -1;
	this->joystick = -1;
	this->axis = -1;
	this->axisIsPos = true;
	this->mouse = -1;
}
ControlSet::ControlSet(int key, int joystick, int axis, bool axisIsPos, int mouse)
{
	this->key = key;
	this->joystick = joystick;
	this->axis = axis;
	this->axisIsPos = axisIsPos;
	this->mouse = mouse;
}

void ControlSet::create(int key, int joystick, int axis, bool axisIsPos, int mouse)
{
	this->key = key;
	this->joystick = joystick;
	this->axis = axis;
	this->axisIsPos = axisIsPos;
	this->mouse = mouse;
}

float ControlSet::getValue()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key)))
		return 1.0f;

	if (sf::Joystick::isConnected(joystick))
		if (sf::Joystick::hasAxis(joystick, sf::Joystick::Axis(axis)))
		{
			float val = sf::Joystick::getAxisPosition(joystick, sf::Joystick::Axis(axis)) / 100;
			if (axisIsPos)
				if (val > 0)
					return val;
			else
				if (val < 0)
					return val;
		}
	return 0;
}

Axis::Axis()
{
	this->positive = ControlSet();
	this->negative = ControlSet();
	this->deadZone = 0;
}
Axis::Axis(ControlSet positive, ControlSet negative, float deadZone)
{
	this->positive = positive;
	this->negative = negative;
	this->deadZone = deadZone;
}

void Axis::create(ControlSet positive, ControlSet negative, float deadZone)
{
	this->positive = positive;
	this->negative = negative;
	this->deadZone = deadZone;
}

float Axis::getValue()
{
	float p = positive.getValue();
	float n = negative.getValue();
	return (p - n > deadZone) || (p - n < -deadZone) ? p - n : 0;
}