#pragma once
#include "Object.h"
#include "PlayerState.h"
#include "PositionComponent.h"
#include "RigidBodyComponent.h"
#include "StatsComponent.h"
#include "VelocityComponent.h"
#include <map>

class Player : public Object
{
private:
	static Player* _instance;
public:
	Player();
	~Player();

	float vx, vy, nx, width, height;
	LPANIMATION _curanimation;
	State _state, _lastState;
	static Player* GetInstance();
	PlayerState* state;
	State stateName;
	bool isReverse = false;

	void Allow(State state, bool flag);
	void Update(DWORD dt);
	void Render();
	void AddAnimation(State _state);
	void SetState(State state);
	void ChangeState(PlayerState* playerstate);

	void SetWidth(float _width) { width = _width; }
	void SetHeight(float _height) { height = _height; }
	State GetState() { return _state; }
	D3DXVECTOR3 GetPosition() { return D3DXVECTOR3(x, y, 0); }
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};

class Ninja : public Entity
{
private:
	static Ninja * _instance;
protected:
	PositionComponent *mPos;
	VelocityComponent *mVelo;
	RigidBodyComponent *mRigid;
	StatsComponent *mStats;

public:
	Ninja();
	~Ninja();

	bool Reverse = false;
	State _state, _lastState;
	PlayerState* state;
	State stateName;

	void Update(float dt);
	void Render();
	TypeObject getType() { return PLAYER; }
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
	static Ninja * GetInstance();
}; 
