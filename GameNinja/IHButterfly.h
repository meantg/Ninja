#pragma once
#include "ItemHolder.h"

class IHButterfly : public ItemHolder
{
public:
	IHButterfly(float spawnX, float spawnY)
	{
		holderanim = AnimationManager::GetInstance()->Get(IH_BUTTERFLY, RUNNING);
		type = IH_BUTTERFLY;
		vx = vy = 0;
	}
	~IHButterfly() {};

};