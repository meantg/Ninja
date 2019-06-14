#include "Player.h"

Player * Player::_instance = NULL;

Player::Player()
{
	this->type = PLAYER;
	this->tag = PLAYER;
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
	this->AddAnimation(INJURED);


	this->x = 56.0f;
	this->y = 56.0f;
	this->width = NINJA_WIDTH;
	this->height = NINJA_STANDING_HEIGHT;

	_state = STANDING;
	//_curAnimation = animations[_state];
	isOnGround = true;

	_allow[JUMPING] = true;
	_allow[ATTACKING] = true;
	_allow[RUNNING] = true;
	_allow[THROWING] = true;
}

Player::~Player()
{
}

//Phát hiện ground bằng cách tạo một broading-phase của player và check xem có chạm vào ground không
bool Player::DetectGround(unordered_set<Rect*> grounds)
{
	auto rbp = this->GetRect();					//rect broading-phase
	auto bottom = rbp.y + rbp.height;
	rbp.y = rbp.y + dy;
	rbp.height = rbp.height - dy;
	if (rbp.isContain(_curGround) && (bottom >= _curGround.y))
		return true;

	for (auto g : grounds)
	{
		if (rbp.isContain(*g) && (bottom >= g->y))
		{
			_curGround = *g;
			return true;
		}
	}
	return false;
}

bool Player::DetectWall(unordered_set<Wall*> walls)
{
	auto r = this->GetRect();
	r.x = dx > 0 ? r.x : r.x + dx;
	r.width = dx > 0 ? dx + r.width : r.width - dx;

	if (r.isContain(wallBound.wall))
	{
		return true;
	}
	else
	{
		for (auto w : walls)
		{
			if (w->wall.isContain(r))
			{
				wallBound = *w;
				return true;
			}
		}
	}
	return false;
}

Player * Player::GetInstance()
{
	if (_instance == NULL)
		_instance = new Player();
		return _instance;
}

//Hitbox Player::GetHitbox()
//{
//	Hitbox box;
//	box.top = y + (height >> 1);
//	box.left = x - (width >> 1);
//	box.right = box.left + width;
//	box.bottom = box.top - height;
//	box.vx = vx;
//	box.vy = vy;
//	return box;
//}

void Player::Update(float dt, unordered_set<Object*> gameObj)
{
	_curAnimation->Update(dt);
	state->Update(dt);
	CollisionResult result;
	result.nx = result.ny = 0;
	result.entryTime = 1.0f;
	if (_state == !INJURED)
	{
		for (auto o : gameObj)
		{
			result = Collision::GetInstance()->SweptAABB(o->GetHitbox(), this->GetHitbox());
			if (result.entryTime > 0 && result.entryTime < 1.0f)
			{
				if (_state != ATK_SIT && _state != ATK_STAND)
				{
					this->ChangeState(new PlayerInjuredState());
					if (isReverse == true)
					{
						if (result.nx > 0)
							player->vx = NINJA_WALKING_SPEED;
						else
						{
							player->vx = -NINJA_WALKING_SPEED;
							Player::isReverse = false;
						}
					}
					else
						if (result.nx > 0)
						{
							player->vx = NINJA_WALKING_SPEED;
							player->isReverse = true;
						}
						else
							player->vx = -NINJA_WALKING_SPEED;
				}
				else if (_state == ATK_SIT || _state == ATK_STAND)
				{
					if (_curAnimation->isLastFrame == false)
					{
						o->isAttacked = true;
					}
				}
			}
		}
	}
	if (x < 0)
		x = 0;
	if (x >= 2048 - 20)
		x = 2048 - 20;

	//if (_state != SITTING) {
	//	if (y <= 56) {
	//		y = 56;
	//	}
	//}
}
void Player::CheckGroundCollision(unordered_set<Rect*> grounds)
{
	// Trên không
	if (this->vy)
	{
		this->isOnGround = false;
	}

	// Tìm được vùng đất va chạm
	if (DetectGround(grounds))
	{
		if (this->vy < 0)
		{
			this->isOnGround = true;
			this->vy = this->dy = 0;
			this->y = _curGround.y + (this->height >> 1);

			if (_state == ATK_STAND)
				this->_allow[RUNNING] = false;
		}
	}

	// Nếu không thì đang chạy -> rơi
	else if (!this->vy)
	{
		this->ChangeState(new PlayerFallingState());
	}
}

void Player::CheckWallCollision(std::unordered_set<Wall*> walls)
{

	if (this->vx && this->DetectWall(walls))
	{
		float wallLeft = wallBound.wall.x;
		float wallRight = wallLeft + wallBound.wall.width;
		float playerLeft = this->x - (this->width >> 1);
		float playerRight = this->x + (this->width >> 1);

		if (this->vx > 0 && playerRight > wallLeft && playerRight < wallRight)
		{
			this->vx = this->dx = 0;
			this->x = wallLeft - (this->width >> 1);

			if (wallBound.climbable && this->vy
				&& this->y + (this->height >> 1) <= wallBound.wall.y
				&& this->y - (this->height >> 1) >= wallBound.wall.y - wallBound.wall.height)
			{
				this->isReverse = false;
				this->ChangeState(new PlayerClingingState());
			}
		}
		else if (this->vx < 0 && playerLeft < wallRight && playerLeft > wallLeft)
		{
			this->vx = this->dx = 0;
			this->x = wallRight;

			if (wallBound.climbable && this->vy
				&& this->y + (this->height >> 1) <= wallBound.wall.y
				&& this->y - (this->height >> 1) >= wallBound.wall.y - wallBound.wall.height)
			{
				this->isReverse = true;
				this->ChangeState(new PlayerClingingState());
			}
		}
	}
}


void Player::Render(float cameraX, float cameraY)
{
	screenX = x - cameraX;
	screenY = cameraY - y;
	animations[_state]->isReverse = isReverse;
	animations[_state]->Render(screenX, screenY);
	/*this->RenderBoundingBox(x - cameraX, cameraY - y);*/
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
				/*player->y += 7;*/
				_state = STANDING;
			}
			break;
	}
}