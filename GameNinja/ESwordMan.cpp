#include "ESwordMan.h"

ESwordMan::ESwordMan()
{
	this->_state = STANDING;
	this->AddAnimation(E_SWORDMAN, STANDING);
	this->AddAnimation(E_SWORDMAN, RUNNING);
	//this->AddAnimation(E_SWORDMAN, DEAD);
	this->width = ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->speed = ENEMY_SWORDMAN_SPEED;
	this->x = 1000.0f;
	this->y = 56.0f;
}

void ESwordMan::UpdatePosition(float dt)
{
	this->x += vx * dt;
}