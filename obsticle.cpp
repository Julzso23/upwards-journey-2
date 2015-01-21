#include "Obsticle.h"

Obsticle::Obsticle(sf::Vector2f position, float size, sf::Vector2f speed)
{
	setPosition(position);
	this->speed = speed;
	this->size = size;
	this->shape.setSize(sf::Vector2f(size, size));
	this->shape.setFillColor(sf::Color::Black);
	this->collisionLines.resize(4);
}

bool Obsticle::drop(float dt)
{
	move(speed.x * dt, speed.y * dt);

	sf::Vector2f position = getPosition();
	// Top
	collisionLines[0].setPoints(sf::Vector2f(position.x, position.y), sf::Vector2f(position.x + size, position.y));
	// Left
	collisionLines[1].setPoints(sf::Vector2f(position.x, position.y), sf::Vector2f(position.x, position.y + size));
	// Right
	collisionLines[2].setPoints(sf::Vector2f(position.x + size, position.y), sf::Vector2f(position.x + size, position.y + size));
	// Bottom
	collisionLines[3].setPoints(sf::Vector2f(position.x, position.y + size), sf::Vector2f(position.x + size, position.y + size));

	if (position.y > 1080.f)
		return true;
	return false;
}

void Obsticle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw(shape, states);
}

float Obsticle::getSize()
{
	return size;
}

std::vector<Maths::Line>* Obsticle::getCollisionLines()
{
	return &collisionLines;
}