#include "Game.h"
#include "UJ.h"
#include "Axis.h"
#include "Player.h"

#include <iostream>

void UJ::load()
{
	font.loadFromFile("fonts/Frail-Sans.otf");

	std::vector<GUI::Button> buttons;
	buttons.insert(buttons.end(), GUI::Button("Play", [&](){setMenu();}, &font));
	buttons.insert(buttons.end(), GUI::Button("Options", [&](){setMenu(&optionsMenu);}, &font));
	buttons.insert(buttons.end(), GUI::Button("Exit", [&](){exit();}, &font));
	mainMenu.setButtons(buttons);

	buttons.clear();
	buttons.insert(buttons.end(), GUI::Button("Video", [&](){}, &font));
	buttons.insert(buttons.end(), GUI::Button("Audio", [&](){}, &font));
	buttons.insert(buttons.end(), GUI::Button("Controls", [&](){}, &font));
	buttons.insert(buttons.end(), GUI::Button("Back", [&](){setMenu(&mainMenu);}, &font));
	optionsMenu.setButtons(buttons);

	curMenu = &mainMenu;
	curMenu->show();

	xAxis.create(ControlSet(sf::Keyboard::Right, 0, sf::Joystick::X, true, -1), ControlSet(sf::Keyboard::Left, 0, sf::Joystick::X, false, -1), 0.25);
	yAxis.create(ControlSet(sf::Keyboard::Down, 0, sf::Joystick::Y, true, -1), ControlSet(sf::Keyboard::Up, 0, sf::Joystick::Y, false, -1), 0.25);
}

void UJ::update(float dt)
{
	player.update(dt);
	player.move(sf::Vector2f(xAxis.getValue(), yAxis.getValue()), dt);
	background.update(dt);

	curMenu->update(dt);
}

void UJ::draw(sf::RenderWindow* window)
{
	window->draw(background.getSprite());
	window->draw(player.getSprite());

	curMenu->draw(&*window);
}

void UJ::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
{
	curMenu->mousePressed(button, position);
}
void UJ::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
{
	curMenu->mouseReleased(button, position);
}

void UJ::setMenu()
{
	curMenu->hide();
}
void UJ::setMenu(GUI::Menu* menu)
{
	curMenu->hide();
	curMenu = menu;
	curMenu->show();
}