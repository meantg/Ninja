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

class GameMap
{
public:
	GameMap(const char* filePath);

	void SetCamera(Camera *camera);
	void Draw();

	~GameMap();

private:
	void LoadMap(const char* filePath);

	int **mapMatrix;
	int **isContain(int **matrix);
	int curX;
	Camera *mCamera;
};


