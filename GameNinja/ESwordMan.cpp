#include "ESwordMan.h"

ESwordMan::ESwordMan(float spawnX, float spawnY)
{
	this->type = E_SWORDMAN;
	this->_state = STANDING;
	this->AddAnimation(E_SWORDMAN, STANDING);
	this->AddAnimation(E_SWORDMAN, RUNNING);
	this->AddAnimation(E_SWORDMAN, DEAD);

	this->width =ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->speed = ENEMY_SWORDMAN_SPEED;

	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;
}

void ESwordMan::UpdatePosition(float dt)
{
	this->dx = vx * dt;

	if (vx > 0 && this->x + (this->width >> 1) >= groundBound.x + groundBound.width)
	{
		this->vx = -vx;
		this->isReverse = true;
	}
	else if (vx < 0 && this->x - (this->width >> 1) <= groundBound.x)
	{
		this->vx = -vx;
		this->isReverse = false;
	}
}


