#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <vector>
#include "Sprite.h"
#include "Animation.h"
#include "AnimationManager.h"

class Object
{
protected:
	float x, y;
	float vx;

	State _curState;

	unordered_map<State, LPANIMATION> animations;
public:
	void SetPosition(float x, float y) { this->x = x; this->y = y; }
	void SetState(State _state) { this->_curState = _state; }
	void AddAnimation(State _state);

	Object();

	virtual void Update(DWORD dt);
	virtual void Render();
	~Object();
};
