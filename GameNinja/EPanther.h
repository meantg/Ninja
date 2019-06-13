#pragma once
#include "Enemy.h"

class EPanther : public Enemy
{
public :
	EPanther(float spawnX, float spawnY);
	~EPanther() {};
	void UpdatePosition(float dt);
	virtual void Update(float dt);
};