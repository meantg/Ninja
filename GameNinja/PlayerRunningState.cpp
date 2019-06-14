#include "PlayerRunningState.h"

PlayerRunningState::PlayerRunningState()
{
	StateName = RUNNING;
	player->vy = 0;
	player->isStanding = false;

}

void PlayerRunningState::Update(float dt)
{
	this->HandleKeyboard();

}

void PlayerRunningState::HandleKeyboard()
{
	if (keyCode[DIK_RIGHT])
	{
		player->isReverse = false;
		player->vx = NINJA_WALKING_SPEED;
	}
	else if (keyCode[DIK_LEFT])
	{
		player->isReverse = true;
		player->vx = -NINJA_WALKING_SPEED;
	}
	else
		player->ChangeState(new PlayerStandingState());
}
