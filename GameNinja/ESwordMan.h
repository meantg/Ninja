#pragma once
#include "Enemy.h"
#include "EnemyBullet.h"

class ESwordMan : public Enemy
{
public:
	ESwordMan(float spawnX, float spawnY);
	~ESwordMan() {};
	void UpdatePosition(float dt);
	virtual void Update(float dt);
};