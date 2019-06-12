#include "PlayerInjuredState.h"

PlayerInjuredState::PlayerInjuredState()
{
	StateName = INJURED;
	/*Player::GetInstance()->vx = Player::GetInstance()->isReverse ? NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED;*/
	Player::GetInstance()->vy = NINJA_JUMPING_SPEED_Y;
	Player::GetInstance()->_allow[ATTACKING] = false;
}

void PlayerInjuredState::Update(float dt)
{
	Player::GetInstance()->vy -= 1.5*NINJA_GRAVITY;

	//if (Player::GetInstance()->vy <= 0 )
	//{
	//	Player::GetInstance()->ChangeState(new PlayerFallingState());
	//}
	if (Player::GetInstance()->vy <= 0)
	{
		/*Player::GetInstance()->vy = NINJA_FALLING_SPEED_Y;*/
		if (Player::GetInstance()->y <= 56)
		{
			Player::GetInstance()->y = 56;
			Player::GetInstance()->vy = 0;
			Player::GetInstance()->ChangeState(new PlayerStandingState());
			return;
		}
	}
}

State PlayerInjuredState::GetName()
{
	return INJURED;
}