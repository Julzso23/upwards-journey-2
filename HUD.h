#ifndef HUD_H
#define HUD_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Player.h"

class HUD
{
private:
	sf::Texture heartTexure;
	sf::Sprite hearts[5];

	Player* player;
public:
	HUD();
	void setPlayer(Player* player);
	void update();
	void draw(sf::RenderWindow* window);
};

#endif