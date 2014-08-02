#pragma once
#include "lua.hpp"
#include <iostream>

lua_State* L;
typedef int(*lua_CFunction) (lua_State *LuaInterpreter);
unsigned int GetLuaInt(std::string get_from_what)
{
	unsigned int statistic;

	/* the function name */
	lua_getglobal(L, "get_value");
	lua_pushstring(L, get_from_what.c_str());

	/* call the function with 2 arguments, return 1 result */
	lua_pcall(L, 1, 1, NULL);

	/* get the result */
	//statistic = (unsigned int)lua_tounsigned(L, -1);
	statistic = (unsigned int)lua_tounsigned(L, 1);
	lua_pop(L, 1);
	return statistic;
}

bool GetLuaBool(std::string get_from_what)
{
	bool statistic;

	/* the function name */
	lua_getglobal(L, "get_value");
	lua_pushstring(L, get_from_what.c_str());

	/* call the function with 2 arguments, return 1 result */
	lua_pcall(L, 1, 1, NULL);

	/* get the result */
	//statistic = (bool)lua_toboolean(L, -1);
	statistic = (bool)lua_toboolean(L, 1);
	lua_pop(L, 1);
	return statistic;
}
