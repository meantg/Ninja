#pragma once
#include "Enemy.h"

class EEagle : public Enemy
{
public:
	EEagle(float spawnX, float spawnY);
	~EEagle() {};
	void UpdatePosition(float dt);
	virtual void Update(float dt);
};
