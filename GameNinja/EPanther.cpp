#include "EPanther.h"

EPanther::EPanther(float spawnX, float spawnY)
{
	this->tag = ENEMY;
	this->type = E_PANTHER;
	this->_state = STANDING;
	this->AddAnimation(E_PANTHER, STANDING);
	this->AddAnimation(E_PANTHER, RUNNING);
	this->AddAnimation(E_PANTHER, DEAD);

	this->width = ENEMY_PANTHER_WIDTH;
	this->height = ENEMY_PANTHER_HEIGHT;
	this->speed = ENEMY_PANTHER_SPEED;

	this->vy = 0;
	this->vx = speed;
	this->x = spawnX;
	this->spawnX = x;
	this->y = spawnY;
	this->ChangeState(RUNNING);
}

void EPanther::UpdatePosition(float dt)
{
	this->isReverse = false;

	this->x += vx * dt;
	this->y += vy * dt;
	this->dx = vx * dt;
	this->dy = vy * dt;
}

void EPanther::Update(float dt)
{
	Enemy::Update(dt);
	if (isActive == true && isAttacked == false)
	{
		if (isReverse == true)
		{
			vx = -ENEMY_PANTHER_SPEED;
		}
		else
			vx = ENEMY_PANTHER_SPEED;
		ChangeState(RUNNING);
	}
	else
		ChangeState(DEAD);
}