﻿#include "Player.h"

Player * Player::_instance = NULL;

Player::Player()
{

	this->AddAnimation(STANDING);
	this->AddAnimation(ATK_STAND);
	this->AddAnimation(ATK_SIT);
	this->AddAnimation(THROWING);
	this->AddAnimation(CLIMBING);
	this->AddAnimation(RUNNING);
	this->AddAnimation(SITTING);
	this->AddAnimation(ATTACKING);
	this->AddAnimation(JUMPING);
	this->AddAnimation(JUMPING_ATK);
	this->AddAnimation(FALLING);


	this->x = 20.0f;
	this->y = 56.0f;
	this->width = NINJA_WIDTH;
	this->height = NINJA_STANDING_HEIGHT;

	maxy = 60;
	_state = STANDING;
	_curAnimation = animations[_state];


	_allow[JUMPING] = true;
	_allow[ATTACKING] = true;
	_allow[RUNNING] = true;
	_allow[THROWING] = true;
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

Hitbox Player::GetHitbox()
{
	Hitbox box;
	box.top = y + (height >> 1);
	box.left = x - (width >> 1);
	box.right = box.left + width;
	box.bottom = box.top - height;
	box.vx = vx;
	box.vy = vy;
	return box;
}

void Player::Update(float dt)
{
	_curAnimation->Update(dt);
	state->Update(dt);
	if (x < 0)
		x = 0;
	if (x >=2048-20)
		x = 2048-20;
	x += vx * dt;
	y += vy * dt;
}

void Player::Render(float cameraX, float cameraY)
{
	animations[_state]->isReverse = isReverse;
	animations[_state]->Render(x-cameraX, cameraY - y);
	this->RenderBoundingBox(x - cameraX, cameraY - y);
}

void Player::AddAnimation(State _state)
{
	LPANIMATION ani = AnimationManager::GetInstance()->Get(PLAYER, _state);
	animations[_state] = ani;
}

//void Player::SetState(State state)
//{
//	switch (state)
//	{
//	case STANDING:
//		vx = 0;
//		_state = STANDING;
//		break;
//	case RUNNING_RIGHT:
//		_state = RUNNING;
//		break;
//	case RUNNING_LEFT:
//		_state = RUNNING;
//		break;
//	case ATK_STAND:
//		_state = ATK_STAND;
//		break;
//	case ATK_SIT:
//		_state = ATK_SIT;
//		break;
//	case SITTING:
//		_state = SITTING;
//		break;
//	case JUMPING:
//		_state = JUMPING;
//		break;
//	case ATTACKING:
//		_state = ATTACKING;
//		break;
//	//case NINJA_RUN_LEFT:
//	//	vx = NINJA_WALKING_SPEED;
//	//	_curState = 4;
//	//	nx = -1;
//	//	isReverse = true;
//	//	break;
//	//case NINJA_JUMP:
//	//	if (y == 100)
//	//		vy = -NINJA_JUMPING_SPEED_Y;
//	//	_curState = NINJA_JUMP;
//	//	break;
//	//case NINJA_SITTING:
//	//	_curState = NINJA_SITTING;
//	//	break;
//	//case NINJA_ATK_STANDING:
//	//	_curState = NINJA_ATK_STANDING;
//	//	break;
//	//default:
//	//	break;
//	}
//}

void Player::ChangeState(PlayerState * playerstate)
{
	delete state;
	state = playerstate;
	_state = playerstate->StateName;
	_curAnimation = animations[_state];
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
		if (_allow[ATTACKING])
		{
			_allow[ATTACKING] = false;
			ChangeState(new PlayerAttackingState());
			/*if (isStanding == true)
				SetState(ATK_STAND);
			else
				SetState(ATK_SIT);*/
		}
		break;
	case DIK_DOWN:
		ChangeState(new PlayerSittingState());
		/*SetState(SITTING);*/
		break;
	case DIK_SPACE:
		ChangeState(new PlayerJumpingState());
		/*SetState(JUMPING);*/
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
			if (isStanding == true)
			{
				_state = STANDING;
			}
			break;
	}
}


