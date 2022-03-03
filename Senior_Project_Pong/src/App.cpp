#include "App.h"

App::GameState App::gamestate = Multiplayer;
App::App() : mWindow(sf::VideoMode(800, 600), "Pong")
{
	mWindow.setFramerateLimit(60);
	//ball.setAngle();
}

void App::run()
{
	while (mWindow.isOpen())
	{
		processWindowEvents();
		player1.move();
		player1.createBoundaries();
		player2.move();
		player2.createBoundaries();
		ball.move(player1, player2, player1score, player2score);
		ball.createBoundaries();
		render();
	}
}

void App::processWindowEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::Escape)
			{
				mWindow.close();
				break;
			}
			else if (event.key.code == sf::Keyboard::P)
			{
				ball.stopBall();
				break;
			}
			else if (event.key.code == sf::Keyboard::R)
			{
				ball.resumeBall();
				break;
			}
			else if (event.key.code == sf::Keyboard::V)
			{
				ball.displayScore();
				break;
			}
			else if (event.key.code == sf::Keyboard::M)
			{
				ball.resetScore(player1score, player2score);
				break;
			}
			//handleInput(event.key.code);
			break;
		}
	}
}

/* not needed
void App::handleInput(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Escape)
	{
		mWindow.close();
	}
	/*
	else if (key == sf::Keyboard::E)
	{
		gamestate = App::Multiplayer;
	}
	else if (key == sf::Keyboard::P)
	{
		gamestate = App::NotStarted;
	}

}
*/

void App::render()
{
	if(gamestate == App::Multiplayer)
	{
		mWindow.clear(sf::Color::Black);
		player1.show(mWindow);
		player2.show(mWindow); //Disable if gamestate is set to singleplayer
		ball.show(mWindow);
		player1score.show(mWindow);
		player2score.show(mWindow);
		mWindow.display();
	}
	//Debug code to see if gamestates are working
	/*
	else if(gamestate == App::NotStarted)
	{
		mWindow.clear();
		mWindow.display();
	}
	*/
}
