#include "ECloakMan.h"

ECloakMan::ECloakMan(float spawnX, float spawnY)
{
	this->_state = RUNNING;
	this->AddAnimation(E_CLOAKMAN, STANDING);
	this->AddAnimation(E_CLOAKMAN, RUNNING);
	this->AddAnimation(E_CLOAKMAN, ATTACKING);
	this->AddAnimation(E_CLOAKMAN, DEAD);

	this->type = E_CLOAKMAN;

	this->width = ENEMY_SWORDMAN_WIDTH;
	this->height = ENEMY_SWORDMAN_HEIGHT;
	this->bulletTotal = bulletCount = BULLET_CLOAKMAN_COUNT;
	this->delayTime = ENEMY_CLOAKMAN_DELAY;
	this->speed = ENEMY_CLOAKMAN_SPEED;
	this->score = ENEMY_CLOAKMAN_SCORE;

	this->spawnX = this->x = spawnX;
	this->spawnY = this->y = spawnY;


}

void ECloakMan::UpdatePosition(float dt)
{
 	delayTime -= dt * 100;
	if (player->x < this->x)
		this->isReverse = true;
	else
		this->isReverse = false;
	switch (this->_state) {
	case RUNNING:
	{
		this->dx = vx * dt;

		if ((vx > 0 && this->x + (this->width >> 1) >= groundBound.x + groundBound.width)
			|| (vx < 0 && this->x - (this->width >> 1) <= groundBound.x))
		{
			this->vx = -vx;
		}
		if (delayTime <= 0)
		{
			ChangeState(ATTACKING);
			this->vx = -vx;
			delayTime = ENEMY_CLOAKMAN_DELAY;
		}
	}
	case ATTACKING:
	{
		this->dx = 0;
		break;
	}
	}
}

void ECloakMan::Update(float dt)
{
	Enemy::Update(dt);
	if (this->isDead) {
		delayTime = ENEMY_CLOAKMAN_DELAY;
	}
}

	
