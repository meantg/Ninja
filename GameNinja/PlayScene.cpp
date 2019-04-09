#include "PlayScene.h"
#include "GameGlobal.h"
Player *player;

PlayScene::PlayScene()
{
	_backColor = D3DCOLOR_XRGB(0, 255, 255);
	_timeCounter = 0;
}

PlayScene::~PlayScene()
{
	delete animations;
}

void PlayScene::Update(float dt)
{
	player->Update(dt);
}

// Tải Scene lên màn hình bằng cách vẽ các Sprite trong Scene
void PlayScene::Render()
{
	player->Render();
}

