#include "GamepadManager.h"

GamepadManager::GamepadManager()
{
	current = -1;
}

void GamepadManager::setCurrent(int id)
{
	if (id == -1)
		current = -1;
	else
		for (int i = 0; i < gamepads.size(); i++)
			if (gamepads[i].getId() == id)
				current = i;
}

void GamepadManager::addGamepad(int id)
{
	gamepads.insert(gamepads.end(), Gamepad(id));
}
void GamepadManager::removeGamepad(int id)
{
	for (int i = 0; i < gamepads.size(); i++)
		if (gamepads[i].getId() == id)
			gamepads.erase(gamepads.begin() + i);
}

std::vector<Gamepad>* GamepadManager::getGamepads()
{
	return &gamepads;
}

bool GamepadManager::isDown(XBoxButtons button)
{
	if (current == -1)
		return false;
	return gamepads[current].isDown(button);
}

float GamepadManager::getAxis(XBoxAxes axis)
{
	if (current == -1)
		return 0.f;
	return gamepads[current].getAxis(axis);
}