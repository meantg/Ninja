#include "PlayScene.h"
#include "GameGlobal.h"
Player *player;

PlayScene::PlayScene(AnimationManager* gAnimationManager)
{
	player = new Player();
	_backColor = D3DCOLOR_XRGB(0, 255, 255);
	_timeCounter = 0;
	animations = gAnimationManager;
	LoadMap("MapReader/Map1_matrix.txt");
	MapWidth = 2048; MapHeight = 176;
}

PlayScene::~PlayScene()
{
	delete animations;
}

void PlayScene::LoadMap(const char * filePath)
{
	mMap = new GameMap(filePath);

	mCamera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT);
	mCamera->SetPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	mMap->SetCamera(mCamera);
}

void PlayScene::Update(float dt)
{
	player->Update(dt);
}

// Tải Scene lên màn hình bằng cách vẽ các Sprite trong Scene
void PlayScene::Render()
{
	mMap->Draw();
	player->Render();
}

void PlayScene::OnKeyDown(int keyCode)
{
	if (keyCode == VK_LEFT)
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(-30, 0, 0));
	}

	if (keyCode == VK_RIGHT)
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(30, 0, 0));
	}

	if (keyCode == VK_UP)
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(0, -10, 0));
	}

	if (keyCode == VK_DOWN)
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(0, 10, 0));
	}
}

void PlayScene::OnKeyUp(int keyCode)
{
}

