#pragma once
#include "Object.h"
#include "PlayerState.h"
#include "PlayerStandingState.h"
#include "PlayerInjuredState.h"
#include "Camera.h"
#include <map>
#include "Enemy.h"
#include "GameGlobal.h"
#include "Collision.h"
#include <unordered_set>

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
	Ground *_curGround;
	bool isStanding = true, isOnGround;
	bool DetectGround(unordered_set<Ground*> grounds);

	void CheckGroundCollision(unordered_set<Ground*> grounds);

	unordered_map<State, bool> _allow;

	static Player* GetInstance();


	void Update(float dt, vector<Object*> gameObj);
	void Render(float cameraX= 0, float cameraY= 0);
	void AddAnimation(State _state);
	void ChangeState(PlayerState * playerstate);

	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};
