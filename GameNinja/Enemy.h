#pragma once
#include "Player.h"
#include "Object.h"
#include "Camera.h"
#include "EnemyBullet.h"
#include <unordered_set>
class Enemy : public Object
{

public:
	unordered_map<State, LPANIMATION> animations;
	LPANIMATION _curAnimation;
	Rect groundBound;

	float speed;
	State _state;
	bool isDoneAtk;
	int bulletCount, bulletTotal;
	Enemy();
	~Enemy() {};

	void Render(float cameraX, float cameraY);
	virtual void Update(float dt);
	virtual void UpdatePosition(float dt);
	virtual void DetectGround(unordered_set<Rect*> grounds);
	Rect GetSpawnRect();
	bool isOutScreen;
	virtual void ChangeState(State StateName);
	void AddAnimation(TypeObject _type,State _state);
	//Hitbox GetHitBox();
};
