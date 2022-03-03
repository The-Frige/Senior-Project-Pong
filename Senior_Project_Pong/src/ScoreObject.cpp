#include "ScoreObject.h"

ScoreObject::ScoreObject(float xpos, float ypos)
{
	sprite.setPosition(xpos, ypos);
	textures.load(0, "score0.png");
	textures.load(1, "score1.jpeg");
	textures.load(2, "score2.jpeg");
	textures.load(3, "score3.jpeg");
	sprite.setTexture(textures.get(0));
}

void ScoreObject::show(sf::RenderWindow& mWindow)
{
	mWindow.draw(sprite);
}

void ScoreObject::updateScore(int id)
{
	switch(id)
	{
	case 0:
		sprite.setTexture(textures.get(0));
		break;
	case 1:
		sprite.setTexture(textures.get(1));
		break;
	case 2:
		sprite.setTexture(textures.get(2));
		break;
	case 3:
		sprite.setTexture(textures.get(3));
		break;
	default:
		break;
	}
}
