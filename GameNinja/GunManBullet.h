#pragma once
#include "Bullet.h"

class GunManBullet : public Bullet
{
private:
	float delay;
public:
	GunManBullet();
	void UpdateDistance(float dt);
};