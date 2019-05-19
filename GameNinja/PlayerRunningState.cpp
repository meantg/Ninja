#include "PlayerRunningState.h"

PlayerRunningState::PlayerRunningState()
{
	StateName = RUNNING;
}

void PlayerRunningState::Update(float dt)
{
	this->HandleKeyboard();
}

void PlayerRunningState::HandleKeyboard()
{
	if (keyCode[DIK_RIGHT])
	{
	}
}
