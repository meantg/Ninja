#pragma once
#include "Weapon.h"

class FireWheel : public Weapon
{
	FireWheel()
	{
		width = WEAPON_FIREWHEEL_WIDTH;
		height = WEAPON_FIREWHEEL_HEIGHT;
		vx = WEAPON_FIREWHEEL_SPEED;
		vy = 0;
		weapontype = FIREWHEEL;
	}

	void UpdateDistance(float dt)
	{
		this->dx = vx * dt;
		this->dy = vy * dt;
	}
};