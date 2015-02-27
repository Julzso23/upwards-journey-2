#include "Axis.h"

ControlSet::ControlSet(int key, GamepadManager* manager, XBoxAxes axis, bool axisIsPos, int mouse)
{
	create(key, manager, axis, axisIsPos, mouse);
}

void ControlSet::create(int key, GamepadManager* manager, XBoxAxes axis, bool axisIsPos, int mouse)
{
	this->key = key;
	this->manager = manager;
	this->axis = axis;
	this->axisIsPos = axisIsPos;
	this->mouse = mouse;
}

float ControlSet::getValue()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key)))
		return 1.0f;

	float val = manager->getAxis(axis);
	if (axisIsPos)
		if (val > 0)
			return val;
	else
		if (val < 0)
			return val;
	return 0;
}

Axis::Axis(ControlSet positive, ControlSet negative, float deadZone)
	: positive(positive), negative(negative)
{
	create(deadZone);
}

void Axis::create(float deadZone)
{
	this->deadZone = deadZone;
}

float Axis::getValue()
{
	float p = positive.getValue();
	float n = negative.getValue();
	return (p - n > deadZone) || (p - n < -deadZone) ? p - n : 0;
}