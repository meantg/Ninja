#pragma once
#include "Enemy.h"

class EPanther : public Enemy
{
public :
	float activeDistance;
	EPanther(float spawnX, float spawnY, bool isReverse);
	bool isOnGround;
	Rect curGroundBound;
	~EPanther() {};
	void DetectGround(unordered_set<Rect*> grounds);
	void DetectCurGround(unordered_set<Rect*> grounds);
	void UpdatePosition(float dt);
	void ChangeState(State StateName);
};