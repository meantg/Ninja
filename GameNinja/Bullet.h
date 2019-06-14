#pragma once
#include "Object.h"
#include "Camera.h"

class Bullet : public Object
{
protected:
	unordered_map<State, LPANIMATION> animations;

	LPANIMATION activeAnimation;
	LPANIMATION deadAnimation;
	LPANIMATION _curAnimation;
public:

	State _state;

	Bullet()
	{
		this->tag = BULLET;
		this->deadAnimation = AnimationManager::GetInstance()->Get(E_CLOAKMAN, DEAD);
	}

	~Bullet() {}

	void Render(float cameraX, float cameraY)
	{
		screenX = x - cameraX;
		screenY = cameraY - y;
		if (isActive == true)
		{
			_curAnimation->isReverse = isReverse;
			_curAnimation->Render(screenX, screenY);
		}
		//this->RenderBoundingBox(screenX, screenY);
	}

	virtual void UpdateDistance(float dt)
	{
		this->dx = vx * dt;
		this->dy = vy * dt;
		this->x += dx;
		this->y += dy;
	}

	virtual void Update(float dt)
	{
		if (isFrozen)
			this->dx = this->dy = 0;
		else
		{
			this->UpdateDistance(dt);
			_curAnimation->Update(dt);
		}

		if (this->_state == DEAD)
		{
			this->vx = this->vy = 0;
			if (isFrozen)
				_curAnimation->Update(dt);
			if (_curAnimation->isLastFrame)
			{
				this->isDead = true;
			}
		}
	}

	void ChangeState(State StateName)
	{
		this->_state = StateName;
		switch (StateName)
		{
		case ATK_WITH_WEAPON:
		{
			_curAnimation = activeAnimation;
			this->isDead = false;
			break;
		}
		case DEAD:
		{
			_curAnimation = deadAnimation;
			break;
		}
		}
	}

	void AddAnimation(TypeObject _type, State _state)
	{
		LPANIMATION ani = AnimationManager::GetInstance()->Get(_type, _state);
		animations[_state] = ani;
	}

};