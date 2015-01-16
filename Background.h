#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML\Graphics.hpp>

class Background : public sf::Drawable
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Background();
	void update(float dt);
};

#endif