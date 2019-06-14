#include "PlayerStandingState.h"

PlayerStandingState::PlayerStandingState()
{
	player->height = NINJA_STANDING_HEIGHT;
	player->vx = 0;
	player->vy = 0;

	player->_allow[ATTACKING] = true;
	player->_allow[JUMPING] = true;
	player->_allow[RUNNING] = true;
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
		player->ChangeState(new PlayerRunningState());
	}
	if(keyCode[DIK_DOWN])
	{
		player->ChangeState(new PlayerSittingState());
	}
}