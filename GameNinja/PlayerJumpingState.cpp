#include "PlayerJumpingState.h"

PlayerJumpingState::PlayerJumpingState()
 {
	StateName = JUMPING;
	State _lastState = Player::GetInstance()->state->StateName;

	if (_lastState == RUNNING || _lastState == STANDING || _lastState == CLINGING)
		Player::GetInstance()->vy = NINJA_JUMPING_SPEED_Y;
}

void PlayerJumpingState::Update(float dt)
{
	Player::GetInstance()->vy = NINJA_GRAVITY;

	if (Player::GetInstance()->vy <= 0)
	{
		Player::GetInstance()->ChangeState(new PlayerFallingState());
		return;
	}

	this->HandleKeyboard();
}

void PlayerJumpingState::HandleKeyboard()
{
	Player::GetInstance()->vx = 0;
	if (keyCode[DIK_LEFT])
	{
		Player::GetInstance()->vx = _reverse ? NINJA_WALKING_SPEED / 2 : NINJA_WALKING_SPEED;
	}

}