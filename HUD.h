#ifndef HUD_H
#define HUD_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Player.h"

class HUD : public sf::Drawable
{
private:
	sf::Texture heartTexure;
	sf::Sprite hearts[5];
	sf::Clock heartFlashClock;

	sf::Text gameOverText;
	sf::Font HUDFont;

	Player* player;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	HUD();
	void setPlayer(Player* player);
	void update();
};

#endif