#pragma once
#include "AnimationManager.h"
#include "Scene.h"
#include "Player.h"
#include "Game.h"
#include "Camera.h"
#include "GameMap.h"

class PlayScene : public Scene
{
private:
	AnimationManager *animations;
	float _timeCounter;			
	
	Camera *mCamera;
	GameMap *mMap;

	int MapWidth, MapHeight;
	// Counter nhằm Update Scene sau một khoảng thời gian
public:

	PlayScene(AnimationManager *gAnimationManager);		// Load các resources cần thiết để khởi tạo Scene
	~PlayScene();

	void LoadMap(const char *filePath);
	virtual void Update(float dt);							// Update các thông số các đối tượng trong Scene
	void Render();									// Tải Scene lên màn hình

	void OnKeyDown(int key);
	void OnKeyUp(int key);
};