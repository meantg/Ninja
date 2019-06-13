#pragma once
#include "Bullet.h"

class CloakManBullet : public Bullet
{
private:
	float delay;
public:
	CloakManBullet();
	void UpdateDistance(float dt);
};