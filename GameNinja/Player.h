#pragma once
#include "Object.h"
#include "Component.h"
#include "PositionComponent.h"
#include "RigidBodyComponent.h"
#include "StatsComponent.h"
#include "VelocityComponent.h"
#include <map>

class Player : public Object
{
protected:
	float vx, vy, nx, width, height;
	LPANIMATION _curanimation;
	State _state;
	bool isReverse = false;
	
public:
	Player();
	~Player();

	void Allow(State state, bool flag);
	void Update(DWORD dt);
	void Render();
	void AddAnimation(State _state);
	void SetState(State state);

	void SetWidth(float _width) { width = _width; }
	void SetHeight(float _height) { height = _height; }
	State GetState() { return _state; }
	D3DXVECTOR3 GetPosition() { return D3DXVECTOR3(x, y, 0); }
	void HandleKeyboard(map<int, bool> keyCode);
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};

class Ninja : public Entity
{
protected:
	PositionComponent *mPos;
	VelocityComponent *mVelo;
	RigidBodyComponent *mRigid;
	StatsComponent *mStats;
public:
	Ninja();
	~Ninja();

	void Update();
	void Render();
	TypeObject getType() { return PLAYER; }
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);

};
