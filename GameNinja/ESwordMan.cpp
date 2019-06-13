#include "ESwordMan.h"

ESwordMan::ESwordMan(float spawnX, float spawnY)
{
	this->tag = ENEMY;
	this->type = E_SWORDMAN;
	this->_state = STANDING;
	this->AddAnimation(E_SWORDMAN, STANDING);
	this->AddAnimation(E_SWORDMAN, RUNNING);
	this->AddAnimation(E_SWORDMAN, DEAD);

	this->width =ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->speed = ENEMY_SWORDMAN_SPEED;

	this->vy = 0;
	this->vx = speed;
	this->x = spawnX;
	this->spawnX = x;
	this->y = spawnY;
	this->ChangeState(RUNNING);
}

void ESwordMan::UpdatePosition(float dt)
{
		this->isReverse = true;

	this->x += vx * dt;
	this->y += vy * dt;
	this->dx = vx * dt;
	this->dy = vy * dt;
}

void ESwordMan::Update(float dt)
{
	Enemy::Update(dt);
	if (isActive == true && isAttacked == false)
	{
		ChangeState(RUNNING);
		if (isReverse == true)
		{
			vx = -ENEMY_SWORDMAN_SPEED;
		}
	}
	else 
		ChangeState(DEAD);
}

