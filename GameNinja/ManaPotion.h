#pragma once
#include "Item.h"

class ManaPotion : public Item
{
protected:
	float manabonus;

public:
	ManaPotion()
	{
		_curState = IDLE;
		itemtype = MANA;
		manabonus = 10.0f;
	}
	~ManaPotion();
};