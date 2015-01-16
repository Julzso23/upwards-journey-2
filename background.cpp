#include "Background.h"

Background::Background()
{
	texture.loadFromFile("images/background.png");
	sprite.setTexture(texture);
	sprite.setScale(3.f / 2.f, 3.f / 2.f);
	sprite.setPosition(0, -4320.f * (3.f / 2.f));
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

void Background::update(float dt)
{
	sprite.move(0, 1000.f * dt);
	if (sprite.getPosition().y > -15)
	{
		sprite.move(0, -4310.f * (3.f / 2.f));
	}
}