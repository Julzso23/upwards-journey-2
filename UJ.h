#ifndef UPWARDSJOURNEY_H
#define UPWARDSJOURNEY_H

#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Axis.h"
#include "Player.h"
#include "Background.h"
#include "GUI\Menu.h"
#include "ObsticleDropper.h"
#include "KeyCommand.h"
#include "HUD.h"
#include "pickups\Health.h"

class UJ : public Game
{
private:
	Player player;
	Axis xAxis;
	Axis yAxis;

	Background background;

	HUD hud;

	ObsticleDropper dropper;
	std::vector<Obsticle>* obsticles;

	std::vector<Pickups::Health> pickups;

	GUI::Menu mainMenu;
	GUI::Menu optionsMenu;
	GUI::Menu optionsVideoMenu;
	GUI::Menu optionsVideoResolutionsMenu;
	GUI::Menu* curMenu;

	std::vector<KeyCommand> keyCommands;

	bool paused;

	sf::Font font;
public:
	UJ::UJ(sf::String title, sf::VideoMode size, bool fullscreen) : Game(title, size, fullscreen) {};

	void load();

	void update(float dt);

	void draw(sf::RenderWindow* window);

	void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
	void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);

	void keyPressed(sf::Keyboard::Key key);
	void keyReleased(sf::Keyboard::Key key);

	void setMenu();
	void setMenu(GUI::Menu* menu);
};

#endif