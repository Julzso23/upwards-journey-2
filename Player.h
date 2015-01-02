#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Obsticle.h"

class Player
{
private:
	sf::Vector2f position;
	sf::Vector2f speed;
	int lives;
	bool respawning;
	sf::Clock respawnClock;
	Animation animation;
	sf::Texture hatTexure;
	sf::Sprite hatSprite;
	sf::Clock vibrateClock;
	sf::Vector2f vibrationOffset;
	int score;
public:
	Player();

	void move(sf::Vector2f direction, float dt);

	void update(float dt);

	void draw(sf::RenderWindow* window);

	sf::Vector2f getPos();

	void isColliding(Obsticle* obsticle);

	int getLives();
};

#endif