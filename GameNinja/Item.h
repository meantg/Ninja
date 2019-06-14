#pragma once
#include "Object.h"
#include <unordered_set>

class Item : public Object
{
public:
	LPSPRITE _sprite;
	Rect groundBound;
	float speedY;

	Item();
	void DectectGround(unordered_set<Rect*> grounds);
	void Update(float dt);
	void Render();
};