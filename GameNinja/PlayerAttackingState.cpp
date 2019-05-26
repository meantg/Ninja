#include "PlayerAttackingState.h"

PlayerAttackingState::PlayerAttackingState()
{
	StateName = ATTACKING;
	_curState = Player::GetInstance()->_curState;
	if (_curState == SITTING)
		StateName = ATK_SIT;
	else
		StateName = ATK_STAND;
}

void PlayerAttackingState::Update(float dt)
{
	this->HandleKeyboard();
	if (Player::GetInstance()->_curanimation->isLastFrame)
	{
		switch (_curState)
		{
		case STANDING: case RUNNING:
			Player::GetInstance()->ChangeState(new PlayerStandingState());
			return;

		case SITTING:
			Player::GetInstance()->ChangeState(new PlayerSittingState());
			return;
		case FALLING:
			Player::GetInstance()->ChangeState(new PlayerFallingState());
			return;
		case JUMPING:
			Player::GetInstance()->ChangeState(new PlayerJumpingState());
			return;
		}
	}
	else
	{
		switch (_curState)
		{
		case RUNNING: case STANDING: case SITTING:
			Player::GetInstance()->vx = 0;
			Player::GetInstance()->vy = 0;
			break;
		case JUMPING:
		{
			Player::GetInstance()->vy -= NINJA_GRAVITY;
			if ((Player::GetInstance()->vx == SCREEN_WIDTH - Player::GetInstance()->width ||
				Player::GetInstance()->vx == (Player::GetInstance()->width) / 2))
			{
				Player::GetInstance()->ChangeState(new PlayerClingingState());
				return;
			}

			else if(Player::GetInstance()->vy <=0)
			{
				_curState = FALLING;
				Player::GetInstance()->vy = NINJA_GRAVITY;
			}
			break;
		}
	}
}