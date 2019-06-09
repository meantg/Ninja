#include "Collision.h"

Collision * Collision::_instance = NULL;

Collision * Collision::GetInstance()
{
	if (_instance == NULL) _instance = new Collision();
	return _instance;
}

bool Collision::isCollision(Hitbox obj1, Hitbox obj2)
{
	float left = obj2.x - (obj1.x + obj1.width);
	float top = (obj2.y + obj2.height) - obj1.y;
	float right = obj2.x + obj2.width - obj1.x;
	float bottom = obj2.y - (obj1.y + obj1.height);
	return !(left > 0 || right < 0 || top < 0 || bottom > 0);
}

CollisionResult Collision::SweptAABB(Hitbox obj1, Hitbox obj2)
{
	CollisionResult result;

	result.entryTime = 1.0f;
	result.nx = result.ny = 0;

	Hitbox rect = GetBroadphaseBox(obj1);

	if (!isCollision(rect, obj2)) {
		return result;
	}

	if (obj1.vx > 0.0f) {
		dxEntry = obj2.x - (obj1.x + obj1.width);
		dxExit = (obj2.x + obj2.width) - obj1.x;
	}
	else {
		dxEntry = (obj2.x + obj2.width) - obj1.x;
		dxExit = obj2.x - (obj1.x + obj1.width);
	}


	if (obj1.vy > 0.0f) {
		dyEntry = obj2.y - (obj1.y + obj1.height);
		dyExit = (obj2.y + obj2.height) - obj1.y;
	}
	else {
		dyEntry = (obj2.y + obj2.height) - obj1.y;
		dyExit = obj2.y - (obj1.y + obj1.height);
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
	broadphaseBox.x = obj.vx > 0 ? obj.x : obj.x + obj.vx;
	broadphaseBox.y = obj.vy > 0 ? obj.y : obj.y + obj.vy;
	broadphaseBox.width = obj.width + abs(obj.vx);
	broadphaseBox.height = obj.height + abs(obj.vy);
	return broadphaseBox;

}
