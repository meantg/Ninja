#include "PlayerClingingState.h"

PlayerClingingState::PlayerClingingState()
{
	StateName = CLINGING;

	player->vx = 0;
	player->vy = 0;
}

void PlayerClingingState::Update(float dt)
{
	this->HandleKeyboard();
}

void PlayerClingingState::HandleKeyboard()
{
	if (keyCode[DIK_UP] || keyCode[DIK_DOWN])
	{
		player->ChangeState(new PlayerClingingState());
		return;
	}

	if (keyCode[DIK_SPACE])
	{
		if (!player->isReverse && keyCode[DIK_LEFT])
		{
			player->isReverse = true;
			player->x--;
			player->ChangeState(new PlayerJumpingState());
		}

		else if (player->isReverse && keyCode[DIK_RIGHT])
		{
			player->isReverse = false;
			player->x++;
			player->ChangeState(new PlayerJumpingState());
		}
	}
}