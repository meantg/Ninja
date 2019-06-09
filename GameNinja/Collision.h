#pragma once
#include "GameGlobal.h"
struct Hitbox {
	float x, y, width, height;
	float vx, vy;
};

struct CollisionResult {
	float nx, ny;
	float entryTime;
};

class Collision {
private:
	float dxEntry, dxExit;
	float dyEntry, dyExit;
	float txEntry, tyEntry;
	float txExit, tyExit;
	float entryTime;
	float exitTime;

	static Collision* _instance;

public:
	static Collision *GetInstance();
	bool isCollision(Hitbox obj1, Hitbox obj2);
	CollisionResult SweptAABB(Hitbox obj1, Hitbox obj2);
	Hitbox GetBroadphaseBox(Hitbox obj);
};