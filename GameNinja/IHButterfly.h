#pragma once
#include "Enemy.h"

class IHButterfly : public Enemy
{
public:
	IHButterfly();
	~IHButterfly() {};
	void UpdateBeingAtk();
};