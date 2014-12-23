#ifndef KEYCOMMAND_H
#define KEYCOMMAND_H

#include <vector>
#include <functional>
#include <SFML\Graphics.hpp>

struct KeyState
{
	sf::Keyboard::Key key;
	bool pressed;
};

class KeyCommand
{
private:
	std::vector<KeyState> keys;
	std::function<void()> callback;
public:
	KeyCommand();
	KeyCommand(std::vector<sf::Keyboard::Key> keys, std::function<void()> func);
	void create(std::vector<sf::Keyboard::Key> keys, std::function<void()> func);
	void keyPressed(sf::Keyboard::Key);
	void keyReleased(sf::Keyboard::Key);
};

#endif