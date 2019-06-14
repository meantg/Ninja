#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <vector>
#include "Sprite.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "Collision.h"
#include "GameGlobal.h"
#include <unordered_set>
using namespace std;

class Object
{

public:
	Object();
	TypeObject type,tag;

	float x, y;
	float screenX, screenY;
	float vx, vy;
	float dx, dy;
	float spawnX, spawnY;
	int width, height;
	bool isDead, isAttacked = false, isReverse = false, isFrozen = false, isActive = false ;
	Rect GetRect();


	//State _curState;
	//bool isOnGround = true;
	//void SetPosition(float x, float y) { this->x = x; this->y = y; }
	//void SetState(State _state) { this->_curState = _state; }

	Hitbox GetHitbox() {
		Hitbox box;
		box.x = x;
		box.y = y;
		box.width = width;
		box.height = height;
		box.vx = vx;
		box.vy = vy;
		return box;
	};
	virtual void DetectGround(unordered_set<Rect*> grounds) {}
	virtual void Update(float dt);
	virtual void Render(float cameraX, float cameraY);
	void RenderBoundingBox(float x, float y);
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
