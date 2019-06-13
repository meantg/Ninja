#pragma once
#include "CloakManBullet.h"

class EnemyBullet 
{
public:
	static Bullet* CreateBullet(TypeObject eType)
	{
		switch (eType) 
		{
		case E_CLOAKMAN: return new CloakManBullet();
		}
	}
};