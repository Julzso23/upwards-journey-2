#include "ModHandler.h"
#include "lib\dirent.h"
#include <string>
#include <sys\stat.h>

ModHandler::ModHandler()
{
	L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "include", include);
	lua_newtable(L);
	lua_setglobal(L, "mod");
	DIR* dir;
	struct dirent* ent;
	if ((dir = opendir("mods\\")) != NULL)
		while ((ent = readdir(dir)) != NULL)
			if (ent->d_type == DT_DIR)
			{
				std::string path("mods\\");
				path += ent->d_name;
				path += "\\mod.lua";
				struct stat buffer;
				if (stat(path.c_str(), &buffer) == 0)
					if (luaL_dofile(L, path.c_str()))
						printf("%s\n", lua_tostring(L, 1));
			}
}

int ModHandler::include(lua_State* L)
{
	if (lua_gettop(L) > 0)
	{
		std::string path("mods\\");
		path += lua_tostring(L, 1);
		if (luaL_dofile(L, path.c_str()))
			printf("%s\n", lua_tostring(L, 1));
	}
	return 0;
}

void ModHandler::load()
{
	lua_getglobal(L, "mod");
	lua_getfield(L, 1, "load");
	if (lua_pcall(L, 0, 0, 0))
		printf("%s\n", lua_tostring(L, 1));
}

void ModHandler::update(float dt, bool paused)
{
	lua_pushboolean(L, paused);
	lua_setglobal(L, "paused");
	lua_getglobal(L, "mod");
	lua_getfield(L, 1, "update");
	lua_pushnumber(L, dt);
	if (lua_pcall(L, 1, 0, 0))
		printf("%s\n", lua_tostring(L, 1));
}

void ModHandler::draw()
{
	lua_getglobal(L, "mod");
	lua_getfield(L, 1, "draw");
	if (lua_pcall(L, 0, 0, 0))
		printf("%s\n", lua_tostring(L, 1));
}

void ModHandler::mousePressed(sf::Mouse::Button button, int x, int y)
{
	lua_getglobal(L, "mod");
	lua_getfield(L, 1, "mousePressed");
	switch (button)
	{
	case sf::Mouse::Left: lua_pushstring(L, "left"); break;
	case sf::Mouse::Right: lua_pushstring(L, "right"); break;
	case sf::Mouse::Middle: lua_pushstring(L, "middle"); break;
	default: lua_pushstring(L, "unknown"); break;
	}
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	if (lua_pcall(L, 3, 0, 0))
		printf("%s\n", lua_tostring(L, 1));
}
void ModHandler::mouseReleased(sf::Mouse::Button button, int x, int y)
{
	lua_getglobal(L, "mod");
	lua_getfield(L, 1, "mousePressed");
	switch (button)
	{
	case sf::Mouse::Left: lua_pushstring(L, "left"); break;
	case sf::Mouse::Right: lua_pushstring(L, "right"); break;
	case sf::Mouse::Middle: lua_pushstring(L, "middle"); break;
	default: lua_pushstring(L, "unknown"); break;
	}
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	if (lua_pcall(L, 3, 0, 0))
		printf("%s\n", lua_tostring(L, 1));
}

void ModHandler::onExit()
{
	lua_getglobal(L, "mod");
	lua_getfield(L, 1, "onExit");
	if (lua_pcall(L, 0, 0, 0))
		printf("%s\n", lua_tostring(L, 1));
	lua_close(L);
}