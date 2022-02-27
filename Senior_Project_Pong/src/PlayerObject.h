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
	void createBoundaries();
private:
	sf::RectangleShape player;
	sf::FloatRect part1;
	sf::FloatRect part2;
	sf::FloatRect part3;
	int playerid;
	void checkBoundaries();

};
