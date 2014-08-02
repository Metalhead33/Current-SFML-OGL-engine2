#include "GameObject.h"
#include <SFML/System.hpp>

void GameObject::draw()
{
	if (!model.get_bLoaded())return;
	glBindVertexArray(model.get_uiVAO());
	texture.BindTexture();
	glDrawArrays(GL_TRIANGLES, 0, model.getPolygonCount() * 3);
}
void GameObject::update(sf::Time delta_time)
{
	;
}
void GameObject::event(sf::Event event)
{
	;
}

GameObject::GameObject(const char* modell_path, const char* mti_path, const char* texture_path)
: texture(texture_path)
{
	model.loadModel(modell_path, mti_path);
}

GameObject::GameObject()
: texture(1, 1)
{
	;
}


GameObject::~GameObject()
{
	;
}
