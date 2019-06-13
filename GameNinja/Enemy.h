#pragma once
#include "Player.h"
#include "Object.h"
#include "Camera.h"
#include "EnemyBullet.h"
#include "CloakManBullet.h"

class Enemy : public Object
{

public:
	unordered_map<State, LPANIMATION> animations;
	LPANIMATION _curAnimation;

	TypeObject tag;
	float speed;
	State _state;
	bool isDoneAtk;
	int bulletCount, bulletTotal;
	Enemy();
	~Enemy() {};

	void Render(float cameraX, float cameraY);
	virtual void Update(float dt);
	virtual void UpdatePosition(float dt);
	bool isOnScreen();
	virtual void ChangeState(State StateName);
	void AddAnimation(TypeObject _type,State _state);
	//Hitbox GetHitBox();
};
