#pragma once
#include <unordered_set>
#include "Player.h"
#include "ItemHolder.h"
#include "GameGlobal.h"

class Weapon : public Object
{
protected:
	LPANIMATION atkanim;
public:
	Weapon()
	{
		tag = WEAPON;
		if (player->isThrowing)
		{
			player->_allow[THROWING] = false;
		}
	}

	~Weapon() {};

	TypeObject weapontype = SWORD;
	virtual void Update(float dt) {}
	virtual void Render(float cameraX, float cameraY)
	{
		screenX = x - cameraX;
		screenY = cameraY - y;
		if (isActive == true)
		{
			atkanim->isReverse = isReverse;
			atkanim->Render(screenX, screenY);
		}
	}

	virtual void UpdateDistance(float dt)
	{
		this->dx = vx * dx;
		this->dy = vy * dy;
	}

	virtual void Update(float dt, unordered_set<Object*> colliableObj)
	{
		this->UpdateDistance(dt);

		this->x += vy * dt;
		this->y += vy * dt;

		atkanim->isReverse = this->isReverse;
		atkanim->Update(dt);

		auto r = this->GetRect();

		for (auto obj : colliableObj)
		{
			if (r.isContain(obj->GetRect()))
			{
				switch (obj->tag)
				{
				case BULLET:
				{
					auto bullet = (Bullet*)obj;
					bullet->ChangeState(DEAD);
					break;
				}
				case ENEMY:
				{
					auto enemy = (Enemy*)obj;
					enemy->ChangeState(DEAD);
					break;
				}
				case ITEMHOLDER:
				{
					auto itemholder = (ItemHolder*)obj;
					itemholder->isDead = true;
					break;
				}
				}
			}
		}
	}
};