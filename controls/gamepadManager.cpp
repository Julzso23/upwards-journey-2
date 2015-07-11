#include "GamepadManager.h"

GamepadManager::GamepadManager()
{
	for (int i = 0; i < sf::Joystick::Count; i++)
		if (sf::Joystick::isConnected(i))
			addGamepad(i);
	current = -1;
}

void GamepadManager::setCurrent(int id)
{
	current = -1;
	if (id != -1)
		for (std::size_t i = 0; i < gamepads.size(); i++)
			if (gamepads[i].getId() == id)
				current = i;
}

void GamepadManager::addGamepad(int id)
{
	gamepads.insert(gamepads.end(), Gamepad(id));
}
void GamepadManager::removeGamepad(int id)
{
	for (std::size_t i = 0; i < gamepads.size(); i++)
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