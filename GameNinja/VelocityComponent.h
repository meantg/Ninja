#pragma once
#include "Component.h"

class VelocityComponent : public Component
{
protected:
	float vx;
	float vy;
	float _gravity;
public:
	VelocityComponent(float vx = 0, float vy = 0, float _gravity = 0)
	{
		this->vx = vx;
		this->vy = vy;
		this->_gravity = _gravity;
	}

	float Getvx() { return vx; }
	float Getvy() { return vy; }

	~VelocityComponent() {}

};