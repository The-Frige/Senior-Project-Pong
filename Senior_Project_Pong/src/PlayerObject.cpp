#include "PlayerObject.h"

PlayerObject::PlayerObject(int num, float x, float y, float xpos, float ypos) : player(sf::Vector2f(x, y)), playerid(num)
{
	player.setPosition(xpos, ypos);

}

void PlayerObject::move() //Player ids are there to determine which paddle takes what key
{
	if(playerid == 0) //player 1
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0.0f, -7.5f);
			checkBoundaries();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0.0f, 7.5f);
			checkBoundaries();
		}
	}
	else if(playerid == 1) //Disable if gamestate is set to single player. also player 2
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.move(0.0f, -7.5f);
			checkBoundaries();
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.move(0.0f, 7.5f);
			checkBoundaries();
		}
	}
	/*Debug test to see cordinate output
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		std::cout << player.getPosition().y << std::endl;
	}
	*/


	//Need to put collision later

}

void PlayerObject::show(sf::RenderWindow& mWindow)
{
	mWindow.draw(player);
}

void PlayerObject::checkBoundaries() //Makes sure the paddle doesn't go off screen
{
	if(player.getPosition().y <= -1.0f)
	{
		player.move(0.0f, 7.5f);
		//std::cout << "touching" << std::endl;
	}
	else if(player.getPosition().y >= 530.0f)
	{
		player.move(0.0f, -7.5f);
	}

}

void PlayerObject::createBoundaries() //Creates the collision for the paddle
{
	part1.top = player.getGlobalBounds().top;
	part1.left = player.getGlobalBounds().left;
	part1.height = player.getGlobalBounds().height/3;
	part1.width = player.getGlobalBounds().width;

	part2.top = part1.top + 25.0f;
	part2.left = player.getGlobalBounds().left;
	part2.height = 25.0f;
	part2.width = 10.0f;

	part3.top = part2.top + 25.0f;
	part3.left = player.getGlobalBounds().left;
	part3.height = 25.0f;
	part3.width = 10.0f;

}
