#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerObject.h"
#include "Object.h"
#include "ScoreObject.h"

#include <cmath>


class BallObject : public Object {
public:
	using Object::Object;

	void show(sf::RenderWindow& mWindow);
	void move(PlayerObject& player1, PlayerObject& player2, ScoreObject& score1, ScoreObject& score2);
	void player1Move(PlayerObject& player1, ScoreObject& score2);
	void setAngle();
	void createBoundaries();
	void displayScore(); // Debug function
	void stopBall(); //Debug
	void resumeBall(); //Debug
	void resetScore(ScoreObject& s1, ScoreObject& s2);

private:
	sf::FloatRect ballrect;
	int p_score1 = 0;
	int p_score2 = 0;
	void borderReflect();
	void paddleReflect(PlayerObject& p);
	void scoring(ScoreObject& s1, ScoreObject& s2);
	void player1Scoring(ScoreObject& s2);

	float speedx = 6.5f; //set to 6.5
	float speedy = 6.5f; //set to 6.5
	float angle = 100;
	int count;
};


