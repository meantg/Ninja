#pragma once
#include "Player.h"
#include "Object.h"
#include "Camera.h"

class Enemy : public Object
{
protected:
	unordered_map<State, LPANIMATION> animations;
	LPANIMATION _curAnimation;
public:
	float speed;
	State _state;
	bool isActive, isDoneAtk, isFrozen = false;
	int totalBullet, bullets;
	Enemy();
	~Enemy() {};

	void Render();
	virtual void Update(float dt);
	virtual void UpdatePosition(float dt);
	bool isOnScreen();
	virtual void ChangeState(State StateName);
	void AddAnimation(TypeObject _type,State _state);
};
