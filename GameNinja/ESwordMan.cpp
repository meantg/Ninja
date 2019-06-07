#include "ESwordMan.h"

ESwordMan::ESwordMan(float spawnX, float spawnY)
{
	this->_state = STANDING;
	this->AddAnimation(E_SWORDMAN, STANDING);
	this->AddAnimation(E_SWORDMAN, RUNNING);
	this->AddAnimation(E_SWORDMAN, DEAD);
	this->width = ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->speed = ENEMY_SWORDMAN_SPEED;
	this->x = spawnX;
	this->y = spawnY;
}

void ESwordMan::UpdatePosition(float dt)
{
	this->x += speed * dt;
}