#pragma once
#include "GameGlobal.h"
#include <vector>
#include "Object.h"
#include "Cell.h"
#include "Camera.h"
#include "Player.h"
#include "ESwordMan.h"
#include "ECloakMan.h"
#include "EBazoka.h"
#include "EEagle.h"
#include "EPanther.h"
#include "EGunMan.h"

#include "IHButterfly.h"

#include "IBlueBag.h"
#include "IBlueShuriken.h"
#include "IBlueSpirit.h"
#include "IFireWheel.h"
#include "IGlassHour.h"
#include "IHealthPotion.h"
#include "IRedBag.h"
#include "IRedShuriken.h"
#include "IRedSpirit.h"


class Grid {
private:
	vector<vector<Cell*>> _cells;
	int rows, columns;
public:
	vector<Cell*> visibleCells;
	unordered_set<Object*> respawnObjects;

	Grid(int mapWidth, int mapHeight);
	~Grid();
	void AddObject(Object *obj);
	void RemoveObject(Object *obj);
	void MoveObject(Object* obj, float x, float y);
	void RespawnEnemies();
	void Update();
	void UpdateVisibleCells(Rect viewport);

	void AddGround(Rect *g);
	void AddWall(Wall *w);
	//void RespawnEnemies();
	//Get nearby Object
	unordered_set<Object*> GetColliableObjects(Object * obj);
	unordered_set<Wall*> GetColliableWalls(Object *obj);
	unordered_set<Rect*> GetColliableGrounds(Object *obj);

	//Get all object in viewport
	unordered_set<Object*> GetVisibleObjects();
	unordered_set<Wall*> GetVisibleWalls();
	unordered_set<Rect*> GetVisibleGrounds();

	
};