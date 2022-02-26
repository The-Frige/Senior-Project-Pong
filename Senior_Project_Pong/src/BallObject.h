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

private:
	//sf::FloatRect ballrect;
	void borderReflect();
	void paddleReflect(PlayerObject& p);
	float speedx = 5.5f;
	float speedy = 5.5f;
	float angle = 0.45f;
};


