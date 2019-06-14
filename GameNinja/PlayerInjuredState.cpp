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

	//if (player->vy <= 0 )
	//{
	//	player->ChangeState(new PlayerFallingState());
	//}
	if (player->vy <= 0)
	{
		/*player->vy = NINJA_FALLING_SPEED_Y;*/
		if (player->y <= 56)
		{
			player->y = 56;
			player->vy = 0;
			player->ChangeState(new PlayerStandingState());
			return;
		}
	}
}

State PlayerInjuredState::GetName()
{
	return INJURED;
}