#ifndef UPWARDSJOURNEY_H
#define UPWARDSJOURNEY_H

#include <SFML\Graphics.hpp>
#include "Axis.h"
#include "Player.h"
#include "Background.h"

class UJ : public Game
{
private:
	Player player;
	Axis xAxis;
	Axis yAxis;
	Background background;
public:
	UJ::UJ(sf::String title, sf::VideoMode size, bool fullscreen) : Game(title, size, fullscreen) {};
	void load();
	void update(float dt);
	void draw();
	void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
	void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);
};

#endif