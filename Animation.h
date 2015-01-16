#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>

class Animation : public sf::Drawable
{
private:
	sf::Clock clock;
	sf::Texture texture;
	sf::Sprite sprite;
	float period;
	int minFrame;
	int frames;
	int frame;
	sf::IntRect frameRect;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Animation();
	Animation(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame = 0);
	void create(sf::String texturePath, float period, int frames, sf::Vector2i frameSize, int minFrame = 0);
	sf::Sprite getSprite();
	void update(float dt);
	void setPos(sf::Vector2f position);
	sf::Vector2f getPos();
	void setRot(float angle);
	float getRot();
	void setScale(sf::Vector2f scale);
	sf::Vector2f getScale();
	void setColour(sf::Color colour);
};

#endif