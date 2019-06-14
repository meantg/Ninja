#include "ECloakMan.h"

ECloakMan::ECloakMan(float spawnX, float spawnY)
{
	this->_state = RUNNING;
	this->AddAnimation(E_CLOAKMAN, STANDING);
	this->AddAnimation(E_CLOAKMAN, RUNNING);
	this->AddAnimation(E_CLOAKMAN, ATTACKING);
	this->AddAnimation(E_CLOAKMAN, DEAD);

	this->type = E_CLOAKMAN;

	this->width = ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->bulletTotal = bulletCount = BULLET_CLOAKMAN_COUNT;
	this->delayTime = ENEMY_CLOAKMAN_DELAY;
	this->speed = ENEMY_CLOAKMAN_SPEED;

	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;


}

void ECloakMan::UpdatePosition(float dt)
{
	delayTime -= dt * 100;
	if (player->x - this->x < 0)
		this->isReverse = true;
	else
		this->isReverse = false;
	if (_state == RUNNING)
	{
		this->dx = vx * dt;
		if (x > 1235)
		{
			x = 1235;
			vx = -ENEMY_CLOAKMAN_SPEED;
		}
		else if (x < 1225)
		{
			x = 1225;
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
		if (x > 1235)
		{
			x = 1235;
			vx = -ENEMY_CLOAKMAN_SPEED;
		}
		else if (x < 1225)
		{
			x = 1225;
			vx = ENEMY_CLOAKMAN_SPEED;
		}
	}
	x += vx * dt;
}

void ECloakMan::Update(float dt)
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
			else if(isAttacked == true)
				ChangeState(DEAD);
		}
		else
		{
			ChangeState(RUNNING);
			isAttacked = false;
		}
	}
}

	
