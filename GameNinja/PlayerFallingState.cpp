#include "PlayerFallingState.h"

PlayerFallingState::PlayerFallingState()
{
	_reverse = Player::GetInstance()->isReverse;
	StateName = FALLING;
}

void PlayerFallingState::Update(float dt)
{
	if (Player::GetInstance()->y == 120)
		Player::GetInstance()->vy = 0;
	if (Player::GetInstance()->vy == 0)
	{
		Player::GetInstance()->ChangeState(new PlayerStandingState());
		return;
	}

	this->HandleKeyboard();
}

void PlayerFallingState::HandleKeyboard()
{
	if (keyCode[DIK_LEFT])
	{
		Player::GetInstance()->vx = _reverse ? -NINJA_WALKING_SPEED : NINJA_WALKING_SPEED /2;
		Player::GetInstance()->isReverse = true;
	}

	else if (keyCode[DIK_RIGHT])
	{
		Player::GetInstance()->vx = _reverse ? NINJA_WALKING_SPEED / 2 : NINJA_WALKING_SPEED;
		Player::GetInstance()->isReverse = false;
	}

	else
	{
		Player::GetInstance()->vx = 0;
	}
}