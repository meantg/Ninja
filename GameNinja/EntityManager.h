#pragma once
#include "Object.h"
#include "Component.h"

class EntityManager {
private:
	static EntityManager *_instance;
	vector<Entity> _entities;
	vector<Component> _components;


};