#include "GameApp.h"
#include <iostream>

sf::ContextSettings GameApp::GetSettings()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;
	return settings;
}

GameApp::GameApp(const char* title, unsigned int width, unsigned int height)
: m_window(sf::VideoMode(width, height), title, sf::Style::Default, this->GetSettings())
{
	m_window.setVerticalSyncEnabled(true);
}


GameApp::~GameApp()
{
}

void GameApp::Run()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cerr << "Error encountered while initializing GLEW! Exitting." << std::endl;
		return;
	}
	//Initialize app
	if (!Init())
		{
		std::cerr << "Error encountered while initializing application! Exitting." << std::endl;
		return;
		}
	//Main loop
	while (m_window.isOpen())
	{
		// HANDLE EVENT MESSAGES FROM OS
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}

		// clear the buffers
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// draw...
		sf::Time time = m_clock.restart();
		//update
		Update(time);
		//Render
		Render(time);

		// end the current frame (internally swaps the front and back buffers)
		m_window.display();
	}
	//Cleanup resources before exiting
	Cleanup();
}