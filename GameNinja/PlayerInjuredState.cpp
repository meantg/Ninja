#include "PlayerInjuredState.h"

PlayerInjuredState::PlayerInjuredState()
{
	StateName = INJURED;
	/*player->vx = player->isReverse ? NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED;*/
	player->vy = NINJA_JUMPING_SPEED_Y;
	player->_allow[ATTACKING] = false;
}

void PlayerInjuredState::Update(float dt)
{
	player->vy -= 1.5*NINJA_GRAVITY;

	if (player->isOnGround)
	{
		player->ChangeState(new PlayerStandingState());
	}
}

State PlayerInjuredState::GetName()
{
	return INJURED;
}