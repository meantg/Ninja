#include "PlayerStandingState.h"

PlayerStandingState::PlayerStandingState()
{
	Player::GetInstance()->height = NINJA_STANDING_HEIGHT;
	Player::GetInstance()->vx = 0;
	Player::GetInstance()->vy = 0;

	Player::GetInstance()->_allow[ATTACKING] = true;
	Player::GetInstance()->_allow[JUMPING] = true;
	Player::GetInstance()->_allow[RUNNING] = true;
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