#ifndef UPWARDSJOURNEY_H
#define UPWARDSJOURNEY_H

#include <SFML\Graphics.hpp>
#include "Game.h"
#include "controls\Axis.h"
#include "Player.h"
#include "Background.h"
#include "GUI\HTMLMenu.h"
#include "ObsticleDropper.h"
#include "controls\KeyCommand.h"
#include "HUD.h"
#include "pickups\PickupDropper.h"
#include "controls\GamepadManager.h"
//#include "ModHandler.h"

class UJ : public Game
{
private:
	Player player;

	GamepadManager gamepadManager;

	Axis xAxis;
	Axis yAxis;

	Background background;

	HUD hud;

	ObsticleDropper dropper;
	std::vector<Obsticle>* obsticles;

	PickupDropper<Pickups::Health> healthDropper;
	PickupDropper<Pickups::Coin> coinDropper;

	GUI::HTMLMenu htmlMenu;

	std::vector<KeyCommand> keyCommands;

	bool paused;

	sf::Font font;

	//ModHandler modHandler;


	void load();

	void update(float dt);

	void draw(sf::RenderWindow* window);
	void drawUnscaled(sf::RenderWindow* window);

	void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
	void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);
	void mouseMoved(int x, int y);

	void keyPressed(sf::Keyboard::Key key);
	void keyReleased(sf::Keyboard::Key key);

	void joystickConnected(int id);
	void joystickDisconnected(int id);

	void windowResized(sf::Vector2u size);

	void onExit();
public:
	UJ::UJ(sf::String title, sf::VideoMode size, bool fullscreen);
};

#endif