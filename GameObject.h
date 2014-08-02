#pragma once
#include "common_headers.h"
#include "texture.h"
#include "objModel.h"
#include <SFML/Window.hpp>
//#include <SFML/System/Vector3.hpp>
class GameObject
{
public:
	void draw();
	void update(sf::Time delta_time);
	void event(sf::Event event);
	GameObject(const char* modell_path, const char* mti_path, const char* texture_path);
	GameObject();
	virtual ~GameObject();
	sf::Vector3<GLfloat> position;
protected:
	CTexture texture;
	CObjModel model;
	// modell/mesh palceholder
};

