#include "Player.h"
#include "Game.h"
#include <cmath>

Player::Player()
{
	position = sf::Vector2f(960, 800);
	animation.setPos(position);
	speed = sf::Vector2f(600, 0);
	lives = 3;
	respawning = false;
	animation.create("images/player.png", 0.1f, 2, sf::Vector2i(64, 64), 1);
	animation.setScale(sf::Vector2f(2.f, 2.f));
	vibrationOffset = sf::Vector2f(0, 0);
	hatSprite.setTexture(hatTexure);
	hatSprite.setOrigin(sf::Vector2f(hatTexure.getSize().x / 2, hatTexure.getSize().y / 2 + 56.f));
	score = 0;
}

void Player::move(sf::Vector2f direction, float dt)
{
	position.x += speed.x * direction.x * dt;
	position.y += speed.y * direction.y * dt;
	if (position.x > 1920.f) position.x = 1920.f;
	if (position.x < 0.f) position.x = 0.f;
	animation.setPos(sf::Vector2f(position.x + vibrationOffset.x, position.y + vibrationOffset.y));
	animation.setRot(direction.x * 25.f);
	hatSprite.setRotation(direction.x * 25.f);
}

void Player::update(float dt)
{
	animation.update(dt);
	vibrationOffset = sf::Vector2f(0, 4 * sin(16 * vibrateClock.getElapsedTime().asSeconds()));
	if (vibrateClock.getElapsedTime().asSeconds() >= 2 * 3.14159265)
		vibrateClock.restart();
	animation.setPos(sf::Vector2f(position.x + vibrationOffset.x, position.y + vibrationOffset.y));
	hatSprite.setPosition(position.x + vibrationOffset.x, position.y + vibrationOffset.y);
	if (respawning)
	{
		animation.setColour(sf::Color(255, 255, 255, 200 * sin(respawnClock.getElapsedTime().asSeconds() * 10)));
		hatSprite.setColor(sf::Color(255, 255, 255, 200 * sin(respawnClock.getElapsedTime().asSeconds() * 10)));
		if (respawnClock.getElapsedTime().asSeconds() > 3.f)
			respawning = false;
	}
	else
	{
		animation.setColour(sf::Color(255, 255, 255, 255));
		hatSprite.setColor(sf::Color(255, 255, 255, 255));
	}
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(animation, states);
	target.draw(hatSprite);
}

sf::Vector2f Player::getPos()
{
	return position;
}

void Player::isColliding(Obsticle* obsticle)
{
	if (!respawning && ((position.x + 16) > obsticle->getPos().x) && ((position.x - 16) < (obsticle->getPos().x + obsticle->getSize())) && ((position.y + 48) > obsticle->getPos().y) && ((position.y - 48) < (obsticle->getPos().y + obsticle->getSize())))
	{
		respawnClock.restart();
		lives--;
		if (lives < 0)
			lives = 0;
		respawning = true;
	}
}

int Player::getLives()
{
	return lives;
}
void Player::addLives(int num)
{
	lives += abs(num);
	if (lives > 5)
		lives = 5;
}

int Player::getScore()
{
	return score;
}
void Player::addScore(int num)
{
	score += abs(num);
}

void Player::setHat(sf::String name)
{
	if (name == "")
		hatTexure = sf::Texture();
	else
		hatTexure.loadFromFile("images/hats/" + name + ".png");
	hatSprite = sf::Sprite();
	hatSprite.setTexture(hatTexure);
	hatSprite.setOrigin(sf::Vector2f(hatTexure.getSize().x / 2, hatTexure.getSize().y / 2 + 56.f));
}