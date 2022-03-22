#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include "PlayerObject.h"
#include "BallObject.h"
#include "ScoreObject.h"
#include "LineObject.h"

class App
{
public:
	App();
	void run();

private:
	void processWindowEvents();

	void render();
	//void handleInput(sf::Keyboard::Key key); Junk function need to delete later

	sf::RenderWindow mWindow;
	PlayerObject player1{ 0, 10.0f, 75.0f, 30.0f, 75.0f }; // Parameters: ID, width, height, x position, y position
	PlayerObject player2{ 1, 10.0f, 75.0f, 760.0f, 75.0f }; // Parameters: ID, width, height, x position, y position
	BallObject ball{ 2, 10.0f, 10.0f, 400.0f, 300.0f }; // Parameters: ID, width, height, x position, y position
	ScoreObject player1score{ 150.0f, 0.0f }; //Parameters: x position, y position
	ScoreObject player2score{ 450.0f, 0.0f }; //Parameters: x position, y position
	LineObject line; //Line that runs down the middle of the screen

	enum GameState { NotStarted, Singleplayer, Multiplayer}; //Gamestate to control whether the game is in singleplayer or multiplayer mode

	static GameState gamestate; //Made static so gamestate never gets destroyed. Although given how the app object only gets deleted when the program is closed static wouldn't exactly be necessary.

};
