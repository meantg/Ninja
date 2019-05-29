#include "PlayScene.h"
#include "GameGlobal.h"


PlayScene::PlayScene(AnimationManager* gAnimationManager)
{
	Player::GetInstance()->ChangeState(new PlayerStandingState());
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
	mCamera = new Camera(SCREEN_WIDTH, mMap->mHeight);
	mCamera->SetPosition(0, SCREEN_HEIGHT >> 1);

	mMap->SetCamera(mCamera);
}

void PlayScene::Update(float dt)
{
	Player::GetInstance()->Update(dt);

	mCamera->SetPosition(Player::GetInstance()->GetPosition().x - (mCamera->GetWidth() >> 1  , SCREEN_HEIGHT);

	mMap->Update();

	/*if (mCamera->GetBound().right + 8 <= MapWidth)
	mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(8,0,0));*/
	/*if ((player->GetPosition().x >= SCREEN_WIDTH / 2) && (mCamera->GetBound().right + 32 <= MapWidth)) {
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR2(8, 0));
	}*/
	/*if(mCamera->GetBound().right == MapWidth)*/
}

// Tải Scene lên màn hình bằng cách vẽ các Sprite trong Scene
void PlayScene::Render()
{
	mMap->Render();
	Player::GetInstance()->Render(mCamera->GetPosition().x,mCamera->GetPosition().y);
}

void PlayScene::OnKeyDown(int keyCode)
{
	Player::GetInstance()->OnKeyDown(keyCode);
	//if (keyCode == VK_LEFT)
	//{
	//	if(mCamera->GetBound().left - 32 >= 0)
	//	mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR2(-32, 0));
	//}

	//if (keyCode == VK_RIGHT)
	//{
	//	if (mCamera->GetBound().right + 32 <= MapWidth)
	//		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR2(32, 0));
	//}
}

void PlayScene::OnKeyUp(int keyCode)
{
	Player::GetInstance()->OnKeyUp(keyCode);
}

