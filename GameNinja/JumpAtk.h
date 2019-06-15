#pragma once
#include "Weapon.h"

class JumpAtk : public Weapon
{
	JumpAtk()
	{
		atkanim = AnimationManager::GetInstance()->Get(WEAPON, ATK_WITH_ROUNDSWORD);
		width = WEAPON_ROUNDSWORD_WIDTH;
		height = WEAPON_ROUNDSWORD_HEIGHT;
		vx = vy = 0;
		weapontype = ROUNDSWORD;
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