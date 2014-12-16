#include "Game.h"
#include "UJ.h"
#include "Axis.h"
#include "Player.h"

#include <iostream>

void UJ::load()
{
	std::vector<GUI::Button> buttons;
	buttons.insert(buttons.end(), GUI::Button("Play", [&](){}));
	buttons.insert(buttons.end(), GUI::Button("Options", [&](){}));
	buttons.insert(buttons.end(), GUI::Button("Exit", [&](){exit();}));
	mainMenu.setButtons(buttons);

	xAxis.create(ControlSet(sf::Keyboard::Right, 0, sf::Joystick::X, true, -1), ControlSet(sf::Keyboard::Left, 0, sf::Joystick::X, false, -1), 0.25);
	yAxis.create(ControlSet(sf::Keyboard::Down, 0, sf::Joystick::Y, true, -1), ControlSet(sf::Keyboard::Up, 0, sf::Joystick::Y, false, -1), 0.25);
}

void UJ::update(float dt)
{
	player.update(dt);
	player.move(sf::Vector2f(xAxis.getValue(), yAxis.getValue()), dt);
	background.update(dt);

	mainMenu.update(dt);
}

void UJ::draw(sf::RenderWindow* window)
{
	window->draw(background.getSprite());
	window->draw(player.getSprite());
	mainMenu.draw(&*window);
}

void UJ::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
{
	mainMenu.mousePressed(button, position);
}
void UJ::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
{
	mainMenu.mouseReleased(button, position);
}