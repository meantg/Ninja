#include "CloakManBullet.h"

CloakManBullet::CloakManBullet()
{
	this->type = E_CLOAKMAN;

	this->activeAnimation = AnimationManager::GetInstance()->Get(E_CLOAKMAN, ATK_WITH_WEAPON);
	this->isActive = true;
	this->vx = BULLET_CLOAKMAN_SPEED;
	this->vy = BULLET_CLOAKMAN_JUMPING_SPEED;
	this->width = BULLET_CLOAKMAN_WIDTH;
	this->height = BULLET_CLOAKMAN_HEIGHT;

}

void CloakManBullet::UpdateDistance(float dt)
{
	vy -= 0.1f;
	if (vy <= 0)
	{
		vy = -BULLET_CLOAKMAN_FALLING_SPEED;
	}
	//if (y < 0)
	//	delete this;
	x += vx * dt;
	y += vy * dt;
	dx = vx * dt;
	dy = vy * dt;
}




