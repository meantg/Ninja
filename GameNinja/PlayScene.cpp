#include "PlayScene.h"
#include "GameGlobal.h"
#include "Collision.h"


PlayScene::PlayScene(AnimationManager* gAnimationManager)
{
	Player::GetInstance()->ChangeState(new PlayerStandingState());
	_backColor = D3DCOLOR_XRGB(0, 255, 255);
	_timeCounter = 0;
	animations = gAnimationManager;
	LoadMap("MapReader/Map1_matrix.txt");
	MapWidth = 2048; MapHeight = 176;
	enemy.push_back(new ESwordMan(300, 56));
	enemy.push_back(new ECloakMan(1230, 123));
}

PlayScene::~PlayScene()
{
	delete animations;
}

void PlayScene::LoadMap(const char * filePath)
{
	mMap = new GameMap(filePath);
	mCamera = new Camera(SCREEN_WIDTH, mMap->mHeight);
	scoreboard = new ScoreBoard();

	//Goc toa do camera la bottom left
	mCamera->SetPosition(0, SCREEN_HEIGHT);

	mMap->SetCamera(mCamera);
}

void PlayScene::Update(float dt)
{
	mCamera->SetPosition(Player::GetInstance()->x - (mCamera->GetWidth() >> 1), SCREEN_HEIGHT);
	mMap->Update(dt);
	scoreboard->Update(dt);
	for (auto i = 0; i < enemy.size(); ++i)
		enemy[i]->Update(dt);
	Player::GetInstance()->Update(dt, enemy);

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
	scoreboard->Render();
	Player::GetInstance()->Render(mCamera->GetPositionX(),mCamera->GetPositionY());
	for (auto i = 0; i < enemy.size(); ++i)
		enemy[i]->Render(mCamera->GetPositionX(), mCamera->GetPositionY());
	//mCamera->SetPosition(Player::GetInstance()->x - (mCamera->GetWidth() >> 1), SCREEN_HEIGHT);

}

void PlayScene::OnKeyDown(int key)
{
	keyCode[key] = true;
	Player::GetInstance()->OnKeyDown(key);
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

void PlayScene::OnKeyUp(int key)
{
	keyCode[key] = false;
	Player::GetInstance()->OnKeyUp(key);
}

