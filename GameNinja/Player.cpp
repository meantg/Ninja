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

	this->SetPosition(170.0f, 100.0f);
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
	if (_state == RUNNING)
	{
		if (x <= SCREEN_WIDTH && x >= 0)
			if(isReverse==false)
			x += 0.2f * dt;
			else x -= 0.2f * dt;
		if (x < 0)
			x = 0;
		if (x >= (SCREEN_WIDTH - 20))
			x = SCREEN_WIDTH - 20;
	}
	if (_state == NINJA_JUMP)
	{
		y += dt * vy;
	}
	state->Update(dt);
}

void Player::Render(float cmx, float cmy)
{
	x = x-cmx;
	animations[_state]->FlipHorizontal(isReverse);
	animations[_state]->Render(x, y);
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
		vx = NINJA_WALKING_SPEED;
		_state = RUNNING;
		nx = 2;
		break;
	case RUNNING_LEFT:
		vx = -NINJA_WALKING_SPEED;
		_state = RUNNING;
		nx = -2;
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
	_curanimation = animations[stateName];
}


void Player::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case DIK_RIGHT:
		ChangeState(new PlayerRunningState());
		SetState(RUNNING_RIGHT);
		isReverse = false;
		break;	
	case DIK_LEFT:
		ChangeState(new PlayerRunningState());
		isReverse = true;
		SetState(RUNNING_LEFT);
		break;
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
		case DIK_LEFT: case DIK_RIGHT:
		{
			stateName = STANDING;
			SetState(STANDING);
		}
		break;

	// Khi thả phím DOWN: state hiện tại chuyển thành đứng
		case DIK_DOWN:
			if (_state == SITTING)
			{
				stateName = STANDING;
				SetState(STANDING);
			}
			break;
		case DIK_A:
			if (_state == SITTING)
			{
				stateName = SITTING;
				SetState(SITTING);
			}
			else
			{
				stateName = STANDING;
				SetState(STANDING);
			}
			break;
	}
}


