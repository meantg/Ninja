#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <vector>
#include "Sprite.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "Collision.h"

using namespace std;

class Object
{

public:
	Object();


	float x, y;
	int width, height;
	RECT GetRect();
	//State _curState;
	//bool isOnGround = true;
	//void SetPosition(float x, float y) { this->x = x; this->y = y; }
	//void SetState(State _state) { this->_curState = _state; }

	//virtual void AddAnimation(State _state);
	virtual Hitbox GetHitbox() { return Hitbox(); };
	virtual void Update(float dt);
	virtual void Render();
	~Object();
};





// GameObject: chứa type để quản lý, những class object sẽ kế thừa, và return type khác nhau.
// GameObject: có thể có các thuộc tính như: vị trí, vận tốc, sprites, enable, disable theo grid, Physics(collision)
// Player: vị trí, tốc độ, tốc độ đánh, vũ khí, animation, input, rigid body, máu, năng lượng
// Enemies: vị trí, tốc độ, tốc độ đánh, AI, enable, disable theo grid, rigid body, máu
// Tường: vị trí, rigid body
// Đất: vị trí, rigid body
// Ô vật phẩm: vị trí, rigid body, chứa item nào?
// Các items như vũ khí: animation khác nhau, năng lượng tiêu tốn khi sử dụng, tốc độ, input, dame,
