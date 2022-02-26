#include "PlayerObject.h"

PlayerObject::PlayerObject(int num, float x, float y, float xpos, float ypos) : player(sf::Vector2f(x, y)), playerid(num)
{
	player.setPosition(xpos, ypos);
}

void PlayerObject::move()
{
	if(playerid == 0)
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
	else if(playerid == 1) //Disable if gamestate is set to single player
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

void PlayerObject::checkBoundaries()
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
