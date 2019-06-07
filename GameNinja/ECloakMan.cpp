#include "ECloakMan.h"

ECloakMan::ECloakMan()
{
	this->_state = STANDING;
	this->AddAnimation(E_CLOAKMAN, STANDING);
	this->AddAnimation(E_CLOAKMAN, RUNNING);
	this->AddAnimation(E_CLOAKMAN, ATTACKING);
	this->x = 1220;
	this->y = 130;
	this->vx = 0.02f;
}

void ECloakMan::UpdatePosition(float dt)
{
	if (Player::GetInstance()->x - this->x < 0)
		this->isReverse = true;
	else
		this->isReverse = false;
	if (_state == RUNNING)
	{
		if (x > 1245)
		{
			x = 1245;
			vx = -0.02f;
		}
		else if (x < 1225)
		{
			x = 1225;
			vx = 0.02f;
		}
	}
	x += vx * dt;
}

void ECloakMan::Update(float dt)
{
	Enemy::Update(dt);
	if (abs(Player::GetInstance()->x - this->x) <= 130)
	{
		isActive = true;
		if (abs(Player::GetInstance()->x - this->x) <= 80)
			_state = ATTACKING;
		else
			_state = RUNNING;
	}
	else
		isActive = false;
}
