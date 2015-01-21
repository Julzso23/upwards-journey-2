#include "Animation.h"

Animation::Animation()
{
	this->period = 0;
	this->frames = 0;
	this->minFrame = 0;
	this->frame = minFrame;
	this->frameRect = sf::IntRect(0, 0, 0, 0);
	setTexture(texture);
	setTextureRect(frameRect);
}
Animation::Animation(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame)
{
	this->period = period;
	this->frames = frames;
	this->minFrame = minFrame;
	this->frame = minFrame;
	this->frameRect = sf::IntRect(0, 0, frameSize.x, frameSize.y);
	texture.loadFromFile(texturePath);
	setTexture(texture);
	setTextureRect(frameRect);
	setOrigin(frameSize.x / 2.f, frameSize.y / 2.f);
}

void Animation::create(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame)
{
	this->period = period;
	this->frames = frames;
	this->minFrame = minFrame;
	this->frame = minFrame;
	this->frameRect = sf::IntRect(0, 0, frameSize.x, frameSize.y);
	texture.loadFromFile(texturePath);
	setTexture(texture);
	setTextureRect(frameRect);
	setOrigin(frameSize.x / 2.f, frameSize.y / 2.f);
}

void Animation::update(float dt)
{
	if (clock.getElapsedTime().asSeconds() >= period)
	{
		clock.restart();
		frame++;
		if (frame > frames) frame = minFrame;
		frameRect.left = frame * frameRect.width;
		setTextureRect(frameRect);
	}
}