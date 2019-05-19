#pragma once
#include "Component.h"
#include "VelocityComponent.h"

class PositionComponent : public Component 
{
public:
	float x;
	float y;
	float maxx;
	float maxy;
	PositionComponent(float x = 0, float y = 0,float maxx=0,float maxy=0) 
	{
		this->x = x;
		this->y = y;
		this->maxx = maxx;
		this->maxy = maxy;
	}

	void Update(float dt,VelocityComponent *_veloc)
	{
		this->x += _veloc->Getvx();
		this->y += _veloc->Getvy();
	}
	~PositionComponent() {}
};