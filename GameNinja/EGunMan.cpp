#include "EGunMan.h"

EGunMan::EGunMan(float spawnX, float spawnY)
{
	this->type = E_GUNMAN;
	this->_state = STANDING;
	this->AddAnimation(E_GUNMAN, STANDING);
	this->AddAnimation(E_GUNMAN, RUNNING);
	this->AddAnimation(E_GUNMAN, ATTACKING);
	this->AddAnimation(E_GUNMAN, DEAD);

	this->width = ENEMY_GUNMAN_WIDTH;
	this->height = ENEMY_GUNMAN_HEIGHT;
	this->speed = ENEMY_GUNMAN_SPEED;

	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;
}

void EGunMan::UpdatePosition(float dt)
{
	delayTime -= dt * 100;
	if (player->x - this->x < 0)
		this->isReverse = true;
	else
		this->isReverse = false;
	if (_state == RUNNING)
	{
		this->dx = vx * dt;
		if (x > 1383)
		{
			x = 1383;
			vx = -ENEMY_CLOAKMAN_SPEED;
		}
		else if (x < 1363)
		{
			x = 1363;
			vx = ENEMY_CLOAKMAN_SPEED;
		}
		if (delayTime <= 0)
		{
			ChangeState(ATTACKING);
			this->vx = -vx;
			delayTime = ENEMY_CLOAKMAN_DELAY;
		}
	}
	if (_state == ATTACKING)
	{
		this->dx = 0;
		if (x > 1283)
		{
			x = 1283;
			vx = -ENEMY_CLOAKMAN_SPEED;
		}
		else if (x < 1363)
		{
			x = 1363;
			vx = ENEMY_CLOAKMAN_SPEED;
		}
	}
	x += vx * dt;
}

void EGunMan::Update(float dt)
{
	Enemy::Update(dt);
	if (abs(player->x - this->x) <= 130)
	{
		if (abs(player->x - this->x) <= 60)
		{
			if (isActive == true && isAttacked == false)
			{
				ChangeState(ATTACKING);
			}
			else if (isAttacked == true)
				ChangeState(DEAD);
		}
		else
		{
			ChangeState(RUNNING);
			isAttacked = false;
		}
	}
}
