#pragma once
#include "Enemy.h"

class IHButterfly : public Enemy
{
public:
	IHButterfly(float spawnX, float spawnY);
	void DetectGround(unordered_set<Rect*> grounds) {}
	~IHButterfly() {};
};