#include "Object.h"

Object::Object(int num, float x, float y, float xpos, float ypos) : object (sf::Vector2f(x, y)), id(num)
{
	object.setPosition(xpos, ypos);
}

Object::~Object()
{

}

void Object::show(sf::RenderWindow& mWindow)
{
	mWindow.draw(object);
}

void Object::move()
{

}
