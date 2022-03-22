#pragma once
#include <iostream>
#include "TextureLoader.h"
#include <SFML/Graphics.hpp>

class LineObject { //This is just an object class that puts the middle line down in pong.
public:
	LineObject();
	void show(sf::RenderWindow& mWindow);

private:
	sf::Sprite sprite;
	TextureLoader textures;
};

