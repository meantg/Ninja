#include "EEagle.h"

EEagle::EEagle(float spawnX, float spawnY)
{
	this->type = E_EAGLE;
	this->_state = STANDING;
	this->AddAnimation(E_EAGLE, STANDING);
	this->AddAnimation(E_EAGLE, RUNNING);
	this->AddAnimation(E_EAGLE, DEAD);

	this->width = ENEMY_EAGLE_WIDTH;
	this->height = ENEMY_EAGLE_HEIGHT;
	this->speed = ENEMY_EAGLE_SPEED;

	this->vy = ENEMY_EAGLE_SPEED;
	this->vx = speed;
	this->x = spawnX;
	this->spawnX = x;
	this->y = spawnY;
	this->spawnY = spawnY;
	this->ChangeState(STANDING);
	this->activeDistance = 70.0f;
}

void EEagle::UpdatePosition(float dt)
{
	this->isReverse = (player->x < this->x);

	if (delayTime <= 0)
	{
		this->dx = (player->x - this->x) / MAX_FRAME_RATE;
		this->dy = (player->y - this->y) / MAX_FRAME_RATE;

		if (player->x < this->x)
		{
			this->vx = min(-9.0f, dx);
		}
		else
		{
			this->vx = max(9.0f, dx);
		}

		if (player->y < this->y)
		{
			this->vy = min(-9.0, dy);
		}
		else this->vy = max(9.0, dy);

		delayTime = 3000;
	}
	else
	{
		delayTime -= 100*dt;
	}


	if (vx > 0 && this->x > player->x)
	{
		this->vx -= 0.3f;
	}
	else if (vx < 0 && this->x <= player->x)
	{
		this->vx += 0.3f;
	}

	if (vy > 0 && this->y > player->y)
	{
		this->vy -= 0.4;
	}
	else if (vy < 0 && this->y <= player->y)
	{
		this->vy += 0.4;
	}
	this->dx = vx * dt;
	this->dy = vy * dt;
}

void EEagle::Update(float dt)
{
	Enemy::Update(dt);
	if (isActive == true && isAttacked == false)
	{
		ChangeState(RUNNING);
	}
	else
		ChangeState(DEAD);
}

void EEagle::ChangeState(State StateName)
{
	switch (StateName)
	{
	case STANDING:
	{
		this->isOutScreen = false;
		this->isActive = false;
		this->isDead = false;
		break;
	}

	case RUNNING:
	{
		auto distance = player->x - this->spawnX;

		if (activeDistance * distance > 0 && distance >= this->activeDistance)
		{
			this->dx = this->dy = 0;
			this->isActive = true;
		}
		break;
	}
	case DEAD:
	{
		//this->isDead = true;
		////this->isActive = false;
		//this->isAttacked = false;
		break;
	}
	}

	this->_state = StateName;
	this->_curAnimation = animations[StateName];
}
