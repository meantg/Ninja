#pragma once
#include "Component.h"
class RigidBodyComponent : public Component {
private:
	float width;
	float height;
public:
	RigidBodyComponent(float width = 0, float height = 0) {
		this->width = width;
		this->height = height;
	}
	~RigidBodyComponent() {}
};