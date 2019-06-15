#include "GunManBullet.h"

GunManBullet::GunManBullet()
{
	this->type = E_GUNMAN;

	this->activeAnimation = AnimationManager::GetInstance()->Get(E_GUNMAN, ATK_WITH_WEAPON);
	this->vx = BULLET_GUNMAN_SPEED;
	this->vy = 0;
	this->width = BULLET_GUNMAN_WIDTH;
	this->height = BULLET_GUNMAN_HEIGHT;
}

void GunManBullet::UpdateDistance(float dt)
{
	dx = vx * dt;
}
