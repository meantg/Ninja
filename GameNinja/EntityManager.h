#pragma once
#include "Object.h"
#include "Component.h"

class EntityManager {
private:
	static EntityManager *_instance;
	unordered_map<int,Entity> entities;
public:
	static EntityManager *GetInstance();
	Entity GetEntity();

};
