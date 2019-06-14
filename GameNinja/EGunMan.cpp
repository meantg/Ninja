#include "EGunMan.h"

EGunMan::EGunMan(float spawnX, float spawnY)
{
	this->type = E_GUNMAN;
	this->AddAnimation(E_GUNMAN, STANDING);
	this->AddAnimation(E_GUNMAN, RUNNING);
	this->AddAnimation(E_GUNMAN, ATTACKING);
	this->AddAnimation(E_GUNMAN, DEAD);

	this->width = ENEMY_GUNMAN_WIDTH;
	this->height = ENEMY_GUNMAN_HEIGHT;
	this->speed = ENEMY_GUNMAN_SPEED;
	this->score = ENEMY_GUNMAN_SCORE;
	this->bulletTotal = this->bulletCount = BULLET_GUNMAN_COUNT;
	this->delayTime = 900;
	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;
}

void EGunMan::UpdatePosition(float dt)
{
	this->isReverse = (player->x < this->x);
	delayTime -= dt*100;

	switch (this->_state)
	{
	case RUNNING:
	{
		this->dx = vx * dt;

		/*if ((vx > 0 && this->x + (this->width >> 1) >= groundBound.x + groundBound.width)
			|| (vx < 0 && this->x - (this->width >> 1) <= groundBound.x))
		{
			this->vx = -vx;
		}*/
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

		if (delayTime <= 0)
		{
			this->ChangeState(ATTACKING);
			this->vx = -vx;
			delayTime = 1800;
		}
		break;
	}
	case ATTACKING:
	{
		this->vx = 0;
		break;
	}
	}
}

void EGunMan::Update(float dt)
{
	Enemy::Update(dt);
	if (this->isDead)
	{
		delayTime = 3000 >> 1;
	}
}

