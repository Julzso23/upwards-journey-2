#ifndef OBSTICLE_H
#define OBSTICLE_H

#include <SFML\Graphics.hpp>

class Obsticle : public sf::Drawable
{
private:
	sf::Vector2f position;
	sf::Vector2f speed;
	float size;
	sf::RectangleShape shape;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Obsticle(sf::Vector2f position, float size, sf::Vector2f speed);
	bool drop(float dt);
	sf::Vector2f getPos();
	float getSize();
};

#endif