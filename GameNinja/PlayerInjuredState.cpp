#include "PlayerInjuredState.h"

PlayerInjuredState::PlayerInjuredState()
{
	StateName = INJURED;
	Player::GetInstance()->vx = Player::GetInstance()->isReverse ? NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED;
}

void PlayerInjuredState::Update(float dt)
{
	Player::GetInstance()->vy -= NINJA_GRAVITY;

	if (Player::GetInstance()->isOnGround)
	{
		Player::GetInstance()->ChangeState(new PlayerStandingState());
	}
}

State PlayerInjuredState::GetName()
{
	return INJURED;
}