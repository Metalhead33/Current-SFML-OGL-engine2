#include "GameApplication.h"
#include <iostream>


GameApplication::GameApplication(const char* title, unsigned int width, unsigned int height, int style, const sf::ContextSettings& settings)
{
	window = new sf::Window(sf::VideoMode(width, height), title, style, settings);
}

GameApplication::~GameApplication()
{
}

void GameApplication::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto iterator = objects.begin(); iterator != objects.end(); iterator++)
	{
		iterator->second->draw();
	}
	window->display();
}

/*bool GameApplication::Run()
{
	if (!Initialize())
	{
		std::cerr << "Error Initializing application! Exiting." << std::endl;
		return;
	};
	while (window->isOpen())
	{
		//retrieve new elapsed time each frame
		sf::Time time = m_clock->restart();
		update(time);
		draw(window);
	}
}*/

bool GameApplication::Initialize()
{
	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	window->setActive(true);
}

void GameApplication::cleanup()
{
	;
}

bool GameApplication::IsRunning()
{
	return window->isOpen();
}
