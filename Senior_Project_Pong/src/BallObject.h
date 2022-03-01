#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerObject.h"
#include "Object.h"
#include <cmath>


class BallObject : public Object{
public:
	using Object::Object;

	void show(sf::RenderWindow& mWindow);
	void move(PlayerObject& player1, PlayerObject& player2);
	void setAngle();
	void createBoundaries();
private:
	sf::FloatRect ballrect;
	void borderReflect();
	void paddleReflect(PlayerObject& p);
	void scoring();

	float speedx = 6.5f;
	float speedy = 6.5f;
	float angle = 120;
	int count;
};


