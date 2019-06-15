#include "EEagle.h"

EEagle::EEagle(float spawnX, float spawnY, bool isReverse)
{
	this->type = E_EAGLE;
	this->_state = STANDING;
	this->AddAnimation(E_EAGLE, STANDING);
	this->AddAnimation(E_EAGLE, RUNNING);
	this->AddAnimation(E_EAGLE, DEAD);

	this->width = ENEMY_EAGLE_WIDTH;
	this->height = ENEMY_EAGLE_HEIGHT;
	this->speed = ENEMY_EAGLE_SPEED;
	this->score = ENEMY_EAGLE_SCORE;

	this->vy = ENEMY_EAGLE_SPEED;
	this->vx = speed;
	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;
	this->activeDistance = isReverse ? 70.0f : -70.0f;
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
			this->vx = min(-6.0f, dx);
		}
		else
		{
			this->vx = max(6.0f, dx);
		}

		if (player->y < this->y)
		{
			this->vy = min(-6.0, dy);
		}
		else this->vy = max(6.0, dy);

		delayTime = 1300;
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
		this->vy -= 0.3f;
	}
	else if (vy < 0 && this->y <= player->y)
	{
		this->vy += 0.3f;
	}
}

void EEagle::Update(float dt)
{
	Enemy::Update(dt);
	if (this->isDead) {
		delayTime = 1300 >> 1;
	}
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
		ScoreBoard::GetInstance()->score += score;
		delayTime = 1300 >> 2;
		break;
	}
	}

	this->_state = StateName;
	this->_curAnimation = animations[StateName];
}
