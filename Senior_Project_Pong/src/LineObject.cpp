
#include "LineObject.h"

LineObject::LineObject() {
	sprite.setPosition(400.0f, 0.0f);
	textures.load(4, "middle.png");
	sprite.setTexture(textures.get(4));
}

void LineObject::show(sf::RenderWindow& mWindow)
{
	mWindow.draw(sprite);
}




