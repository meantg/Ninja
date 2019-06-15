#pragma once
#include "Item.h"

class IBlueBag : public Item
{
public:
	IBlueBag(float spawnX, float spawnY) {
		this->itemID = BLUEBAG;
		this->x = this->spawnX = spawnX;
		this->y = this->spawnY = spawnY;
		this->_sprite = SpriteManager::GetInstance()->GetSprite(16007);
	}
	~IBlueBag();
};