#include "Item.h"

Item::Item(float spawnX, float spawnY)
{
	this->type = ITEM;
	this->tag = ITEM;

	this->vx = 0;
	this->vy = ITEM_SPEED_Y;
}

bool Item::DectectGround(unordered_set<Rect*>)
{
	auto rbp = this->GetRect();					//rect broading-phase
	auto bottom = rbp.y + rbp.height;
	rbp.y = rbp.y + dy;
	rbp.height = rbp.height - dy;
	if (rbp.isContain(_curGround) && (bottom >= _curGround.y))
		return true;

	for (auto g : grounds)
	{
		if (rbp.isContain(*g) && (bottom >= g->y))
		{
			_curGround = *g;
			return true;
		}
	}
	return false;
}

void Item::Update(float dt)
{
}

void Item::Render()
{
}
