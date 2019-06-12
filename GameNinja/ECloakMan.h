#pragma once
#include "Enemy.h"

class ECloakMan : public Enemy
{
private:
	float bulletvx, bulletvy;
	float bulletx, bullety;
public:
	ECloakMan(float spawnX, float spawnY);
	~ECloakMan() {};
	void UpdatePosition(float dt);
	void Update(float dt);
};