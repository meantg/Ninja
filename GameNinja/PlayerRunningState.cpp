#include "PlayerRunningState.h"

PlayerRunningState::PlayerRunningState()
{
	StateName = RUNNING;
	Player::GetInstance()->vy = 0;
}

void PlayerRunningState::Update(float dt)
{
	this->HandleKeyboard();
}

void PlayerRunningState::HandleKeyboard()
{
	if (keyCode[DIK_RIGHT])
	{
		Player::GetInstance()->isReverse = false;
		Player::GetInstance()->vx = NINJA_WALKING_SPEED;
	}
	else if (keyCode[DIK_LEFT])
	{
		Player::GetInstance()->isReverse = true;
		Player::GetInstance()->vx = -NINJA_WALKING_SPEED;
	}

	else
		Player::GetInstance()->ChangeState(new PlayerStandingState());
}
