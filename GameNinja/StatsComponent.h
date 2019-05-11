#pragma once
#include "Component.h"
class StatsComponent : public Component {
private:
	float hp;
	float maxHP;
	float mp;
	float maxMP;
public:
	StatsComponent(float hp = 1, float maxHP = 1, float mp = 0, float maxMP = 0) {
		this->hp = hp;
		this->maxHP = maxHP;
		this->mp = mp;
		this->maxMP = maxMP;
	}
	~StatsComponent() {}
};