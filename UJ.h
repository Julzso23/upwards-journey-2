#ifndef UPWARDSJOURNEY_H
#define UPWARDSJOURNEY_H

#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Axis.h"
#include "Player.h"
#include "Background.h"
#include "GUI\Menu.h"
#include "ObsticleDropper.h"

class UJ : public Game
{
private:
	Player player;
	Axis xAxis;
	Axis yAxis;

	Background background;

	ObsticleDropper dropper;
	std::vector<Obsticle>* obsticles;

	GUI::Menu mainMenu;
	GUI::Menu optionsMenu;
	GUI::Menu* curMenu;

	sf::Font font;
public:
	UJ::UJ(sf::String title, sf::VideoMode size, bool fullscreen) : Game(title, size, fullscreen) {};

	void load();

	void update(float dt);

	void draw(sf::RenderWindow* window);

	void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
	void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);

	void setMenu();
	void setMenu(GUI::Menu* menu);
};

#endif