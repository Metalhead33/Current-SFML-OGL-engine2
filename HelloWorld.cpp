#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <map>
#include "lwa.h"
#include "common_headers.h" 
#include "shader.h"       //added for opengl extensions
#include "LuaSystem.h"
using namespace glm;
using namespace std;

GLuint myVBO;
sf::Clock* m_clock;
GLuint programID;
GLuint vertexbuffer;
GLuint VertexArrayID;

std::map<std::string, GameObject*> objects;
GameObject* ActiveObject;

void draw(sf::Window & window)
{
	//std::cout << "Drawing!" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto iterator = objects.begin(); iterator != objects.end(); iterator++)
		{
		iterator->second->draw(window);
		}
	window.display();
}

void keypress(sf::Window & window, sf::Event & event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Escape:
		window.close();
		break;

	default:
		break;
	}
}

void update(sf::Window & window, sf::Time delta_time)
{
	sf::Event event;
	/*while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			keypress(window, event);
			break;
		}
	}*/
	ActiveObject->event(window);
	for (auto iterator = objects.begin(); iterator != objects.end(); iterator++)
	{
		iterator->second->update(delta_time);
	}
}



int main()
{
	L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dostring(L, "function get_value(value) return settings[value] end");
	luaL_dofile(L, "settings.ini");
	//luaL_dostring(L, "print(resx)");
	unsigned int resx = GetLuaInt("resx");
	unsigned int resy = GetLuaInt("resy");
	sf::ContextSettings settings;
	settings.depthBits = GetLuaInt("txt");
	settings.stencilBits = GetLuaInt("stncl");
	settings.antialiasingLevel = GetLuaInt("aa");
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	/*std::cout << GetLuaInt("txt") << endl;
	std::cout << "OpenGL: " << settings.majorVersion << "." << settings.minorVersion << endl;
	std::cout << "AA: " << settings.antialiasingLevel << endl;
	std::cout << "Texture quality: " << settings.depthBits << "-bit" << endl;
	std::cout << "Stencil quality: " << settings.stencilBits << "-bit" << endl;
	std::cout << "Resolution: " << resx << "x" << resy << endl;*/
	if (GetLuaBool("flscrn"))
		window.create(sf::VideoMode(resx, resy), "OpenGL", sf::Style::Fullscreen, settings);
	else
		window.create(sf::VideoMode(resx, resy), "OpenGL", sf::Style::Default, settings);
	m_clock = new sf::Clock();
	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	window.setActive(true);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	//loadData();
	// Create and compile our GLSL program from the shaders
	while (window.isOpen())
	{
		update(window, m_clock->restart());
		draw(window);
	}
	glDeleteBuffers(1, &myVBO);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);
	lua_close(L);
	return 0;
}