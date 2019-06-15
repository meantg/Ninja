#pragma once
#include "ITem.h"

class IFireWheel : public Item
{
public:
	IFireWheel(float spawnX, float spawnY)
	{
		this->itemID = FIREWHEEL;
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16006);
	}
	~IFireWheel();
};