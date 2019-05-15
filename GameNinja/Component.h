#pragma once
#include "GameGlobal.h"

class Component
{
private:
	int Cid;
public:
	Component() {}

	int GetComponentType() { return Cid; }
	static void Update();

	~Component() {}
};

