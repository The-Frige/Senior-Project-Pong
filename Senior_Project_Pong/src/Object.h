#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Object {
public:
	Object(int num, float x, float y, float xpos, float ypos);
	virtual ~Object();
	virtual void show(sf::RenderWindow& mWindow);
	virtual void move();

protected:
	sf::SoundBuffer buffer;
	sf::Sound scoresound;
	sf::RectangleShape object;
	int id;
};


