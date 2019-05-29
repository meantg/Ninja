#include "PlayerSittingState.h"

PlayerSittingState::PlayerSittingState()
{
	StateName = SITTING;
	Player::GetInstance()->vx = 0;
	Player::GetInstance() -> vy = 0;
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
