#pragma once
#include "Player.h"
#include "PlayerState.h"
#include "PlayerRunningState.h"
#include "PlayerStandingState.h"

class PlayerSittingState : public PlayerState
{
public:
	PlayerSittingState();
	void Update(float dt);
	void HandleKeyboard();
};
