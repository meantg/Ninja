#pragma once
#include "Player.h"

class Item : public Entity
{
public:
	TypeItem itemtype;
	virtual void Update(Entity entity);
	Item() {}
	~Item();
};