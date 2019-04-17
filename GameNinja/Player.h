#pragma once
#include "Object.h"
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

	void HandleKeyboard(map<int, bool> keyCode);
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};
