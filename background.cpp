#include "Background.h"

Background::Background()
{
	texture.loadFromFile("images/background.png");
	sprite.setTexture(texture);
	sprite.setScale(3.f / 2.f, 3.f / 2.f);
	sprite.setPosition(0, -4320.f * (3.f / 2.f));
}

sf::Sprite Background::getSprite()
{
	return sprite;
}

void Background::update(float dt)
{
	sprite.move(0, 1000.f * dt);
	if (sprite.getPosition().y > -15)
	{
		sprite.move(0, -4310.f * (3.f / 2.f));
	}
}