#include "IHButterfly.h"

IHButterfly::IHButterfly(float spawnX, float spawnY)
{
	this->tag = PLAYER;
	this->type = ENEMY;
	this->_state = STANDING;
	this->isActive = true;
	this->AddAnimation(IH_BUTTERFLY, STANDING);
	this->x = spawnX;
	this->spawnX = x;
	this->y = spawnY;
	this->ChangeState(STANDING);
}

