#include "CloakManBullet.h"

CloakManBullet::CloakManBullet()
{
	this->type = E_CLOAKMAN;

	this->activeAnimation = AnimationManager::GetInstance()->Get(E_CLOAKMAN, ATK_WITH_WEAPON);

	this->vx = BULLET_CLOAKMAN_SPEED;
	this->vy = BULLET_CLOAKMAN_JUMPING_SPEED;
	this->width = BULLET_CLOAKMAN_WIDTH;
	this->height = BULLET_CLOAKMAN_HEIGHT;

}

void CloakManBullet::UpdateDistance(float dt)
{
	vy -= 0.2f;
	//if (vy <= 0)
	//{
	//	vy = -BULLET_CLOAKMAN_FALLING_SPEED;
	//}
	dx = vx * dt;
	dy = vy * dt;
}




