#include "Collision.h"

Collision * Collision::_instance = NULL;

Collision * Collision::GetInstance()
{
	if (_instance == NULL) _instance = new Collision();
	return _instance;
}

bool Collision::isCollision(Hitbox obj1, Hitbox obj2)
{
	return !(obj1.left > obj2.right || obj1.right < obj2.left || obj1.top > obj2.bottom || obj1.bottom < obj2.top);
}

CollisionResult Collision::SweptAABB(Hitbox obj1, Hitbox obj2)
{
	CollisionResult result;

	result.entryTime = 1.0f;
	result.nx = result.ny = 0;

	obj1.vx = obj1.vx - obj2.vx;
	obj2.vy = obj1.vy - obj2.vy;

	Hitbox rect = GetBroadphaseBox(obj1);

	if (!isCollision(rect, obj2)) {
		return result;
	}

	if (obj1.vx > 0.0f) {
		dxEntry = obj2.left - obj1.right;
		dxExit = obj2.right - obj1.left;
	}
	else {
		dxEntry = obj2.right - obj1.left;
		dxExit = obj2.left - obj1.right;
	}

		
	if (obj1.vy > 0.0f) {
		dyEntry = obj2.top - obj1.bottom;
		dyExit = obj2.bottom - obj1.top;
	}
	else {
		dyEntry = obj2.bottom - obj1.top;
		dyExit = obj2.top - obj1.bottom;
	}

	if (obj1.vx == 0.0f) {
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else {
		txEntry = dxEntry / obj1.vx;
		txExit = dxExit / obj1.vx;
	}

	if (obj1.vy == 0.0f) {
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else {
		tyEntry = dyEntry / obj1.vy;
		tyExit = dyExit / obj1.vy;
	}

	entryTime = max(txEntry, tyEntry);
	exitTime = min(txExit, tyExit);

	// Nếu không có va chạm
	if (entryTime > exitTime || (txEntry < 0.0f && tyEntry < 0.0f) || txEntry > 1.0f || tyEntry > 1.0f)
	{
		return result;
	}
	// Nếu có trả về thời gian bắt đầu va chạm
	else {
		result.entryTime = entryTime;
		if (txEntry > tyEntry) {
			result.nx = dxEntry < 0.0f ? 1 : -1;		
		}
		else {
			result.ny = dyEntry < 0.0f ? 1 : -1;
		}
		return result;
	}
}

Hitbox Collision::GetBroadphaseBox(Hitbox obj)
{
	Hitbox broadphaseBox;
	broadphaseBox.left = obj.vx > 0 ? obj.left : obj.left + obj.vx;
	broadphaseBox.top = obj.vy > 0 ? obj.top : obj.top + obj.vy;
	broadphaseBox.right = broadphaseBox.left + obj.right - obj.left + abs(obj.vx);
	broadphaseBox.bottom = broadphaseBox.top + obj.bottom - obj.top + abs(obj.vy);
	return broadphaseBox;

}
