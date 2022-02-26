#pragma once
#include <SFML/Graphics.hpp>

class Object {
public:
	Object(int num, float x, float y, float xpos, float ypos);
	virtual ~Object();
	virtual void show(sf::RenderWindow& mWindow);
	virtual void move();

protected:
	sf::RectangleShape object;
	int id;
};


