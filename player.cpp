#include "Player.h"
#include "Game.h"
#include <cmath>

Player::Player()
{
	position = sf::Vector2f(960, 800);
	speed = sf::Vector2f(600, 0);
	lives = 3;
	animation.create("images/player.png", 0.1f, 2, sf::Vector2i(64, 64), 1);
	animation.setScale(sf::Vector2f(2.f, 2.f));
	vibrationOffset = sf::Vector2f(0, 0);
}
Player::Player(float x, float y)
{
	position = sf::Vector2f(x, y);
	speed = sf::Vector2f(400, 0);
	lives = 3;
	animation.create("images/player.png", 0.1f, 2, sf::Vector2i(64, 64), 1);
	vibrationOffset = sf::Vector2f(0, 0);
}

void Player::move(sf::Vector2f direction, float dt)
{
	position.x = position.x + speed.x * direction.x * dt;
	position.y = position.y + speed.y * direction.y * dt;
	animation.setPos(sf::Vector2f(position.x + vibrationOffset.x, position.y + vibrationOffset.y));
	animation.setRot(direction.x * 25);
}
void Player::move(float mod, float arg, float dt)
{
	position.x = position.x + speed.x * mod * cosf(arg) * dt;
	position.y = position.y + speed.y * mod * sinf(arg) * dt;
	animation.setPos(position);
	animation.setRot(arg);
}

void Player::update(float dt)
{
	animation.update(dt);
	vibrationOffset = sf::Vector2f(0, 4 * sin(16 * vibrateClock.getElapsedTime().asSeconds()));
	if (vibrateClock.getElapsedTime().asSeconds() >= 2 * 3.14159265)
		vibrateClock.restart();
}

sf::Vector2f Player::getPos()
{
	return position;
}

sf::Sprite Player::getSprite()
{
	return animation.getSprite();
}