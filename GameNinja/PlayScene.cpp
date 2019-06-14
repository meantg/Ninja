#include "PlayScene.h"

PlayScene::PlayScene(AnimationManager* gAnimationManager)
{
	player->ChangeState(new PlayerStandingState());
	_backColor = D3DCOLOR_XRGB(0, 255, 255);
	_timeCounter = 0;
	animations = gAnimationManager;
	LoadMap("MapReader/Map1_matrix.txt");
	MapWidth = 2048; MapHeight = 176;

	grid = new Grid(MapWidth, MapHeight);
}

PlayScene::~PlayScene()
{
	delete animations;
}

void PlayScene::LoadMap(const char * filePath)
{
	mMap = new GameMap(filePath);
	scoreboard = new ScoreBoard();

	//Goc toa do camera la bottom left
	mCamera->SetPosition(0, SCREEN_HEIGHT);

	//Insert Enemy
		//SwordMan
	//listObj.insert(new ESwordMan(255, 57));
	//listObj.insert(new ESwordMan(349, 57));
	//listObj.insert(new ESwordMan(445, 57));
	//listObj.insert(new ESwordMan(1292, 120));
	//listObj.insert(new ESwordMan(1452, 120));
	//listObj.insert(new ESwordMan(1484, 140));
	//listObj.insert(new ESwordMan(1883,57));
	//listObj.insert(new ESwordMan(1963, 57));

	//	//CloakMan
	//listObj.insert(new ECloakMan(820, 100));
	//listObj.insert(new ECloakMan(1230, 119));

	//	//Panther
	//listObj.insert(new EPanther(234, 46));
	//listObj.insert(new EPanther(912, 118));
	//listObj.insert(new EPanther(945, 118));
	//listObj.insert(new EPanther(1281, 46));

	//	//GunMan
	//listObj.insert(new EGunMan(1373, 57));

	//	//Eagle
	//listObj.insert(new EEagle(560, 140));
	//listObj.insert(new EEagle(720, 140));
	//listObj.insert(new EEagle(1060, 130));
	//listObj.insert(new EEagle(1570, 125));
	//listObj.insert(new EEagle(1730, 140));

	////Insert ItemHolder
	//	//Butterfly
	//listObj.insert(new IHButterfly(330,80));
	//listObj.insert(new IHButterfly(430, 80));
	//listObj.insert(new IHButterfly(567, 80));
	//listObj.insert(new IHButterfly(631, 104));
	//listObj.insert(new IHButterfly(758, 121));
	//listObj.insert(new IHButterfly(1146, 80));
	//listObj.insert(new IHButterfly(884, 152));
	//listObj.insert(new IHButterfly(1174, 152));
	//listObj.insert(new IHButterfly(1321, 152));
	//listObj.insert(new IHButterfly(1655, 80));
	//listObj.insert(new IHButterfly(1850, 80));


	//grounds.insert(new Ground(0, 38, 540, 10));
	//grounds.insert(new Ground(580, 42, 22, 10));
}

void PlayScene::Update(float dt)
{
	mCamera->SetPosition(player->x - (mCamera->GetWidth() >> 1), SCREEN_HEIGHT);
	mMap->Update(dt);
	grid->Update();
	scoreboard->Update(dt);
	UpdateObject(dt);
	UpdatePlayer(dt);
	

	/*if (mCamera->GetBound().right + 8 <= MapWidth)
	mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(8,0,0));*/
	/*if ((player->GetPosition().x >= SCREEN_WIDTH / 2) && (mCamera->GetBound().right + 32 <= MapWidth)) {
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR2(8, 0));
	}*/
	/*if(mCamera->GetBound().right == MapWidth)*/
}

void PlayScene::UpdateObject(float dt)
{
	auto it = visibleObjects.begin();
	while (it != visibleObjects.end())
	{
		auto o = *it;
		switch (o->tag)
		{
		case ENEMY:
		{
			auto e = (Enemy*)o;
			e->Update(dt);
			grid->MoveObject(e, e->x + e->vx*dt, e->y + e->vy*dt);

			switch (e->type)
			{
			case E_CLOAKMAN:
			case E_GUNMAN:
			case E_BAZOKA:
			{
				if (e->_state == ATTACKING && e->_curAnimation->isLastFrame)
				{
					auto bullet = EnemyBullet::CreateBullet(e->type);
					bullet->isReverse = e->isReverse;
					if (bullet->isReverse)
						bullet->vx = -bullet->vx;
					bullet->x = e->x + (e->isReverse ? -5 : 5);
					bullet->y = e->y + 3;
					bullet->ChangeState(ATK_WITH_WEAPON);
					grid->AddObject(bullet);
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
		case BULLET:
		{
			Bullet* b = (Bullet*)o;
			b->Update(dt);
			grid->MoveObject(b, b->x + b->dx, b->y + b->dy);
			break;
		}
		}
		++it;
	}
	this->UpdateVisibleObjects();
}

void PlayScene::UpdatePlayer(float dt)
{
	player->Update(dt, grid->GetColliableObjects(player));
	player->x += player->vx * dt;
	player->y += player->vy*dt;
	/*if(!player->isOnGround)*/
	/*player->CheckGroundCollision(grounds);*/
}

// Tải Scene lên màn hình bằng cách vẽ các Sprite trong Scene
void PlayScene::Render()
{
	mMap->Render();
	scoreboard->Render();
	for (auto o : visibleObjects)
		o->Render(mCamera->GetPositionX(), mCamera->GetPositionY());
	player->Render(mCamera->GetPositionX(),mCamera->GetPositionY());
	//for (auto i = 0; i < enemy.size(); ++i)
	//	enemy[i]->Render(mCamera->GetPositionX(), mCamera->GetPositionY());
	//mCamera->SetPosition(player->x - (mCamera->GetWidth() >> 1), SCREEN_HEIGHT);

}

void PlayScene::UpdateVisibleObjects()
{
	//auto it = visibleObjects.begin();
	//while (it != visibleObjects.end())
	//{
	//	if ((*it)->tag != WEAPON)
	//	{
	//		it = visibleObjects.erase(it);
	//	}
	//	else ++it;
	//}
 	for (auto o : grid->GetVisibleObjects())
	{
		visibleObjects.insert(o);
	}
}

void PlayScene::OnKeyDown(int key)
{
	keyCode[key] = true;
	player->OnKeyDown(key);
}

void PlayScene::OnKeyUp(int key)
{
	keyCode[key] = false;
	player->OnKeyUp(key);
}

