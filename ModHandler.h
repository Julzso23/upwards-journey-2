#ifndef MODHANDLER_H
#define MODHANDLER_H

#include "lib\lua.hpp"
#include <stdio.h>
#include <vector>
#include <SFML\Window\Mouse.hpp>
#include <SFML\Window\Keyboard.hpp>

class ModHandler
{
private:
	lua_State* L;

	static int include(lua_State* L);
public:
	ModHandler();

	void load();
	void update(float dt, bool paused);
	void draw();
	void mousePressed(sf::Mouse::Button button, int x, int y);
	void mouseReleased(sf::Mouse::Button button, int x, int y);

	void onExit();
};

#endif