#pragma once

class Component
{
private:
	int Cid;
public:
	Component() {}

	int GetComponentType() { return Cid; }
	virtual void Update();

	~Component() {}
};

