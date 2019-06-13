#include "PlayerFallingState.h"

PlayerFallingState::PlayerFallingState()
{

	StateName = FALLING;
	_reverse = Player::GetInstance()->isReverse;
	Player::GetInstance()->vy = -NINJA_FALLING_SPEED_Y;

	Player::GetInstance()->_allow[ATTACKING] = true;
	Player::GetInstance()->_allow[CLINGING] = true;
	Player::GetInstance()->_allow[SITTING] = false;
	Player::GetInstance()->_allow[JUMPING] = false;

}

void PlayerFallingState::Update(float dt)
{
	if (Player::GetInstance()->y <= 56)
	{
		Player::GetInstance()->y = 56;
		Player::GetInstance()->vy = 0;
		Player::GetInstance()->ChangeState(new PlayerStandingState());
		return;
	}
	/*if(Player::GetInstance()->isOnGround){
		Player::GetInstance()->ChangeState(new PlayerStandingState());
		return;
	}*/

	this->HandleKeyboard();
}

void PlayerFallingState::HandleKeyboard()
{
	if (keyCode[DIK_LEFT])
	{
		Player::GetInstance()->vx = _reverse ? -NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED /4;
		Player::GetInstance()->isReverse = true;
	}

	else if (keyCode[DIK_RIGHT])
	{
		Player::GetInstance()->vx = _reverse ? NINJA_WALKING_SPEED / 4 : NINJA_WALKING_SPEED;
		Player::GetInstance()->isReverse = false;
	}

	else
	{
		Player::GetInstance()->vx = 0;
	}
}