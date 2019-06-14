#include "PlayerSittingState.h"

PlayerSittingState::PlayerSittingState()
{
	StateName = SITTING;
	player->_allow[JUMPING] = false;
	player->vx = 0;
	player->vy = 0;
	player->isStanding = false;
	player->_allow[ATTACKING] = true;
	player->height = NINJA_SITTING_HEIGHT;
}

void PlayerSittingState::HandleKeyboard()
{
	if (!keyCode[DIK_DOWN])
	{
		if (keyCode[DIK_LEFT] || keyCode[DIK_RIGHT])
		{
			player->ChangeState(new PlayerRunningState());
		}
		else
		{
			player->ChangeState(new PlayerStandingState());
		}
	}
	if (keyCode[DIK_LEFT])
	{
		player->isReverse = true;
		player->ChangeState(new PlayerRunningState());
	}
	if (keyCode[DIK_RIGHT])
	{
		player->isReverse = false;
		player->ChangeState(new PlayerRunningState());
	}
}

void PlayerSittingState::Update(float dt)
{
	this->HandleKeyboard();
}
