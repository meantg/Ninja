#pragma once
#include "Player.h"
#include "GameGlobal.h"

class PlayerState
{
public:
	PlayerState() {}
	virtual void Update(float dt) = 0;
	virtual void HandleKeyboard() = 0;
	State StateName;
	bool _reverse;
};