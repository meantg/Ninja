#pragma once
#include "Player.h"
#include "PlayerState.h"
#include "PlayerJumpingState.h"

class PlayerClingingState : public PlayerState
{
public:
	PlayerClingingState();
	void Update(float dt);
	void HandleKeyboard();
};
