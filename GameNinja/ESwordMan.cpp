#include "ESwordMan.h"

ESwordMan::ESwordMan()
{
	this->_state = E_SW_STANDING;
	this->AddAnimation(E_SWORDMAN, E_SW_STANDING);
	this->AddAnimation(E_SWORDMAN, E_SW_RUNNING);
	//this->AddAnimation(E_SWORDMAN, DEAD);
	this->width = ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->speed = ENEMY_SWORDMAN_SPEED;
	this->x = 100.0f;
	this->y = 56.0f;
}

void ESwordMan::UpdatePosition(float dt)
{
	this->x = vx * dt;
}