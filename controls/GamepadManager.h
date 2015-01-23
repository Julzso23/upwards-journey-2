#ifndef CONTROLS_GAMEPADMANAGER_H
#define CONTROLS_GAMEPADMANAGER_H

#include <vector>
#include "Gamepad.h"

class GamepadManager
{
private:
	std::vector<Gamepad> gamepads;
	int current;
public:
	GamepadManager();

	void setCurrent(int id);
	void addGamepad(int id);
	void removeGamepad(int id);

	std::vector<Gamepad>* getGamepads();

	bool isDown(XBoxButtons button);
	float getAxis(XBoxAxes axis);
};

#endif