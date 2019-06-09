#pragma once
#include "Game.h"

class ScoreBoard
{
private:
	//static ScoreBoard* _instance;
public:
	ScoreBoard();
	~ScoreBoard();

	int time, score, health, mana;

	//static ScoreBoard* GetInstance();
	void Render();
	void Update(float dt);
};