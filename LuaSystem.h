#pragma once
#include "GameApplication.h"
#include "GameMode.h"
#include "lwa.h"
class LuaSystem
{
public:
	static GameApplication* system;
	static GameMode* mode;
	static void initializer(std::string title, unsigned int s_width, unsigned int s_height, unsigned int s_bit1, unsigned int s_bit2, unsigned int s_aa, bool s_flscrn);
	static const int luaConstructor(lua_State* L);
	static void Run();
	static void cleanup();
	static void SetActiveObject(const char* name);
	LuaSystem();
	~LuaSystem();
	static const int luaNewObject(lua_State* L);
	static GameObject* luaCheckObject(lua_State* L, int N);
	static const int luaRemoveObject(lua_State* L);
private:
	static sf::Window* system_window;
};

