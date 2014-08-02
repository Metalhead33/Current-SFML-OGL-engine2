#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "GameObject.h"
class GameMode
{
public:
	sf::Window* window;
	sf::Event event;
	GameObject* ActiveObject;
	void update();
	GameMode();
	~GameMode();
	void cleanup();
private:
	void keypress();
	void keyrelease();
};

