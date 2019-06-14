#pragma once
#include "Weapon.h"

class BlueShuriken : public Weapon
{
	BlueShuriken()
	{
		width = WEAPON_BLUESHURIKEN_WIDTH;
		height = WEAPON_BLUESHURIKEN_HEIGHT;
		vx = WEAPON_BLUESHURIKEN_SPEED;
		vy = 0;
		weapontype = BLUESHURIKEN;
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
					if (bullet->_state!= DEAD)
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
