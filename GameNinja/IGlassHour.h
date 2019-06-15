#pragma once
#include "Item.h"

class IGlassHour : public Item
{
public:
	IGlassHour(float spawnX, float spawnY)
	{
		this->itemID = GLASSHOUR;
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16003);
	}
	~IGlassHour();
};