#include "Player.h"
#include "Game.h"
#include <cmath>

Player::Player()
{
	setPosition(sf::Vector2f(960, 800));
	speed = sf::Vector2f(600, 0);
	lives = 3;
	respawning = false;
	animation.create("images/player.png", 0.1f, 2, sf::Vector2i(64, 64), 1);
	animation.setScale(sf::Vector2f(2.f, 2.f));
	vibrationOffset = sf::Vector2f(0, 0);
	hatSprite.setTexture(hatTexure);
	hatSprite.setOrigin(sf::Vector2f(hatTexure.getSize().x / 2.f, hatTexure.getSize().y / 2.f + 56.f));
	score = 0;

	collisionLines.resize(4);
}

void Player::control(sf::Vector2f direction, float dt)
{
	move(speed.x * direction.x * dt, speed.y * direction.y * dt);
	sf::Vector2f position = getPosition();
	if (position.x > 1920.f) position.x = 1920.f;
	if (position.x < 0.f) position.x = 0.f;
	animation.setRotation(direction.x * 25.f);
	hatSprite.setRotation(direction.x * 25.f);
}

void Player::update(float dt)
{
	sf::Vector2f position = getPosition();
	animation.update(dt);
	vibrationOffset = sf::Vector2f(0, 4 * sin(16 * vibrateClock.getElapsedTime().asSeconds()));
	animation.setPosition(sf::Vector2f(vibrationOffset.x, vibrationOffset.y));
	if (vibrateClock.getElapsedTime().asSeconds() >= 2 * 3.14159265)
		vibrateClock.restart();
	hatSprite.setPosition(vibrationOffset.x, vibrationOffset.y);
	if (respawning)
	{
		animation.setColor(sf::Color(255, 255, 255, (sf::Uint8)floor(200 * sin(respawnClock.getElapsedTime().asSeconds() * 10))));
		hatSprite.setColor(sf::Color(255, 255, 255, (sf::Uint8)floor(200 * sin(respawnClock.getElapsedTime().asSeconds() * 10))));
		if (respawnClock.getElapsedTime().asSeconds() > 3.f)
			respawning = false;
	}
	else
	{
		animation.setColor(sf::Color(255, 255, 255, 255));
		hatSprite.setColor(sf::Color(255, 255, 255, 255));
	}
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw(animation, states);
	target.draw(hatSprite, states);
}

void Player::isColliding(Obsticle* obsticle)
{
	if (!respawning)
	{
		sf::Vector2f obsticlePos = obsticle->getPosition();
		float size = obsticle->getSize();
		float w = 10.f;
		float h = 48.f;
		float angle = (3.14159265359f * animation.getRotation()) / 180;
		sf::Vector2f position = getPosition();
		// Top
		collisionLines[0].setPoints(sf::Vector2f(position.x - w * cos(angle) + h * sin(angle), position.y - w * sin(angle) - h * cos(angle)), sf::Vector2f(position.x + w * cos(angle) + h * sin(angle), position.y + w * sin(angle) - h * cos(angle)));
		// Left
		collisionLines[1].setPoints(sf::Vector2f(position.x - w * cos(angle) + h * sin(angle), position.y - w * sin(angle) - h * cos(angle)), sf::Vector2f(position.x - w * cos(angle) - h * sin(angle), position.y - w * sin(angle) + h * cos(angle)));
		// Right
		collisionLines[2].setPoints(sf::Vector2f(position.x + w * cos(angle) + h * sin(angle), position.y + w * sin(angle) - h * cos(angle)), sf::Vector2f(position.x + w * cos(angle) - h * sin(angle), position.y + w * sin(angle) + h * cos(angle)));
		// Bottom
		collisionLines[3].setPoints(sf::Vector2f(position.x - w * cos(angle) - h * sin(angle), position.y - w * sin(angle) + h * cos(angle)), sf::Vector2f(position.x + w * cos(angle) - h * sin(angle), position.y + w * sin(angle) + h * cos(angle)));

		std::vector<Maths::Line>* obsticleLines = obsticle->getCollisionLines();
		
		bool colliding = false;
		if ((position.x > obsticlePos.x) && (position.x < (obsticlePos.x + size)) && (position.y > obsticlePos.y) && (position.y < (obsticlePos.y + size)))
			colliding = true;
		else
			for (std::size_t i = 0; i < obsticleLines->size(); i++)
				for (std::size_t e = 0; e < collisionLines.size(); e++)
					if (Maths::lineIntersect((*obsticleLines)[i], collisionLines[e], nullptr, nullptr))
					{
						colliding = true;
						break;
					}
		if (colliding)
		{
			respawnClock.restart();
			lives--;
			if (lives < 0)
				lives = 0;
			respawning = true;
		}
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
	hatSprite.setOrigin(sf::Vector2f(hatTexure.getSize().x / 2.f, hatTexure.getSize().y / 2.f + 56.f));
}