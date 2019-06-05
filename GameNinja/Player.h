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

	LPANIMATION _curAnimation;
	State _state;
	PlayerState* state;

	bool isStanding = true, isOnGround;
	unordered_map<State, bool> _allow;

	static Player* GetInstance();

	Hitbox GetHitbox();
	void Update(float dt);
	void Render(float cameraX= 0, float cameraY= 0);
	void AddAnimation(State _state);
	void ChangeState(PlayerState * playerstate);

	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};
