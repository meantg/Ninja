#pragma once
#include "GameGlobal.h"
#include <vector>
#include "Object.h"
#include "Collision.h"
#include <unordered_set>

class Cell {
private:
	int xID, yID;
	RECT rect;
public:
	static int _cellwidth, _cellheight;
	unordered_set<Object*>objects;
	vector<Wall*> walls;
	vector<Ground*> grounds;

	Cell(int xID, int yID);

	void RemoveObject(Object *obj);
	bool isContain(RECT r);

	~Cell();

};