#include "BallObject.h"


void BallObject::move(PlayerObject& player1, PlayerObject& player2) //set to 4.5f for both x and y
{

	object.move(speedx * cos(angle), speedy * sin(angle));
	paddleReflect(player1);
	paddleReflect(player2);
	borderReflect();
}

void BallObject::show(sf::RenderWindow& mWindow)
{
	mWindow.draw(object);
}

void BallObject::borderReflect()
{
	if (object.getPosition().y <= 0.0f)
	{
		//ball.rotate(175.0f);
		speedy = -speedy;
		std::cout << "Touching edges" << std::endl;
	}
	else if (object.getPosition().y >= 600.0f)
	{
		//ball.rotate(150.0f);
		speedy = -speedy;
		std::cout << "Touching edges" << std::endl;
	}

}

void BallObject::paddleReflect(PlayerObject& p) //Figure out proper bouncing
{
	if (object.getGlobalBounds().intersects(p.player.getGlobalBounds()))
	{
		srand(time(0));
		angle = 180;
		object.setPosition(object.getPosition().x, p.player.getGlobalBounds().top - object.getGlobalBounds().width/2 -1);
		std::cout << "Touching paddle" << std::endl;
	}
}
