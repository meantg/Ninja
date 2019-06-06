#pragma once
#include "Enemy.h"

class ECloakMan : public Enemy
{
public:
	ECloakMan();
	~ECloakMan() {};
	void UpdatePosition(float dt);
	void Update(float dt);
};