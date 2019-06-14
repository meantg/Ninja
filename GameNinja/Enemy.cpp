#include "Enemy.h"
#include "ScoreBoard.h"
Enemy::Enemy()
{
	this->tag = ENEMY;
	isDead = false;
	isActive = false;
	this->score = ENEMY_DEFAULT_SCORE;
}

void Enemy::Render(float cameraX, float cameraY)
{
	screenX = x - cameraX;
	screenY = cameraY - y;
	if (isActive == true)
	{
		animations[_state]->isReverse = isReverse;
		animations[_state]->Render(screenX, screenY);
	}
	//this->RenderBoundingBox(screenX,screenY);
}

void Enemy::Update(float dt)
{
	if (isFrozen)
		this->vx = this->vy = 0;
	else
	{
		this->UpdatePosition(dt);
		_curAnimation->Update(dt);
	}

	if (_state == DEAD)
	{
		this-> vx = this-> vy = 0;
		if (isFrozen)
			_curAnimation->Update(dt);
		if (_curAnimation->isLastFrame)
		{
			this->isDead = true;
			this->isActive = false;
		}
	}
}

void Enemy::UpdatePosition(float dt)
{
	this->dx = vx * dt;
	this->dy = vy * dt;
}

void Enemy::DetectGround(unordered_set<Rect*> grounds)
{
	for (auto g : grounds)
	{
		if (g->x < this->x && this->x < g->x + g->width
			&& g->y >= groundBound.y && this->y > g->y)
		{
			groundBound = *g;
		}
	}
	this->spawnY = this->y = this->groundBound.y + (this->height >> 1);
	
	}

bool Enemy::isFinishAttack()
{
	return (this->_state == ATTACKING && _curAnimation->isLastFrame);
}

Rect Enemy::GetSpawnRect()
{
	return Rect(spawnX, spawnY, width, height);
}

//bool Enemy::isOnScreen()
//{
//	RECT bCam = Camera::GetInstance()->GetBound();
//	if (bCam.right -20 >= x)
//		return true;
//	else return false;
//}

void Enemy::ChangeState(State StateName)
{
	switch (StateName)
	{
	case STANDING:
	{
		this->isOutScreen = false;
		this->isActive = false;
		this->isDead = false;
		this->isAttacked = false;
		break;
	}

	case RUNNING:
	{
		this->isActive = true;
		break;
	}
	case DEAD:
	{
		ScoreBoard::GetInstance()->score += this->score;
		break;
	}
	}

	this->_state = StateName;
	this->_curAnimation = animations[StateName];
}

void Enemy::AddAnimation(TypeObject _type,State _state)
{
	LPANIMATION ani = AnimationManager::GetInstance()->Get(_type, _state);
	animations[_state] = ani;
}
//
//Hitbox Enemy::GetHitBox()
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
