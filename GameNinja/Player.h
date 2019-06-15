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

	int health;
	int energy;
	int lives;

	void SetHealth(int health);
	void SetEnergy(int energy);

	Wall wallBound;
	Rect _curGround;
	TypeObject weaponType;
	bool isStanding = true, isOnGround, isThrowing = false;
	bool DetectCurGround(unordered_set<Rect*> grounds);
	bool DetectWall(unordered_set<Wall*> walls);
	void CheckGroundCollision(unordered_set<Rect*> grounds);
	void CheckWallCollision(std::unordered_set<Wall*> walls);
	unordered_map<State, bool> _allow;

	static Player* GetInstance();


	void Update(float dt, unordered_set<Object*> gameObj);
	void Render(float cameraX= 0, float cameraY= 0);
	void AddAnimation(State _state);
	void ChangeState(PlayerState * playerstate);

	void SetWeapon(TypeObject weapon);

	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};
