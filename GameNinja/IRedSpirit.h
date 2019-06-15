#pragma once
#include "Item.h"

class IRedSpirit : public Item
{
public:
	IRedSpirit(float spawnX, float spawnY)
	{
		this->itemID = REDSPIRIT;
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16002);
	}
	~IRedSpirit();
};