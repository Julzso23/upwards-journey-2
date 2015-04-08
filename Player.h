#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Obsticle.h"
#include "Maths.h"

class Player : public sf::Drawable, public sf::Transformable
{
private:
	sf::Vector2f speed;
	int lives;
	bool respawning;
	float respawnClock;
	Animation animation;
	sf::Texture hatTexure;
	sf::Sprite hatSprite;
	float vibrateClock;
	sf::Vector2f vibrationOffset;
	int score;

	std::vector<Maths::Line> collisionLines;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Player();

	void control(sf::Vector2f direction, float dt);

	void update(float dt);

	void isColliding(Obsticle* obsticle);

	int getLives();
	void addLives(int num);

	int getScore();
	void addScore(int num);

	void setHat(sf::String name);
};

#endif