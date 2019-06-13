#pragma once
#include "CloakManBullet.h"
#include "GunManBullet.h"

class EnemyBullet 
{
public:
	static Bullet* CreateBullet(TypeObject eType)
	{
		switch (eType) 
		{
		case E_GUNMAN: return new GunManBullet();
		case E_CLOAKMAN: return new CloakManBullet();
		}
	}
};