#include <SFML/Graphics.hpp>
#include <iostream>

class PlayerObject
{
public:
	PlayerObject(int num, float x, float y, float xpos, float ypos); //Id, size, and pos

	void movePlayer();
	void show(sf::RenderWindow& mWindow);

private:
	sf::RectangleShape player;
	int playerid;
	void checkBoundaries();
};
