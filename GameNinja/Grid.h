#pragma once
#include "GameGlobal.h"
#include <vector>
#include "Object.h"
#include "Cell.h"
class Grid {
private:
	vector<vector<Cell*>> _cells;
	int rows, columns;
public:
	Grid(int mapWidth, int mapHeight);
	~Grid();
	void AddObject(Object *obj);
	void RemoveObject(Object *obj);
	void MoveObject(Object* obj, float x, float y);

	void Update();

	//Get nearby Object
	unordered_set<Object*> GetColliableObjects(Object * obj);
	unordered_set<Wall*> GetColliableWalls(Object *obj);
	unordered_set<Ground*> GetColliableGrounds(Object *obj);

	//Get all object in viewport
	unordered_set<Object*> GetVisibleObjects();
	unordered_set<Wall*> GetVisibleWalls();
	unordered_set<Ground*> GetVisibleGrounds();

};