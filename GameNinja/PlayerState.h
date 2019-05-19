#pragma once
#include "Player.h"
#include "GameGlobal.h"

class PlayerState
{
public:
	unordered_map<int, bool> keyCode;
	PlayerState() {};
	virtual void Update(float dt) = 0;
	virtual void HandleKeyboard() = 0;
	State StateName;
};