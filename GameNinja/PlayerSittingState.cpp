#include "PlayerSittingState.h"

PlayerSittingState::PlayerSittingState()
{
	StateName = SITTING;
	Player::GetInstance()->_allow[JUMPING] = false;
	Player::GetInstance()->vx = 0;
	Player::GetInstance()->vy = 0;
	Player::GetInstance()->isStanding = false;
	Player::GetInstance()->_allow[ATTACKING] = true;
	Player::GetInstance()->height = NINJA_SITTING_HEIGHT;
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
	if (keyCode[DIK_LEFT])
	{
		Player::GetInstance()->isReverse = true;
		Player::GetInstance()->ChangeState(new PlayerRunningState());
	}
	if (keyCode[DIK_RIGHT])
	{
		Player::GetInstance()->isReverse = false;
		Player::GetInstance()->ChangeState(new PlayerRunningState());
	}
}

void PlayerSittingState::Update(float dt)
{
	this->HandleKeyboard();
}
