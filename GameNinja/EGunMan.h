#pragma once
#include "Enemy.h"

class EGunMan : public Enemy
{
private:
	float delayTime;
public:
	EGunMan(float spawnX, float spawnY);
	~EGunMan() {};
	void UpdatePosition(float dt);
	virtual void Update(float dt);
};