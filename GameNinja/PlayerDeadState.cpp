#include "PlayerDeadState.h"

PlayerDeadState::PlayerDeadState()
{
	Player::GetInstance()->vx = 0;
	Player::GetInstance()->vy = 0;
}

State PlayerDeadState::GetName()
{
	return DEAD;
}