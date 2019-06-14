#pragma once
#include "Enemy.h"


class EEagle : public Enemy
{
public:
	EEagle(float spawnX, float spawnY);
	~EEagle() {};
	float delayTime;
	float activeDistance;
	void UpdatePosition(float dt);
	virtual void Update(float dt);
	void DetectGround(unordered_set<Rect*> grounds) {}
	void ChangeState(State StateName);
};
