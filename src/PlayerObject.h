#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#pragma once

class PlayerObject
{
public:
	PlayerObject(int num, float x, float y, float xpos, float ypos);

	friend class BallObject;
	void move();
	void show(sf::RenderWindow& mWindow);

private:
	sf::RectangleShape player;
	//sf::FloatRect rect;
	int playerid;
	void checkBoundaries();
};
