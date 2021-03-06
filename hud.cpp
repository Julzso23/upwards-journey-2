#include "HUD.h"
#include <math.h>

HUD::HUD()
{
	heartTexure.loadFromFile("images/heart.png");
	for (int i = 0; i < 5; i++)
		hearts[i].setPosition(sf::Vector2f(i * 64.f, 0.f));

	HUDFont.loadFromFile("fonts/Frail-Sans.otf");

	gameOverText.setFont(HUDFont);
	gameOverText.setString("GAME OVER");
	gameOverText.setCharacterSize(96);
	gameOverText.setColor(sf::Color::Red);
	gameOverText.setPosition(960.f - gameOverText.getLocalBounds().width / 2.f, 540.f - gameOverText.getLocalBounds().height / 2.f);

	scoreText.setFont(HUDFont);
	scoreText.setString("Score: 0");
	scoreText.setCharacterSize(64);
	scoreText.setColor(sf::Color::Black);
	scoreText.setPosition(4.f, 1000.f);
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
		drawColour = sf::Color(255, (sf::Uint8)floor(150 * abs(sin(heartFlashClock.getElapsedTime().asSeconds() * 10)) + 100), (sf::Uint8)floor(150 * abs(sin(heartFlashClock.getElapsedTime().asSeconds() * 10)) + 100));
	for (int i = 0; i < 5; i++)
	{
		hearts[i].setColor(drawColour);
		if (i + 1 > player->getLives())
			hearts[i].setTextureRect(sf::IntRect(128, 0, 64, 64));
		else
			hearts[i].setTextureRect(sf::IntRect(0, 0, 64, 64));
	}

	scoreText.setString("Score: " + std::to_string(player->getScore()));
}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 5; i++)
		target.draw(hearts[i]);
	if (player->getLives() == 0)
		target.draw(gameOverText);

	target.draw(scoreText);
}