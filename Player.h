#ifndef PLAYER
#define PLAYER

#include <SFML\Graphics.hpp>
#include "Animation.h"

class Player {
	private:
		sf::Vector2f position;
		sf::Vector2f speed;
		int lives;
		Animation animation;
		sf::Clock vibrateClock;
		sf::Vector2f vibrationOffset;
	public:
		Player();
		Player(float x, float y);
		void move(sf::Vector2f direction, float dt);
		void move(float mod, float arg, float dt);
		void update(float dt);
		sf::Vector2f getPos();
		sf::Sprite getSprite();
};

#endif