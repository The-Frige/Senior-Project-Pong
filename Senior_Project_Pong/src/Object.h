#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Object { //This is the base class for the ball object and originally the other objects.
public: //I only used this for the ball object however because I quickly realised that other objects would deviate too much from the base class to use this
	Object(int num, float x, float y, float xpos, float ypos);
	virtual ~Object();
	virtual void show(sf::RenderWindow& mWindow);
	virtual void move();

protected:
	sf::SoundBuffer buffer; //These sound variables are just for the ball.
	sf::Sound scoresound;
	sf::RectangleShape object;
	int id;
};


