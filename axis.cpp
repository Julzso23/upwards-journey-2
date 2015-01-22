#include "Axis.h"

ControlSet::ControlSet()
{
	create(-1, -1, -1, true, -1);
}
ControlSet::ControlSet(int key, int joystick, int axis, bool axisIsPos, int mouse)
{
	create(key, joystick, axis, axisIsPos, mouse);
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
	create(ControlSet(), ControlSet(), 0);
}
Axis::Axis(ControlSet positive, ControlSet negative, float deadZone)
{
	create(positive, negative, deadZone);
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