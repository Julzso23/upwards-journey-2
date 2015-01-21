#ifndef OBSTICLE_H
#define OBSTICLE_H

#include <SFML\Graphics.hpp>
#include "Maths.h"

class Obsticle : public sf::Drawable, public sf::Transformable
{
private:
	sf::Vector2f speed;
	float size;
	sf::RectangleShape shape;

	std::vector<Maths::Line> collisionLines;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Obsticle(sf::Vector2f position, float size, sf::Vector2f speed);
	bool drop(float dt);
	float getSize();
	std::vector<Maths::Line>* getCollisionLines();
};

#endif