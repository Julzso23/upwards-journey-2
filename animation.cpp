#include "Animation.h"

Animation::Animation()
{
	this->period = 0;
	this->frames = 0;
	this->minFrame = 0;
	this->frame = minFrame;
	this->frameRect = sf::IntRect(0, 0, 0, 0);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
}
Animation::Animation(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame)
{
	this->period = period;
	this->frames = frames;
	this->minFrame = minFrame;
	this->frame = minFrame;
	this->frameRect = sf::IntRect(0, 0, frameSize.x, frameSize.y);
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	sprite.setOrigin(frameSize.x / 2.f, frameSize.y / 2.f);
}

void Animation::create(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame)
{
	this->period = period;
	this->frames = frames;
	this->minFrame = minFrame;
	this->frame = minFrame;
	this->frameRect = sf::IntRect(0, 0, frameSize.x, frameSize.y);
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	sprite.setOrigin(frameSize.x / 2.f, frameSize.y / 2.f);
}

sf::Sprite Animation::getSprite()
{
	return sprite;
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

void Animation::update(float dt)
{
	if (clock.getElapsedTime().asSeconds() >= period)
	{
		clock.restart();
		frame++;
		if (frame > frames) frame = minFrame;
		frameRect.left = frame * frameRect.width;
		sprite.setTextureRect(frameRect);
	}
}

void Animation::setPos(sf::Vector2f position)
{
	sprite.setPosition(position);
}
sf::Vector2f Animation::getPos()
{
	return sprite.getPosition();
}

void Animation::setRot(float angle)
{
	sprite.setRotation(angle);
}
float Animation::getRot()
{
	return sprite.getRotation();
}

void Animation::setScale(sf::Vector2f scale)
{
	sprite.setScale(scale);
}
sf::Vector2f Animation::getScale()
{
	return sprite.getScale();
}

void Animation::setColour(sf::Color colour)
{
	sprite.setColor(colour);
}