#include "PlayerAttackingState.h"

PlayerAttackingState::PlayerAttackingState()
{
	_curState = player->state->StateName;
	_reverse = player->isReverse;
	player->_allow[JUMPING] = false;
	if (_curState == SITTING)
	{
		StateName = ATK_SIT;
		player->isStanding = false;
	}
	else
		StateName = ATK_STAND;
}

void PlayerAttackingState::Update(float dt)
{
	this->HandleKeyboard();
	if (player->y <= 56)
		player->y = 56;

	// Kiem tra xem danh xong chua
	if (player->_curAnimation->isLastFrame)
	{
		player->_allow[ATTACKING] = true;
		switch (_curState)
		{
		case STANDING: case RUNNING:
			player->ChangeState(new PlayerStandingState());
			return;
		case SITTING:
			player->ChangeState(new PlayerSittingState());		
			return;
		case FALLING:
			player->ChangeState(new PlayerFallingState());
			return;
		case JUMPING:
			player->ChangeState(new PlayerJumpingState());
			return;
		}
	}
	// Neu chua danh xong
	else
	{
		player->_allow[ATTACKING] = false;
		switch (_curState)
		{
		case RUNNING: case STANDING: case SITTING:
			player->vx = 0;
			player->vy = 0;
			break;
		case JUMPING:
		{
			//player->_allow[JUMPING] = false;
			player->vy -= NINJA_GRAVITY;
			//if ((player->vx == SCREEN_WIDTH - player->width ||
			//	player->vx == (player->width) / 2))
			//{
			//	player->ChangeState(new PlayerClingingState());
			//	return;
			//}

			//else if (player->vy <= 0)
			//{
			//	_curState = FALLING;
			//	player->vy = NINJA_GRAVITY;
			//}
			break;
		}
		case FALLING:
			player->vy = -NINJA_FALLING_SPEED_Y;
		}
	}
}

void PlayerAttackingState::HandleKeyboard()
{
	if (keyCode[DIK_LEFT])
	{
		player->vx = _reverse ? -NINJA_WALKING_SPEED : -NINJA_WALKING_SPEED / 2;
	}
	else if (keyCode[DIK_RIGHT])
	{
		player->vx = !_reverse ? NINJA_WALKING_SPEED : NINJA_WALKING_SPEED / 2;
	}
	else player->vx = 0;
}
