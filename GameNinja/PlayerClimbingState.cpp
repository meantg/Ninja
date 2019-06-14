#include "PlayerClimbingState.h"

PlayerClimbingState::PlayerClimbingState()
{
	StateName = CLIMBING;

	player->_allow[ATTACKING] = false;
	player->_allow[JUMPING] = true;
	player->_allow[SITTING] = false;
}

void PlayerClimbingState::Update(float dt)
{
	if (player->x > (SCREEN_HEIGHT / 2) - 20)
	{
		player->x++;
		player->ChangeState(new PlayerFallingState());
		return;
	}

	if (player->y < player->height / 2)
	{
		player->y = player->height / 2;
	}

	this->HandleKeyboard();
}

void PlayerClimbingState::HandleKeyboard()
{
	if (keyCode[DIK_UP])
	{
		player->y += NINJA_GRAVITY;
	}
	else if (keyCode[DIK_DOWN])
	{
		player->y -= NINJA_GRAVITY;
	}
	else
	{
		player->ChangeState(new PlayerClingingState());
	}
}