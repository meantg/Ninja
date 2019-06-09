#include "ESwordMan.h"

ESwordMan::ESwordMan(float spawnX, float spawnY)
{
	this->_state = STANDING;
	this->AddAnimation(E_SWORDMAN, STANDING);
	this->AddAnimation(E_SWORDMAN, RUNNING);
	this->AddAnimation(E_SWORDMAN, DEAD);
	this->width = ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->speed = ENEMY_SWORDMAN_SPEED;
	this->vx = speed;
	this->x = spawnX;
	this->spawnX = x;
	this->y = spawnY;
	this->ChangeState(STANDING);
}

void ESwordMan::UpdatePosition(float dt)
{
	if (Player::GetInstance()->x - this->x < 0)
		this->isReverse = true;
	else
		this->isReverse = false;
	this->x += vx * dt;
	dx += vx * dt;
	dy += vy * dt;
}

void ESwordMan::Update(float dt)
{
	Enemy::Update(dt);
	if (isActive == true)
	{
		ChangeState(RUNNING);
		if (isReverse == true)
		{
			vx = -0.02f;
		}
		else
			vx = 0.02f;
	}
}

