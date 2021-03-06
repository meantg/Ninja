#pragma once
#include "Player.h"
#include "GameGlobal.h"

class PlayerState
{
public:
	PlayerState() {}
	virtual void Update(float dt) = 0;
	virtual void HandleKeyboard() = 0;
	State StateName, _curState;
	bool _reverse, isInjured = false;
};