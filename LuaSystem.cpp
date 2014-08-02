#include "LuaSystem.h"

const int LuaSystem::luaNewObject(lua_State* L)
{
	const char* name = luaL_checkstring(L, 1);
	GameObject** user_data = (GameObject**)lua_newuserdata(L, sizeof(GameObject*));
	*user_data = new GameObject(lua_tostring(L, 2), lua_tostring(L, 3), lua_tostring(L, 4));
	system->objects[name] = *user_data;
	luaL_getmetatable(L, "luaL_GameObject");
	lua_setmetatable(L, -2);
	return 1;
}

void LuaSystem::SetActiveObject(const char* name)
{
	;
}

GameObject* LuaSystem::luaCheckObject(lua_State* L, int N)
{
	return *(GameObject **)luaL_checkudata(L, N, "luaL_GameObject");
}

const int LuaSystem::luaRemoveObject(lua_State* L)
{
	GameObject* object = luaCheckObject(L, 1);
	delete object;
	return 0;
}

void LuaSystem::initializer(std::string title,unsigned int s_width, unsigned int s_height, unsigned int s_bit1, unsigned int s_bit2, unsigned int s_aa, bool s_flscrn)
{
	unsigned int width = s_width;
	unsigned int height = s_height;
	sf::ContextSettings settings;
	settings.depthBits = s_bit1;
	settings.stencilBits = s_bit2;
	settings.antialiasingLevel = s_aa;
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	int stylus;
	if (s_flscrn)
		stylus = sf::Style::Fullscreen;
	else
		stylus = sf::Style::Default;
	system = new GameApplication(title.c_str(), width, height, stylus, settings);
	mode = new GameMode();
	mode->window = system->window;
	system_window = system->window;
}

const int LuaSystem::luaConstructor(lua_State* L)
{
	initializer(lua_tostring(L, 1), (unsigned int)lua_tointeger(L, 2), (unsigned int)lua_tointeger(L, 3), (unsigned int)lua_tointeger(L, 4), (unsigned int)lua_tointeger(L, 5), (unsigned int)lua_tointeger(L, 6), (bool)lua_toboolean(L, 7));
	return 0;
}

void LuaSystem::Run()
{
	system->Initialize();
	while (system_window->isOpen())
	{
		mode->update();
		system->draw();
	}
	cleanup();
}

void LuaSystem::cleanup()
{
	mode->update();
	system->draw();
}

LuaSystem::LuaSystem()
{
}


LuaSystem::~LuaSystem()
{
}
