#pragma once
#include "Item.h"

class IRedBag : public Item
{
public:
	IRedBag(float spawnX, float spawnY)
	{
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16009);
	};
	~IRedBag();
};