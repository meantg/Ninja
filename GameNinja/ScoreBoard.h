#pragma once

#include "Game.h"

class ScoreBoard
{
private:
	static ScoreBoard* _instance;
public:
	ScoreBoard();
	~ScoreBoard();
	static ScoreBoard* GetInstance();
	int time, score, health, mana;
	float curTime ;

	void Render();
	void Update(float dt);
};