#include "Player.h"

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
	this->AddAnimation(JUMPING);
	this->AddAnimation(JUMPING_ATK);
	this->AddAnimation(FALLING);


	this->x = 20.0f;
	this->y = 56.0f;
	this->width = NINJA_WIDTH;
	this->height = NINJA_STANDING_HEIGHT;

	_state = STANDING;
	//_curAnimation = animations[_state];


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
	if (_state != SITTING) {
		if (y <= 56) {
			y = 56;
		}
	}
}

void Player::Render(float cameraX, float cameraY)
{
	animations[_state]->isReverse = isReverse;
	animations[_state]->Render(x-cameraX, cameraY - y);
	//this->RenderBoundingBox(x - cameraX, cameraY - y);
}

void Player::AddAnimation(State _state)
{
	LPANIMATION ani = AnimationManager::GetInstance()->Get(PLAYER, _state);
	animations[_state] = ani;
}


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
	case DIK_A:
		if (_allow[ATTACKING])
		{
			_allow[ATTACKING] = false;
			ChangeState(new PlayerAttackingState());
		}
		break;
	case DIK_SPACE:
		if (_allow[JUMPING])
		{
			_allow[JUMPING] = false;
			ChangeState(new PlayerJumpingState());
		}
		break;
	}
}

void Player::OnKeyUp(int keyCode)
{
	switch (keyCode)
	{
	// Khi thả phím DOWN: state hiện tại chuyển thành đứng
		case DIK_DOWN:
			if (isStanding == true)
			{
				/*Player::GetInstance()->y += 7;*/
				_state = STANDING;
			}
			break;
	}
}