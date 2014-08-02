#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "common_headers.h"
#include "GameObject.h"
class GameApplication
{
protected:
	sf::Clock* m_clock;
public:
	std::map<std::string, GameObject*> objects;
	sf::Window* window;
	bool Initialize();
	void draw();
	virtual void update(sf::Time delta_time);
	//bool Run();
	GameApplication(const char* title, unsigned int width, unsigned int height, int style, const sf::ContextSettings& settings);
	GameApplication(const GameApplication& other);
	GameApplication& operator=(const GameApplication&);
	virtual ~GameApplication();
	bool IsRunning();
	void cleanup();
};

