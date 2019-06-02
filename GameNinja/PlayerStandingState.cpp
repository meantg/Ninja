#include "PlayerStandingState.h"

PlayerStandingState::PlayerStandingState()
{
	Player::GetInstance()->vx = 0;
	Player::GetInstance()->vy = 0;
	Player::GetInstance()->_allow[ATTACKING] = true;
	StateName = STANDING;
}

void PlayerStandingState::Update(float dt)
{
	this->HandleKeyboard();
}

void PlayerStandingState::HandleKeyboard()
{
	if (keyCode[DIK_LEFT] || keyCode[DIK_RIGHT])
	{
		Player::GetInstance()->ChangeState(new PlayerRunningState());
	}
	if(keyCode[DIK_DOWN])
	{
		Player::GetInstance()->ChangeState(new PlayerSittingState());
	}
}