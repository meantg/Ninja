#include "PlayerFallingState.h"

PlayerFallingState::PlayerFallingState()
{

	StateName = FALLING;
	_reverse = player->isReverse;
	player->vy = -NINJA_FALLING_SPEED_Y;

	player->_allow[ATTACKING] = true;
	player->_allow[CLINGING] = true;
	player->_allow[SITTING] = false;
	player->_allow[JUMPING] = false;

}

void PlayerFallingState::Update(float dt)
{
	if (player->vy == 0)
	{
		player->ChangeState(new PlayerStandingState());
		return;
	}

	this->HandleKeyboard();
}

void PlayerFallingState::HandleKeyboard()
{
	if (keyCode[DIK_LEFT])
	{
		player->vx = _reverse ? -NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED /4;
		player->isReverse = true;
	}

	else if (keyCode[DIK_RIGHT])
	{
		player->vx = _reverse ? NINJA_WALKING_SPEED / 4 : NINJA_WALKING_SPEED;
		player->isReverse = false;
	}

	else
	{
		player->vx = 0;
	}
}