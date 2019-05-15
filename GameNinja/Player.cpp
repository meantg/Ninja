#include "Player.h"



Player::Player()
{
	/*this->AddAnimation(STANDING);
	this->AddAnimation(ATTACKING_STAND);
	this->AddAnimation(THROWING);
	this->AddAnimation(CLIMBING);
	this->AddAnimation(RUNNING);
	this->AddAnimation(SITTING);
	this->AddAnimation(ATTACKING_SIT);
	this->AddAnimation(JUMPING);
	this->AddAnimation(JUMPING_ATK);*/

	this->SetPosition(10.0f, 100.0f);
	_state = ATTACKING_SIT;
}

Player::~Player()
{
}

void Player::Update(DWORD dt)
{

	if (_state == RUNNING)
	{
		if (x <= SCREEN_WIDTH-20 && x >= 0)
			/*x += vx * dt*nx;*/
			x += 2;
		if (x < 0)
			x = 0;
		if (x > SCREEN_WIDTH - 20)
			x = SCREEN_WIDTH - 20;
	}
	if (_curState == NINJA_JUMP)
	{
		y += dt * vy;
	}
}

void Player::Render()
{
	State state = _state;
	AnimationManager::GetInstance()->Get(PLAYER, state)->FlipHorizontal(isReverse);
	AnimationManager::GetInstance()->Get(PLAYER, state)->Render(x, y);
}

void Player::AddAnimation(State _state)
{
	LPANIMATION ani = AnimationManager::GetInstance()->Get(PLAYER, _state);
	animations[_state] = ani;
}

void Player::SetState(State state)
{
	//switch (state)
	//{
	//case STANDING:
	//	vx = 0;
	//	_curState = NINJA_IDLE;
	//	break;
	//case NINJA_RUN_RIGHT:
	//	vx = NINJA_WALKING_SPEED;
	//	_curState = 4;
	//	nx = 1;
	//	isReverse = false;
	//	break;
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
	//}

}



void Player::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case DIK_A:
		/*ChangeState(new AttackState(_playerhandler);*/
		break;
	}
}

Ninja::Ninja()
{
	{
		_curState = IDLE;
		mPos = new PositionComponent(10.0f, 100.0f,0.0f,15.0f);
		mVelo = new VelocityComponent(2.0f, 2.0f, 2.0f);
		mRigid = new RigidBodyComponent(mRigid->GetWitdh(PLAYER,_curState),mRigid->GetHeight(PLAYER,_curState));
		mStats = new StatsComponent(10.0f, 10.0f, 2.0f, 2.0f);
	}
}

Ninja::~Ninja()
{
}

void Ninja::Update()
{
	mPos->Update(mVelo);
	mVelo->Update();
	mRigid->Update();
	mStats->Update();
}

void Ninja::Render()
{
}
