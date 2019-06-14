#include "IHButterfly.h"

IHButterfly::IHButterfly(float spawnX, float spawnY)
{
	this->tag = ENEMY;
	this->type = ENEMY;
	this->_state = STANDING;
	this->AddAnimation(IH_BUTTERFLY, STANDING);
	this->AddAnimation(IH_BUTTERFLY, RUNNING);
	this->x = spawnX;
	this->spawnX = x;
	this->y = spawnY;
	this->ChangeState(STANDING);
}

