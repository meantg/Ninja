#pragma once
#include "Enemy.h"
#include "Item.h"

class IHButterfly : public Enemy
{
public:
	IHButterfly(float spawnX, float spawnY)
	{
		this->type = ITEMHOLDER;
		this->_state = STANDING;
		this->AddAnimation(IH_BUTTERFLY, STANDING);
		this->AddAnimation(IH_BUTTERFLY, RUNNING);

		this->width = ITEMHOLDER_WIDTH;
		this->height = ITEMHOLDER_HEIGHT;

		this->spawnX = this->x = spawnX;
		this->spawnY = this->y = spawnY;
		vx = vy = 0;
	}
	~IHButterfly() {};

	void Update(float dt)
	{
		Enemy::Update(dt);
		//else if (isAttacked == true)
		//	ChangeState(DEAD);
	}
	void DetectGround(unordered_set<Rect*> grounds) {}

};