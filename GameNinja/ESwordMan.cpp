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
	this->dy = vy * dt;
}

void ESwordMan::Update(float dt)
{
	Enemy::Update(dt);
	if (isActive == true && isAttacked == false)
	{
		if (isReverse == true)
		{
			vx = -ENEMY_SWORDMAN_SPEED;
		}
		else
			vx = ENEMY_SWORDMAN_SPEED;
		ChangeState(RUNNING);	
	}
	else if(isAttacked == true)
		ChangeState(DEAD);
}

