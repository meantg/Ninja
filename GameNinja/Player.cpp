﻿#include "Player.h"

Player * Player::_instance = NULL;

Player::Player()
{

	this->AddAnimation(STANDING);
	this->AddAnimation(ATK_STAND);
	this->AddAnimation(THROWING);
	this->AddAnimation(CLIMBING);
	this->AddAnimation(RUNNING);
	this->AddAnimation(SITTING);
	this->AddAnimation(ATTACKING);
	this->AddAnimation(JUMPING);
	this->AddAnimation(JUMPING_ATK);

	this->SetPosition(10.0f, 100.0f);
	_state = STANDING;
	_curanimation = animations[_state];
}

Player::~Player()
{
}

Player * Player::GetInstance()
{
	if (_instance == NULL)
		_instance = new Player();
		return _instance;
}

void Player::Update(DWORD dt)
{
	//if (_state == RUNNING)
	//{
	//	if (x <= SCREEN_WIDTH && x >= 0)
	//		if(isReverse==false)
	//		x += 0.2f * dt;
	//		else x -= 0.2f * dt;
	//	if (x < 0)
	//		x = 0;
	//	if (x >= SCREEN_WIDTH /2)
	//		x = SCREEN_WIDTH /2;
	//}
	//if (_state == NINJA_JUMP)
	//{
	//	y += dt * vy;
	//}
	animations[_state]->Update(dt);
	state->Update(dt);
	if (x < 0)
		x = 0;
	if (x >=2048-20)
		x = 2048-20;
	x += vx * dt;
}

void Player::Render(float cameraX, float cameraY)
{
	animations[_state]->isReverse = isReverse;
	animations[_state]->Render(x-cameraX, y);
}

void Player::AddAnimation(State _state)
{
	LPANIMATION ani = AnimationManager::GetInstance()->Get(PLAYER, _state);
	animations[_state] = ani;
}

void Player::SetState(State state)
{
	switch (state)
	{
	case STANDING:
		vx = 0;
		_state = STANDING;
		break;
	case RUNNING_RIGHT:
		_state = RUNNING;
		break;
	case RUNNING_LEFT:
		_state = RUNNING;
		break;
	case ATK_STAND:
		_state = ATK_STAND;
		break;
	case SITTING:
		_state = SITTING;
		break;
	case JUMPING:
		_state = JUMPING;
		break;
	case ATTACKING:
		_state = ATTACKING;
		break;
	//case NINJA_RUN_LEFT:
	//	vx = NINJA_WALKING_SPEED;
	//	_curState = 4;
	//	nx = -1;
	//	isReverse = true;
	//	break;
	//case NINJA_JUMP:
	//	if (y == 100)
	//		vy = -NINJA_JUMPING_SPEED_Y;
	//	_curState = NINJA_JUMP;
	//	break;
	//case NINJA_SITTING:
	//	_curState = NINJA_SITTING;
	//	break;
	//case NINJA_ATK_STANDING:
	//	_curState = NINJA_ATK_STANDING;
	//	break;
	//default:
	//	break;
	}
}

void Player::ChangeState(PlayerState * playerstate)
{
	delete state;
	state = playerstate;
	stateName = playerstate->StateName;
	_state = stateName;
	_curanimation = animations[stateName];
}


void Player::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	/*case DIK_RIGHT:
		ChangeState(new PlayerRunningState());
		_state = RUNNING;
		isReverse = false;
		break;	
	case DIK_LEFT:
		ChangeState(new PlayerRunningState());
		isReverse = true;
		SetState(RUNNING_LEFT);
		break;*/
	case DIK_A:
		ChangeState(new PlayerAttackingState());
		if (isStanding = true)
			SetState(ATK_STAND);
		//else
		//	SetState(ATK_SIT);
		break;
	case DIK_DOWN:
		ChangeState(new PlayerSittingState());
		SetState(SITTING);
		break;
	case DIK_SPACE:
		ChangeState(new PlayerJumpingState());
		SetState(JUMPING);
		break;
	}
}

void Player::OnKeyUp(int keyCode)
{
	switch (keyCode)
	{
	/*	case DIK_LEFT: case DIK_RIGHT:
		{
			stateName = STANDING;
			SetState(STANDING);
		}
		break;*/

	// Khi thả phím DOWN: state hiện tại chuyển thành đứng
		case DIK_DOWN:
			if (_state == SITTING)
			{
				stateName = STANDING;
				SetState(STANDING);
			}
			break;
	}
}


