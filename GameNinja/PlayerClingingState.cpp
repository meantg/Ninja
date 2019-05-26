#include "PlayerClingingState.h"

PlayerClingingState::PlayerClingingState()
{
	StateName = CLINGING;

	Player::GetInstance()->vx = 0;
	Player::GetInstance()->vy = 0;
}

void PlayerClingingState::Update(float dt)
{
	this->HandleKeyboard();
}

void PlayerClingingState::HandleKeyboard()
{
	if (keyCode[DIK_UP] || keyCode[DIK_DOWN])
	{
		Player::GetInstance()->ChangeState(new PlayerClingingState());
		return;
	}

	if (keyCode[DIK_SPACE])
	{
		if (!Player::GetInstance()->isReverse && keyCode[DIK_LEFT])
		{
			Player::GetInstance()->isReverse = true;
			Player::GetInstance()->x--;
			Player::GetInstance()->ChangeState(new PlayerJumpingState());
		}

		else if (Player::GetInstance()->isReverse && keyCode[DIK_RIGHT])
		{
			Player::GetInstance()->isReverse = false;
			Player::GetInstance()->x++;
			Player::GetInstance()->ChangeState(new PlayerJumpingState());
		}
	}
}