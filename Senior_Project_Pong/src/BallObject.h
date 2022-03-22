#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerObject.h"
#include "Object.h"
#include "ScoreObject.h"

#include <cmath>


class BallObject : public Object { //Inherits the object base class. Could be rewritten to not need it however
public:
	using Object::Object; //To inherit the object constructor

	void show(sf::RenderWindow& mWindow);
	void move(PlayerObject& player1, PlayerObject& player2, ScoreObject& score1, ScoreObject& score2);
	void player1Move(PlayerObject& player1, ScoreObject& score2);
	void setAngle();
	void createBoundaries();
	void displayScore(); // Debug function
	void stopBall(); //Debug
	void resumeBall(); //Debug
	void resetScore(ScoreObject& s1, ScoreObject& s2); /* Objects referenced by address because otherwise program won't work
	I think its because of the pointer needed to change the texture.
	*/

private:
	sf::FloatRect ballrect;
	int p_score1 = 0;
	int p_score2 = 0;
	void borderReflect();
	void paddleReflect(PlayerObject& p); //Needs a playerobject for collision. Because it doesn't directly change a value I could pass by value.
	void scoring(ScoreObject& s1, ScoreObject& s2); //Uses scoreobject reference since pointer is needed to change textures
	void player1Scoring(ScoreObject& s2); // Same function as above for singleplayer mode

	float speedx = 6.5f; //set to 6.5
	float speedy = 6.5f; //set to 6.5
	float angle = 100;
	int count;
};


