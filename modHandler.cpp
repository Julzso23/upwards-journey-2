#include "ModHandler.h"
#include "lib\dirent.h"
#include <string>
#include <sys\stat.h>

ModHandler::ModHandler()
{
	L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "include", include);
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
						printf(lua_tostring(L, 1));
			}
}

int ModHandler::include(lua_State* L)
{
	if (lua_gettop(L) > 0)
	{
		std::string path("mods\\");
		path += lua_tostring(L, 1);
		if (luaL_dofile(L, path.c_str()))
			printf(lua_tostring(L, 1));
	}
	return 0;
}

void ModHandler::load()
{
	lua_getglobal(L, "load");
	if (lua_pcall(L, 0, 0, 0))
		printf(lua_tostring(L, 1));
}

void ModHandler::update(float dt)
{
	lua_getglobal(L, "update");
	lua_pushnumber(L, dt);
	if (lua_pcall(L, 1, 0, 0))
		printf(lua_tostring(L, 1));
}

void ModHandler::onExit()
{
	lua_close(L);
}