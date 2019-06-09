#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <vector>

#include "SpriteManager.h"
#include "GameGlobal.h"
#include "Camera.h"
#include <iostream>
#include <fstream>
#include "string"
#include <math.h>

// Entity
#include "ESwordMan.h"
#include "IHButterfly.h"
#include "ECloakMan.h"

class GameMap
{
public:
	GameMap(const char* filePath);
	int mWidth, mHeight;
	void SetCamera(Camera *camera);
	void Update(float dt);
	void Render();
	int getRow();
	int getColumn();
	~GameMap();

private:
	void LoadMap(const char* filePath);

	//Test Entity
	IHButterfly *butterfly;
	ECloakMan *cloakMan;

	int **mapMatrix;
	int rows, columns;
	int cBegin, cEnd;

	Camera *mCamera;
};



