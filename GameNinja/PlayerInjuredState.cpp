#include "PlayerInjuredState.h"

PlayerInjuredState::PlayerInjuredState()
{
	StateName = INJURED;
	Player::GetInstance()->vx = Player::GetInstance()->isReverse ? NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED;
	Player::GetInstance()->vy = NINJA_JUMPING_SPEED_Y;
}

void PlayerInjuredState::Update(float dt)
{
	Player::GetInstance()->vy -= NINJA_GRAVITY;

	if (Player::GetInstance()->vy <= 0 )
	{
		Player::GetInstance()->ChangeState(new PlayerFallingState());
	}
}

State PlayerInjuredState::GetName()
{
	return INJURED;
}