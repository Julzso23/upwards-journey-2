#include "HUD.h"
#include <math.h>

HUD::HUD()
{
	heartTexure.loadFromFile("images/heart.png");
	for (int i = 0; i < 5; i++)
		hearts[i].setPosition(sf::Vector2f(i * 64, 0));

	HUDFont.loadFromFile("fonts/Frail-Sans.otf");

	gameOverText.setFont(HUDFont);
	gameOverText.setString("GAME OVER");
	gameOverText.setCharacterSize(96);
	gameOverText.setColor(sf::Color::Red);
	gameOverText.setPosition(960 - gameOverText.getLocalBounds().width / 2, 540 - gameOverText.getLocalBounds().height / 2);
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
	if (player->getLives() == 0)
		window->draw(gameOverText);
}