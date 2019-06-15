#pragma once
#include "Weapon.h"

class RedShuriken : public Weapon
{
private:
	bool isOut;
public:
	RedShuriken()
	{
		atkanim = AnimationManager::GetInstance()->Get(WEAPON, ATK_WITH_REDSHURIKEN);
		width = WEAPON_REDSHURIKEN_WIDTH;
		height = WEAPON_REDSHURIKEN_HEIGHT;
		vx = WEAPON_BLUESHURIKEN_SPEED;
		vy = 0;
		weapontype = REDSHURIKEN;
	}
	~RedShuriken() {};

	void UpdateDistance(float dt)
	{
		dx = vx * dt;
		dy = 1.5 * (player->x - this->y) / MAX_FRAME_RATE;

		if (this->x > player->x)
		{
			if (vx > 0)
			{
				dx = min(12.0f, dx);
			}
			vx -= 0.45f;

			if (this->isReverse)
			{
				dy -= 0.8f;
			}
			else dy += 0.8f;
		}
		else
		{
			if (vx < 0)
			{
				dx = max(-12.0f, dx);
			}
			vx += 0.45f;

			if (this->isReverse)
			{
				dy += 0.8;
			}
			else dy -= 0.8f;
		}

		if (this->GetRect().isContain(player->GetRect()))
		{
			if (!isOut)
			{
				isOut = true;
				this->x = player->y + (isReverse ? -player->width : player->width);
			}
			else isDead = true;
			this->dx = vx * dt;
			this->dy = vy * dt;
		}
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