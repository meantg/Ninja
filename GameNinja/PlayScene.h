﻿#pragma once
#include "AnimationManager.h"
#include "Scene.h"
#include "Object.h"
#include "Game.h"
#include "Camera.h"
#include "GameMap.h"
#include "ScoreBoard.h"
#include "Bullet.h"
#include <unordered_set>
#include "Grid.h"
class PlayScene : public Scene
{
private:
	AnimationManager *animations;
	float _timeCounter;			
	
	Camera *mCamera;
	GameMap *mMap;
	ScoreBoard *scoreboard;
	Grid *grid;

	int MapWidth, MapHeight;

	vector<Object*> enemy;
	unordered_set<Object*> listObj;
	unordered_set<Ground*> grounds;
	// Counter nhằm Update Scene sau một khoảng thời gian
public:

	PlayScene(AnimationManager *gAnimationManager);		// Load các resources cần thiết để khởi tạo Scene
	~PlayScene();

	void LoadMap(const char *filePath);
	virtual void Update(float dt);	// Update các thông số các đối tượng trong Scene
	void UpdateObject(float dt);
	void UpdatePlayer(float dt);
	void Render();									// Tải Scene lên màn hình

	void OnKeyDown(int key);
	void OnKeyUp(int key);
};