#pragma once
#include "Component.h"
class PositionComponent : public Component {
private:
	float x;
	float y;
public:
	PositionComponent(float x = 0, float y = 0) 
	{
		this->x = x;
		this->y = y;
	}
	~PositionComponent() {}
};