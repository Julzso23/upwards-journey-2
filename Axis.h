#ifndef AXIS
#define AXIS

#include <SFML\Graphics.hpp>

class ControlSet
{
private:
	int key;
	int joystick;
	int axis;
	bool axisIsPos;
	int mouse;
public:
	ControlSet();
	ControlSet(int key, int joystick, int axis, bool axisIsPos, int mouse);
	void create(int key, int joystick, int axis, bool axisIsPos, int mouse);
	float getValue();
};

class Axis
{
private:
	ControlSet positive;
	ControlSet negative;
	float deadZone;
public:
	Axis();
	Axis(ControlSet positive, ControlSet negative, float deadZone);
	void create(ControlSet positive, ControlSet negative, float deadZone);
	float getValue();
};

#endif