#include "PlayerSittingState.h"

PlayerSittingState::PlayerSittingState()
{
	StateName = SITTING;
}

void PlayerSittingState::HandleKeyboard()
{
	if (!keyCode[DIK_DOWN])
	{
		if (keyCode[DIK_LEFT] || keyCode[DIK_RIGHT])
		{
			Player::GetInstance()->ChangeState(new PlayerRunningState());
		}
		else
		{
			Player::GetInstance()->ChangeState(new PlayerStandingState());
		}
	}
}

void PlayerSittingState::Update(float dt)
{
	this->HandleKeyboard();
}
