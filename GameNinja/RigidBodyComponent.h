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

	float GetWitdh(TypeObject _type,State _curState)
	{
		return AnimationManager::GetInstance()->Get(_type, _curState)->GetcurFrame()->GetSprite()->getWidth();
	}

	float GetHeight(TypeObject _type, State _curState)
	{
		return AnimationManager::GetInstance()->Get(_type, _curState)->GetcurFrame()->GetSprite()->getHeight();
	}
	~RigidBodyComponent() {}
};