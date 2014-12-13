#include "Game.h"
#include "UJ.h"
#include "Axis.h"
#include "Player.h"

void UJ::load()
{
	xAxis.create(ControlSet(sf::Keyboard::Right, 0, sf::Joystick::X, true, -1), ControlSet(sf::Keyboard::Left, 0, sf::Joystick::X, false, -1), 0.25);
	yAxis.create(ControlSet(sf::Keyboard::Down, 0, sf::Joystick::Y, true, -1), ControlSet(sf::Keyboard::Up, 0, sf::Joystick::Y, false, -1), 0.25);
}

void UJ::update(float dt)
{
	player.update(dt);
	player.move(sf::Vector2f(xAxis.getValue(), yAxis.getValue()), dt);
	background.update(dt);
}

void UJ::draw()
{
	render(background.getSprite());
	render(player.getSprite());
}