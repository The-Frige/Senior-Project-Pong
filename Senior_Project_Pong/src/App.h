#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerObject.h"

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
	PlayerObject player1 { 0, 10.0f, 75.0f, 30.0f, 75.0f };
	PlayerObject player2 { 1, 10.0f, 75.0f, 760.0f, 75.0f };

	enum GameState { NotStarted, Singleplayer, Multiplayer };

	static GameState gamestate;

};
