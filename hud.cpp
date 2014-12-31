#include "HUD.h"
#include <math.h>

HUD::HUD()
{
	heartTexure.loadFromFile("images/heart.png");
	for (int i = 0; i < 5; i++)
		hearts[i].setPosition(sf::Vector2f(i * 64, 0));
}

void HUD::setPlayer(Player* player)
{
	this->player = player;
	for (int i = 0; i < 5; i++)
	{
		hearts[i].setTexture(heartTexure);
		if (i + 1 > player->getLives())
			hearts[i].setTextureRect(sf::IntRect(128, 0, 64, 64));
		else
			hearts[i].setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
}

void HUD::update()
{
	sf::Color drawColour(255, 255, 255);
	if (player->getLives() == 0)
		drawColour = sf::Color(255, 150 * abs(sin(heartFlashClock.getElapsedTime().asSeconds() * 10)) + 100, 150 * abs(sin(heartFlashClock.getElapsedTime().asSeconds() * 10)) + 100);
	for (int i = 0; i < 5; i++)
	{
		hearts[i].setColor(drawColour);
		if (i + 1 > player->getLives())
			hearts[i].setTextureRect(sf::IntRect(128, 0, 64, 64));
		else
			hearts[i].setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
}

void HUD::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < 5; i++)
		window->draw(hearts[i]);
}