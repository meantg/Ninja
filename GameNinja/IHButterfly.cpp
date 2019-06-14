#include "IHButterfly.h"

IHButterfly::IHButterfly(float spawnX, float spawnY)
{
	this->type = ITEM;
	this->_state = STANDING;
	this->AddAnimation(IH_BUTTERFLY, STANDING);
	this->AddAnimation(IH_BUTTERFLY, RUNNING);

	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;
}

