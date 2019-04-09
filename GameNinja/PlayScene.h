#pragma once
#include "AnimationManager.h"
#include "Scene.h"
#include "Player.h"
#include "Game.h"

class PlayScene : public Scene
{
private:
	AnimationManager *animations;
	float _timeCounter;								// Counter nhằm Update Scene sau một khoảng thời gian
public:

	PlayScene();		// Load các resources cần thiết để khởi tạo Scene
	~PlayScene();

	virtual void Update(float dt);							// Update các thông số các đối tượng trong Scene
	void Render();									// Tải Scene lên màn hình
};