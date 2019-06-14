#pragma once
#include "Item.h"

class IRedShuriken : public Item
{
public:
	IRedShuriken(float spawnX, float spawnY) {
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16009);
	}
	~IRedShuriken();
};