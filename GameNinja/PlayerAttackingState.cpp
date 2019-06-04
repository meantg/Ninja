#include "PlayerAttackingState.h"

PlayerAttackingState::PlayerAttackingState()
{
	_curState = Player::GetInstance()->state->StateName;
	_reverse = Player::GetInstance()->isReverse;
	Player::GetInstance()->_allow[JUMPING] = false;
	if (_curState == SITTING)
	{
		StateName = ATK_SIT;
		Player::GetInstance()->isStanding = false;
	}
	else
		StateName = ATK_STAND;
}

void PlayerAttackingState::Update(float dt)
{
	this->HandleKeyboard();
	if (Player::GetInstance()->y <= 56)
		Player::GetInstance()->y = 56;

	// Kiem tra xem danh xong chua
	if (Player::GetInstance()->_curAnimation->isLastFrame)
	{
		Player::GetInstance()->_allow[ATTACKING] = true;
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
	// Neu chua danh xong
	else
	{
		Player::GetInstance()->_allow[ATTACKING] = false;
		switch (_curState)
		{
		case RUNNING: case STANDING: case SITTING:
			Player::GetInstance()->vx = 0;
			Player::GetInstance()->vy = 0;
			break;
		case JUMPING:
		{
			//Player::GetInstance()->_allow[JUMPING] = false;
			Player::GetInstance()->vy -= NINJA_GRAVITY;
			//if ((Player::GetInstance()->vx == SCREEN_WIDTH - Player::GetInstance()->width ||
			//	Player::GetInstance()->vx == (Player::GetInstance()->width) / 2))
			//{
			//	Player::GetInstance()->ChangeState(new PlayerClingingState());
			//	return;
			//}

			//else if (Player::GetInstance()->vy <= 0)
			//{
			//	_curState = FALLING;
			//	Player::GetInstance()->vy = NINJA_GRAVITY;
			//}
			break;
		}
		case FALLING:
			Player::GetInstance()->vy = -NINJA_FALLING_SPEED_Y;
		}
	}
}

void PlayerAttackingState::HandleKeyboard()
{
	if (keyCode[DIK_LEFT])
	{
		Player::GetInstance()->vx = _reverse ? -NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED / 2;
	}
	else if (keyCode[DIK_RIGHT])
	{
		Player::GetInstance()->vx = !_reverse ? NINJA_WALKING_SPEED : NINJA_WALKING_SPEED / 2;
	}
	else Player::GetInstance()->vx = 0;
}
