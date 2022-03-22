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

void BallObject::move(PlayerObject& player1, PlayerObject& player2, ScoreObject& score1, ScoreObject& score2) //set to 4.5f for both x and y
{
	count = 0;
	object.move(speedx * cos(angle), speedy * sin(angle)); // Using trig to calculate the ball angle
	paddleReflect(player1);
	paddleReflect(player2);
	borderReflect();
	scoring(score1, score2);
}

void BallObject::player1Move(PlayerObject& player1, ScoreObject& score2) //Same as above function for singleplayer
{
	count = 0;
	object.move(speedx * cos(angle), speedy * sin(angle));
	paddleReflect(player1);
	borderReflect();
	player1Scoring(score2);
}

void BallObject::show(sf::RenderWindow& mWindow)
{
	mWindow.draw(object);
}

void BallObject::createBoundaries() //Creates collision for ball
{
	ballrect = object.getGlobalBounds();
}

void BallObject::displayScore() //Debug function that outputs score to console
{
	std::cout << p_score1 << std::endl;
	std::cout << p_score2 << std::endl;
}

void BallObject::stopBall()
{
	speedx = 0.0f;
	speedy = 0.0f;
}

void BallObject::resumeBall()
{
	speedx = 6.5f;
	speedy = 6.5f;
}

void BallObject::resetScore(ScoreObject& s1, ScoreObject& s2)
{
	p_score1 = 0;
	p_score2 = 0;
	s1.updateScore(p_score1);
	s2.updateScore(p_score2);
}

void BallObject::borderReflect() //Bounces the ball when it hits the border
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

void BallObject::paddleReflect(PlayerObject& p) //Reflects the ball when hitting a paddle
{

	if(ballrect.intersects(p.part1)) //I had the bounding boxes(collision) of the paddles divided into three parts to make the ball reflection more randomized
	{
		if(p.playerid == 1) //The player ids are for the sake of making sure the ball bounces back the correct direction.
		{
			angle = 360 - (rand() % 30+1);
			object.setPosition(p.player.getPosition().x -10.0f , object.getPosition().y); //Makes sure the ball doesn't get stuck in the paddle.
			std:: cout << "Touching paddle part 1" << std::endl;
		}
		else if (p.playerid == 0) //Ditto
		{
			angle = 360 -  (rand() % 30+1);
			object.setPosition(p.player.getPosition().x +10.0f , object.getPosition().y); //Ditto
			std::cout << "Touching paddle part 1" << std::endl;
		}

	}
	else if (ballrect.intersects(p.part2))
	{
		if(p.playerid == 1)//Ditto
		{
			angle = 360 - (rand() % 60 + 1);
			object.setPosition(p.player.getPosition().x -10.0f , object.getPosition().y); //Look at comment at the first mention of this function for what it does.
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

void BallObject::scoring(ScoreObject& s1, ScoreObject& s2)
{
	if (object.getPosition().x <= 0.0f) //Collision to see if ball hits the left side of the screen for scoring
	{
		object.setPosition(400.0f, 300.0f);
		scoresound.play();
		std::cout << "Score!" << std::endl;
		sf::sleep(sf::seconds(3.0f));
		p_score2++;
		s2.updateScore(p_score2);
		if(p_score1 == 3 || p_score2 == 3)
		{
			stopBall();
		}

	}
	else if (object.getPosition().x >= 800.0f) //Collision to see if ball hits the left side of the screen for scoring
	{
		object.setPosition(400.0f, 300.0f);
		scoresound.play();
		std::cout << "Score!" << std::endl;
		sf::sleep(sf::seconds(3.0f));
		p_score1++;
		s1.updateScore(p_score1);
		if(p_score1 == 3 || p_score2 == 3)
		{
			stopBall();
		}
	}
}

void BallObject::player1Scoring(ScoreObject& s2) //Same scoring function as above except for singleplayer. Only scores for left side. Right side gets bounced back
{
	if (object.getPosition().x <= 0.0f)
	{
		object.setPosition(400.0f, 300.0f);
		scoresound.play();
		std::cout << "Score!" << std::endl;
		sf::sleep(sf::seconds(3.0f));
		p_score2++;
		s2.updateScore(p_score2);
		if(p_score1 == 3 || p_score2 == 3)
		{
			stopBall();
		}
	}
	else if (object.getPosition().x >= 800.0f)
	{
		speedx = -speedx;
		std::cout << "Touching edges" << std::endl;
	}
}


