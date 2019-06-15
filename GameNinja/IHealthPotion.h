#pragma once
#include "Item.h"

class IHealthPotion : public Item
{
public:
	IHealthPotion(float spawnX, float spawnY)
	{
		this->itemID = HEALTHPOTION;
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16008);
	}
	~IHealthPotion();
};
