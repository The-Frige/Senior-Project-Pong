#include "BallObject.h"

void BallObject::setAngle()
{
	srand(time(0));
	if (count == 0)
	{
		angle = ((rand() % 360 + 1));
		count++;
	}
}

void BallObject::move(PlayerObject& player1, PlayerObject& player2) //set to 4.5f for both x and y
{
	count = 0;
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

	if(ballrect.intersects(p.part1))
	{
		if(p.playerid == 1)//p.player.getGlobalBounds().top - object.getGlobalBounds().width/2 -1
		{
			angle = 360 - (rand() % 30+1);
			object.setPosition(p.player.getPosition().x -10.0f , object.getPosition().y);
			std:: cout << "Touching paddle part 1" << std::endl;
		}
		else if (p.playerid == 0)
		{
			angle = 360 -  (rand() % 30+1);
			object.setPosition(p.player.getPosition().x +10.0f , object.getPosition().y);
			std::cout << "Touching paddle part 1" << std::endl;
		}

	}
	else if (ballrect.intersects(p.part2))
	{
		if(p.playerid == 1)//p.player.getGlobalBounds().top - object.getGlobalBounds().width/2 -1
		{
			angle = 360 - (rand() % 60 + 1);
			object.setPosition(p.player.getPosition().x -10.0f , object.getPosition().y);
			std:: cout << "Touching paddle part 2" << std::endl;
		}
		else if (p.playerid == 0)
		{
			angle = 360 - (rand() % 60 + 1);
			object.setPosition(p.player.getPosition().x +10.0f , object.getPosition().y);
			std::cout << "Touching paddle part 2" << std::endl;
		}

	}
	else if (ballrect.intersects(p.part3))
	{
		if(p.playerid == 1)//p.player.getGlobalBounds().top - object.getGlobalBounds().width/2 -1
		{
			angle = 360 - (rand() % 90+1);
			object.setPosition(p.player.getPosition().x -10.0f , object.getPosition().y);
			std:: cout << "Touching paddle part 3" << std::endl;
		}
		else if (p.playerid == 0)
		{
			angle = 360 - (rand() % 90+1);
			object.setPosition(p.player.getPosition().x +10.0f , object.getPosition().y);
			std::cout << "Touching paddle part 3" << std::endl;
		}

	}


}

void BallObject::createBoundaries()
{
	ballrect = object.getGlobalBounds();
}
