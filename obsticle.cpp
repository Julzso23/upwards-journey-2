#include "Obsticle.h"

Obsticle::Obsticle(sf::Vector2f position, float size, sf::Vector2f speed)
{
	this->position = position;
	this->speed = speed;
	this->size = size;
	this->shape.setPosition(position);
	this->shape.setSize(sf::Vector2f(size, size));
	this->shape.setFillColor(sf::Color::Black);
}

bool Obsticle::drop(float dt)
{
	position.x += speed.x * dt;
	position.y += speed.y * dt;
	shape.setPosition(position);
	if (position.y > 1080.f)
		return true;
	return false;
}

void Obsticle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}

sf::Vector2f Obsticle::getPos()
{
	return position;
}

float Obsticle::getSize()
{
	return size;
}