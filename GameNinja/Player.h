#pragma once
#include "Object.h"
#include "PlayerState.h"
#include "PlayerStandingState.h"
#include "PlayerInjuredState.h"
#include "Camera.h"
#include <map>
#include "GameGlobal.h"

class Player : public Object
{
private:
	static Player * _instance;
	unordered_map<State, LPANIMATION> animations;
public:
	Player();
	~Player();

	float vx, vy, maxy;

	LPANIMATION _curAnimation;
	State _state;
	PlayerState* state;

	bool isReverse = false, isStanding = true, isOnGround;
	unordered_map<State, bool> _allow;

	static Player* GetInstance();

	Hitbox GetHitbox();
	void Allow(State state, bool flag);
	void Update(float dt);
	void Render(float cameraX= 0, float cameraY= 0);
	void AddAnimation(State _state);
	void ChangeState(PlayerState * playerstate);

	//void SetState(State state);	//void SetState(State state);
	//void SetWidth(float _width) { width = _width; }
	//void SetHeight(float _height) { height = _height; }
	//State GetState() { return _state; }
	//D3DXVECTOR3 GetPosition() { return D3DXVECTOR3(x, y, 0); }
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};
