#pragma once
#include "Enemy.h"

class ESwordMan : public Enemy
{
public:
	ESwordMan();
	~ESwordMan() {};
	void UpdatePosition(float dt);
};