#ifndef MODHANDLER_H
#define MODHANDLER_H

#include "lib\lua.hpp"
#include <stdio.h>
#include <vector>

class ModHandler
{
private:
	lua_State* L;

	static int include(lua_State* L);
public:
	ModHandler();

	void load();
	void update(float dt);

	void onExit();
};

#endif