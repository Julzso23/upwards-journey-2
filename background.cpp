#include "Background.h"

Background::Background()
{
	texture.loadFromFile("images/background.png");
	sprite.setTexture(texture);
}

sf::Sprite Background::getSprite()
{
	return sprite;
}

void Background::update(float dt)
{

}