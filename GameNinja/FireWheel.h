#pragma once
#include "Weapon.h"

class FireWheel : public Weapon
{
	FireWheel()
	{
		atkanim = AnimationManager::GetInstance()->Get(WEAPON, ATK_WITH_FIREWHEEL);
		width = WEAPON_FIREWHEEL_WIDTH;
		height = WEAPON_FIREWHEEL_HEIGHT;
		vx = WEAPON_FIREWHEEL_SPEED;
		vy = 0;
		weapontype = FIREWHEEL;
	}

	void UpdateDistance(float dt)
	{
		this->dx = vx * dt;
		this->dy = vy * dt;
	}

	void Update(float dt, unordered_set<Object*> colliableObj)
	{
		Object::Update(dt);
		this->atkanim->Update(dt);

		for (auto obj : colliableObj)
		{
			if (this->GetRect().isContain(obj->GetRect()))
			{
				switch (obj->tag)
				{
				case BULLET:
				{
					auto bullet = (Bullet*)obj;
					if (bullet->_state != DEAD)
					{
						bullet->ChangeState(DEAD);
						this->isDead = true;
						break;
					}
				}

				case ENEMY:
				{
					auto enemy = (Enemy*)obj;
					enemy->ChangeState(DEAD);
				}

				case ITEMHOLDER:
				{
					auto iholder = (ItemHolder*)obj;
					iholder->isDead = true;
					this->isDead = true;
					break;
				}
				}

				if (this->isDead) return;
			}
		}
	}
};