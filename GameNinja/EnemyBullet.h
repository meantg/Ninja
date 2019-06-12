#pragma once
#include "Enemy.h"

class EnemyBullet : public Enemy
{
private:

	int countbullet;
public:
	EnemyBullet();
	~EnemyBullet();

	virtual void Update(float dt);
	virtual void Render();
};