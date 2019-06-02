#include "PlayerJumpingState.h"

PlayerJumpingState::PlayerJumpingState()
 {
	StateName = JUMPING;
	State _lastState = Player::GetInstance()->state->StateName;

	if (_lastState == RUNNING || _lastState == STANDING || _lastState == CLINGING)
		Player::GetInstance()->vy = -NINJA_JUMPING_SPEED_Y;
}

void PlayerJumpingState::Update(float dt)
{
	if(Player::GetInstance()->y>=40)
		Player::GetInstance()->vy = -NINJA_JUMPING_SPEED_Y;
	else 
	{
		Player::GetInstance()->vy = NINJA_GRAVITY;
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
		Player::GetInstance()->isReverse = true;
		Player::GetInstance()->vx = _reverse ? -NINJA_WALKING_SPEED  : -NINJA_WALKING_SPEED/2;
	}
	else if (keyCode[DIK_RIGHT])
	{
		Player::GetInstance()->isReverse = false;
		Player::GetInstance()->vx = _reverse ? NINJA_WALKING_SPEED/2 : NINJA_WALKING_SPEED;
	}

}