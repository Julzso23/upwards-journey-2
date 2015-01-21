#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>

class Animation : public sf::Sprite
{
private:
	sf::Clock clock;
	sf::Texture texture;
	float period;
	int minFrame;
	int frames;
	int frame;
	sf::IntRect frameRect;
public:
	Animation();
	Animation(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame = 0);
	void create(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame = 0);
	void update(float dt);
};

#endif