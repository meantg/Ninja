#include "ESwordMan.h"

ESwordMan::ESwordMan()
{
	this->_state = STANDING;
	this->AddAnimation(E_SWORDMAN, STANDING);
	this->AddAnimation(E_SWORDMAN, RUNNING);
	this->AddAnimation(E_SWORDMAN, DEAD);
	this->width = ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->speed = ENEMY_SWORDMAN_SPEED;
	this->x = 200.0f;
	this->spawnX = x;
	this->y = 60.0f;
	this->vx = 0.02f;
}

void ESwordMan::UpdatePosition(float dt)
{
	if (Player::GetInstance()->x - this->x < 0)
		this->isReverse = true;
	else
		this->isReverse = false;
	this->x += vx * dt;
}

void ESwordMan::Update(float dt)
{
	Enemy::Update(dt);
	if (isActive == true)
		if (isReverse == true)
		{
			vx = -0.02f;
		}
		else 
			vx = 0.02f;
		_state = RUNNING;
}

