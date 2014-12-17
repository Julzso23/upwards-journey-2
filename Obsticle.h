#ifndef OBSTICLE_H
#define OBSTICLE_H

#include <SFML\Graphics.hpp>

class Obsticle
{
private:
	sf::Vector2f position;
	sf::Vector2f speed;
	float size;
	sf::RectangleShape shape;
public:
	Obsticle(sf::Vector2f position, float size, sf::Vector2f speed);
	bool drop(float dt);
	void draw(sf::RenderWindow* window);
};

#endif