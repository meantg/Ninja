#pragma once
#include "Item.h"

class IBlueSpirit : public Item
{
public:
	IBlueSpirit(float spawnX, float spawnY)
	{
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16001);
	}
	~IBlueSpirit();
};