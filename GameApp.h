#pragma once
#include <gl/glew.h>        //added for opengl extensions
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>
using namespace glm;
class GameApp
{
public:
	GameApp(const char* title, unsigned int width, unsigned int height);
	GameApp(const GameApp& other);
	GameApp& operator=(const GameApp&);
	virtual ~GameApp(void);
	//Main loop
	void Run();

	//Framework methods
	virtual bool Init() = 0;
	virtual void Update(sf::Time& time) = 0;
	virtual void Render(sf::Time& time) = 0;
	virtual void Cleanup() = 0;
private:
	sf::ContextSettings GetSettings();
	sf::Window m_window;
	sf::Clock m_clock;
};

