#pragma once
#include "Item.h"

class IBlueShuriken : public Item
{
public:
	IBlueShuriken(float spawnX, float spawnY) {
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16004);
	}
	~IBlueShuriken();
};