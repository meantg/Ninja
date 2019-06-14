#pragma once
#include "Object.h"
#include <unordered_set>

class Item : public Object
{
public:
	LPSPRITE _sprite;
	Rect _curGround;
	float speedY;

	Item(float spawnX, float spawnY);
	~Item();
	void DectectGround(unordered_set<Rect*>);
	void Update(float dt);
	void Render();
};