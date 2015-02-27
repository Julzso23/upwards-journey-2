#ifndef CONTROLS_AXIS_H
#define CONTROLS_AXIS_H

#include <SFML\Graphics.hpp>
#include "GamepadManager.h"

class ControlSet
{
private:
	int key;
	GamepadManager* manager;
	XBoxAxes axis;
	bool axisIsPos;
	int mouse;
public:
	ControlSet(int key, GamepadManager* manager, XBoxAxes axis, bool axisIsPos, int mouse);
	void create(int key, GamepadManager* manager, XBoxAxes axis, bool axisIsPos, int mouse);
	float getValue();
};

class Axis
{
private:
	ControlSet positive;
	ControlSet negative;
	float deadZone;
public:
	Axis(ControlSet positive, ControlSet negative, float deadZone);
	void create(float deadZone);
	float getValue();
};

#endif