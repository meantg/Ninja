#include "Item.h"

Item::Item()
{
	this->type = ITEM;
	this->tag = ITEM;

	this->vx = 0;
	this->vy = ITEM_SPEED_Y;
}

void Item::DectectGround(unordered_set<Rect*> grounds)
{
	for (auto g : grounds)
	{
		if (g->x < this->x && this->x < g->x + g->width
			&& g->y >= groundBound.y && this->y > g->y)
		{
			groundBound = *g;
		}
	}
	this->spawnY = this->y = this->groundBound.y + (this->height >> 1);

}

void Item::Update(float dt)
{
	this->dx = vx * dt;
	this->dy = vy * dt;
}

void Item::Render()
{
	_sprite->Draw(this->x, this->y);
}
