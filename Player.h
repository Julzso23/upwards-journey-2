#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Obsticle.h"
#include "Maths.h"

class Player : public sf::Drawable
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

	std::vector<Maths::Line> collisionLines;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Player();

	void move(sf::Vector2f direction, float dt);

	void update(float dt);

	sf::Vector2f getPos();

	void isColliding(Obsticle* obsticle);

	int getLives();
	void addLives(int num);

	int getScore();
	void addScore(int num);

	void setHat(sf::String name);
};

#endif