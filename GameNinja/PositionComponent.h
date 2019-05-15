#pragma once
#include "Component.h"
#include "VelocityComponent.h"
class VelocityComponent a;

class PositionComponent : public Component 
{
protected:
	float x;
	float y;
public:
	PositionComponent(float x = 0, float y = 0) 
	{
		this->x = x;
		this->y = y;
	}

	void Update()
	{
		this->x += a.Getvx();
		this->y += a.Getvy();
	}
	~PositionComponent() {}
};