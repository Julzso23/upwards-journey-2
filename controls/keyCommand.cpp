#include "KeyCommand.h"

KeyCommand::KeyCommand()
{
}
KeyCommand::KeyCommand(std::vector<sf::Keyboard::Key> keys, std::function<void()> func)
{
	create(keys, func);
}

void KeyCommand::create(std::vector<sf::Keyboard::Key> keys, std::function<void()> func)
{
	for (std::size_t i = 0; i < keys.size(); i++)
	{
		KeyState key;
		key.key = keys[i];
		key.pressed = false;
		this->keys.insert(this->keys.end(), key);
	}
	callback = func;
}

void KeyCommand::keyPressed(sf::Keyboard::Key key)
{
	bool allPressed = true;
	for (std::size_t i = 0; i < keys.size(); i++)
	{
		if (keys[i].key == key)
		{
			keys[i].pressed = true;
		}
		else
		{
			if (!keys[i].pressed)
			{
				allPressed = false;
			}
		}
	}
	if (allPressed)
		callback();
}
void KeyCommand::keyReleased(sf::Keyboard::Key key)
{
	for (std::size_t i = 0; i < keys.size(); i++)
		if (keys[i].key == key)
			keys[i].pressed = false;
}