#include "PlayerJumpingState.h"

PlayerJumpingState::PlayerJumpingState()
 {
	
	State _lastState = player->state->StateName;

	player->_allow[ATTACKING] = true;
	player->_allow[CLINGING] = true;
	player->_allow[SITTING] = false;
	player->isOnGround = false;

	if (_lastState == RUNNING || _lastState == STANDING || _lastState == CLINGING)
		player->vy = NINJA_JUMPING_SPEED_Y;
	StateName = JUMPING;
}

void PlayerJumpingState::Update(float dt)
{
	player->vy -= NINJA_GRAVITY;
	if (player->vy <= 0) {
		player->ChangeState(new PlayerFallingState());
		return;
	}

	this->HandleKeyboard();
}

void PlayerJumpingState::HandleKeyboard()
{
	player->vx = 0;
	if (keyCode[DIK_LEFT])
	{
		player->isReverse = true;
		player->vx = _reverse ? -NINJA_WALKING_SPEED  : -NINJA_WALKING_SPEED/2;
	}
	else if (keyCode[DIK_RIGHT])
	{
		player->isReverse = false;
		player->vx = _reverse ? NINJA_WALKING_SPEED: NINJA_WALKING_SPEED/2;
	}

}