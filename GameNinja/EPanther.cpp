#include "EPanther.h"

EPanther::EPanther(float spawnX, float spawnY, bool isReverse)
{

	this->type = E_PANTHER;
	this->AddAnimation(E_PANTHER, STANDING);
	this->AddAnimation(E_PANTHER, RUNNING);
	this->AddAnimation(E_PANTHER, DEAD);

	this->width = ENEMY_PANTHER_WIDTH;
	this->height = ENEMY_PANTHER_HEIGHT;
	this->speed = ENEMY_PANTHER_SPEED;
	this->score = ENEMY_PANTHER_SCORE;
	this->activeDistance = isReverse ? ENEMY_PANTHER_ACTIVE_DISTANCE : -ENEMY_PANTHER_ACTIVE_DISTANCE;
	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;
}

void EPanther::DetectGround(unordered_set<Rect*> grounds)
{
	Enemy::DetectGround(grounds);
	curGroundBound = groundBound;
	isOnGround = true;
}

void EPanther::DetectCurGround(unordered_set<Rect*> grounds)
{
	Rect nextGround = curGroundBound;

	for (auto g : grounds)
	{
		if (g->y < this->y - (this->height >> 1))
		{
			if (this->isReverse)
			{
				if (g->x <= curGroundBound.x && (nextGround.x == curGroundBound.x || g->x > nextGround.x))
				{
					nextGround = (*g);
				}
			}
			else
			{
				if (g->x >= curGroundBound.x && (nextGround.x == curGroundBound.x || g->x < nextGround.x))
				{
					nextGround = (*g);
				}
			}
		}
	}
	curGroundBound = nextGround;
}

void EPanther::UpdatePosition(float dt)
{
	if (this->y - (this->height >> 1) <= this->curGroundBound.y)
	{
		this->vy = 0;
		this->y = this->curGroundBound.y + (this->height >> 1);
	}

	this->isOnGround = (this->x > curGroundBound.x
		&& this->x < curGroundBound.x + curGroundBound.width);

	this->dx = vx * dt;
	this->dy = vy * dt;
}

void EPanther::ChangeState(State StateName)
{
	switch (StateName)
	{
	case STANDING:
	{
		this->isActive = false;
		this->isDead = false;
		this->isOutScreen = false;
		break;
	}

	case RUNNING:
	{
		auto distance = player->x - this->spawnX;

		if (activeDistance * distance > 0 && distance >= this->activeDistance)
		{
			this->curGroundBound = groundBound;
			this->isOnGround = true;
			this->isActive = true;
		}
		break;
	}

	case DEAD:
	{
		ScoreBoard::GetInstance()->score += score;
		break;
	}
	}
	this->_state = StateName;
	this->_curAnimation = animations[StateName];
}
