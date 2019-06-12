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
	listObj.insert(new ESwordMan(300, 56));
	listObj.insert(new ECloakMan(1230, 123));
}

void PlayScene::Update(float dt)
{

	mCamera->SetPosition(Player::GetInstance()->x - (mCamera->GetWidth() >> 1), SCREEN_HEIGHT);
	mMap->Update(dt);
	Player::GetInstance()->Update(dt, enemy);
	scoreboard->Update(dt);
	UpdateObject(dt);
	

	/*if (mCamera->GetBound().right + 8 <= MapWidth)
	mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(8,0,0));*/
	/*if ((player->GetPosition().x >= SCREEN_WIDTH / 2) && (mCamera->GetBound().right + 32 <= MapWidth)) {
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR2(8, 0));
	}*/
	/*if(mCamera->GetBound().right == MapWidth)*/
}

void PlayScene::UpdateObject(float dt)
{

	auto it = listObj.begin();
	while (it != listObj.end())
	{
		auto o = *it;
		switch (o->tag)
		{
		case PLAYER:
		{
			auto e = (Enemy*)o;
			e->Update(dt);

			switch (e->type)
			{
			case E_CLOAKMAN:
			case E_GUNMAN:
			case E_BAZOKA:
			{
				if (e->_state == ATTACKING && e->_curAnimation->isLastFrame)
				{
					auto bullet = new Bullet();
					if (e->type == E_CLOAKMAN)
						bullet = new CloakManBullet();
					listObj.insert(bullet);
					bullet->isReverse = e->isReverse;
					if (bullet->isReverse)
						bullet->vx = -bullet->vx;
					bullet->x = e->x + (e->isReverse ? -5 : 5);
					bullet->y = e->y + 3;
					bullet->ChangeState(ATK_WITH_WEAPON);
					
					e->bulletCount--;

					if (e->bulletCount == 0)
					{
						e->bulletCount = e->bulletTotal;
						e->ChangeState(RUNNING);
					}
				}
				break;
			}
			}
		}
		}
		++it;

	}
}

// Tải Scene lên màn hình bằng cách vẽ các Sprite trong Scene
void PlayScene::Render()
{
	mMap->Render();
	scoreboard->Render();
	for (auto o : listObj)
		o->Render(mCamera->GetPositionX(), mCamera->GetPositionY());
	Player::GetInstance()->Render(mCamera->GetPositionX(),mCamera->GetPositionY());
	//for (auto i = 0; i < enemy.size(); ++i)
	//	enemy[i]->Render(mCamera->GetPositionX(), mCamera->GetPositionY());
	//mCamera->SetPosition(Player::GetInstance()->x - (mCamera->GetWidth() >> 1), SCREEN_HEIGHT);

}

void PlayScene::OnKeyDown(int key)
{
	keyCode[key] = true;
	Player::GetInstance()->OnKeyDown(key);
}

void PlayScene::OnKeyUp(int key)
{
	keyCode[key] = false;
	Player::GetInstance()->OnKeyUp(key);
}

