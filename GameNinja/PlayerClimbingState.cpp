#include "PlayerClimbingState.h"

PlayerClimbingState::PlayerClimbingState()
{
	StateName = CLIMBING;

	Player::GetInstance()->_allow[ATTACKING] = false;
	Player::GetInstance()->_allow[JUMPING] = true;
	Player::GetInstance()->_allow[SITTING] = false;
}

void PlayerClimbingState::Update(float dt)
{
	if (Player::GetInstance()->x > (SCREEN_HEIGHT / 2) - 20)
	{
		Player::GetInstance()->x++;
		Player::GetInstance()->ChangeState(new PlayerFallingState());
		return;
	}

	if (Player::GetInstance()->y < Player::GetInstance()->height / 2)
	{
		Player::GetInstance()->y = Player::GetInstance()->height / 2;
	}

	this->HandleKeyboard();
}

void PlayerClimbingState::HandleKeyboard()
{
	if (keyCode[DIK_UP])
	{
		Player::GetInstance()->y += NINJA_GRAVITY;
	}
	else if (keyCode[DIK_DOWN])
	{
		Player::GetInstance()->y -= NINJA_GRAVITY;
	}
	else
	{
		Player::GetInstance()->ChangeState(new PlayerClingingState());
	}
}