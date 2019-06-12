#pragma once
#include "Enemy.h"

class ECloakMan : public Enemy
{
private:
	float delayTime;
public:
	ECloakMan(float spawnX, float spawnY);
	void UpdatePosition(float dt);
	void Update(float dt);
};