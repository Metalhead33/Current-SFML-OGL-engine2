#include "GameMode.h"


void GameMode::keypress()
{
	switch (event.key.code)
	{
	case sf::Keyboard::Escape:
		window->close();
		break;
	default:
		break;
	}
}
void GameMode::keyrelease()
{
	switch (event.key.code)
	{
	default:
		break;
	}
}
void GameMode::update()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			keypress();
			break;
		case sf::Event::KeyReleased:
			keyrelease();
			break;
		}
		ActiveObject->event(event);
	}
}

void GameMode::cleanup()
{
	;
}

GameMode::GameMode()
{
}

GameMode::~GameMode()
{
}
