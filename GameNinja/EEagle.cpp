#include "EEagle.h"

EEagle::EEagle(float spawnX, float spawnY)
{
	this->type = E_GUNMAN;
	this->_state = STANDING;
	this->AddAnimation(E_EAGLE, STANDING);
	this->AddAnimation(E_EAGLE, RUNNING);
	this->AddAnimation(E_EAGLE, DEAD);

	this->width = ENEMY_EAGLE_WIDTH;
	this->height = ENEMY_EAGLE_HEIGHT;
	this->speed = ENEMY_EAGLE_SPEED;

	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;
}

void EEagle::UpdatePosition(float dt)
{
	this->isReverse = false;

	this->x += vx * dt;
	this->y += vy * dt;
	this->dx = vx * dt;
	this->dy = vy * dt;
}

void EEagle::Update(float dt)
{
	Enemy::Update(dt);
	if (isActive == true && isAttacked == false)
	{
		if (isReverse == true)
		{
			vx = -ENEMY_EAGLE_SPEED;
		}
		else
			vx = ENEMY_EAGLE_SPEED;
		ChangeState(RUNNING);
	}
	else if(isAttacked == true) 
		ChangeState(DEAD);
}
