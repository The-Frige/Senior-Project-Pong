#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include "PlayerObject.h"
#include "BallObject.h"
#include "ScoreObject.h"

class App
{
public:
	App();
	void run();

private:
	void processWindowEvents();

	void render();
	//void handleInput(sf::Keyboard::Key key);

	sf::RenderWindow mWindow;
	PlayerObject player1{ 0, 10.0f, 75.0f, 30.0f, 75.0f };
	PlayerObject player2{ 1, 10.0f, 75.0f, 760.0f, 75.0f };
	BallObject ball{ 2, 10.0f, 10.0f, 400.0f, 300.0f };
	ScoreObject player1score{ 150.0f, 0.0f };
	ScoreObject player2score{ 450.0f, 0.0f };

	enum GameState { NotStarted, Singleplayer, Multiplayer};

	static GameState gamestate;

};
