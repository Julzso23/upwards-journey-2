#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML\Graphics.hpp>

class Background
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Background();
	sf::Sprite getSprite();
	void update(float dt);
};

#endif