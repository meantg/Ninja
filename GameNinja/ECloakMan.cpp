#include "ECloakMan.h"

ECloakMan::ECloakMan(float spawnX, float spawnY)
{
	this->_state = RUNNING;
	this->AddAnimation(E_CLOAKMAN, STANDING);
	this->AddAnimation(E_CLOAKMAN, RUNNING);
	this->AddAnimation(E_CLOAKMAN, ATTACKING);
	this->AddAnimation(E_CLOAKMAN, DEAD);

	this->width = 18;
	this->height = 35;
	this->speed = 4.0f;

	this->vy = 0;
	this->x = spawnX;
	this->spawnX = x;
	this->y = spawnY;
	this->vx = 2.5f;
	ChangeState(RUNNING);
}

void ECloakMan::UpdatePosition(float dt)
{
	if (Player::GetInstance()->x - this->x < 0)
		this->isReverse = true;
	else
		this->isReverse = false;
	if (_state == RUNNING)
	{
		if (x > 1235)
		{
			x = 1235;
			vx = -2.5f;
		}
		else if (x < 1225)
		{
			x = 1225;
			vx = 2.5f;
		}
	}
	if (_state == ATTACKING)
	{
		if (x > 1235)
		{
			x = 1235;
			vx = -2.5f;
		}
		else if (x < 1225)
		{
			x = 1225;
			vx = 2.5f;
		}
	}
	x += vx * dt;
}

void ECloakMan::Update(float dt)
{
	Enemy::Update(dt);
	if (abs(Player::GetInstance()->x - this->x) <= 130)
	{
		if (abs(Player::GetInstance()->x - this->x) <= 60)
		{
			if (isActive == true && isAttacked == false)
				ChangeState(ATTACKING);
			else
				ChangeState(DEAD);
		}
		else
		{
			ChangeState(RUNNING);
			isAttacked = false;
		}
	}

}
