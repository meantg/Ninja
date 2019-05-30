#pragma once
#include "Object.h"
#include "PlayerState.h"
#include "PlayerStandingState.h"
#include "PlayerInjuredState.h"
#include "Camera.h"
#include <map>

class Player : public Object
{
private:
	static Player * _instance;
public:
	Player();
	~Player();

	float vx, vy, nx, width, height;
	LPANIMATION _curanimation ;
	State _state, _lastState;
	static Player* GetInstance();
	PlayerState* state;
	State stateName;
	bool isReverse = false, isStanding = true;

	void Allow(State state, bool flag);
	void Update(DWORD dt);
	void Render(float cameraX= 0, float cameraY= 0);
	void AddAnimation(State _state);
	void SetState(State state);
	void ChangeState(PlayerState * playerstate);

	void SetWidth(float _width) { width = _width; }
	void SetHeight(float _height) { height = _height; }
	State GetState() { return _state; }
	D3DXVECTOR3 GetPosition() { return D3DXVECTOR3(x, y, 0); }
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};
