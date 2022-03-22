#include "Object.h"

Object::Object(int num, float x, float y, float xpos, float ypos) : object (sf::Vector2f(x, y)), id(num)
{
	object.setPosition(xpos, ypos);
	if(!buffer.loadFromFile("Score.wav")) //Loads a sound file for scoring
			std::cout << "File not found!" << std::endl;
	scoresound.setBuffer(buffer);
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
