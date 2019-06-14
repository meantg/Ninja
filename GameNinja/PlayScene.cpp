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
}

void PlayScene::Update(float dt)
{
	mCamera->SetPosition(player->x - (mCamera->GetWidth() >> 1), SCREEN_HEIGHT);
	mMap->Update(dt);
	grid->Update();

	scoreboard->Update(dt);

	UpdateObject(dt);
	UpdatePlayer(dt);

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
				if (e->isDoneAtk)
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
				}
				break;
			}
			}
		}
		case BULLET:
		{
			Bullet* bullet = (Bullet*)o;
			bullet->Update(dt);
			grid->MoveObject(bullet, bullet->x + bullet->dx, bullet->y + bullet->dy);
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
	player->CheckGroundCollision(grid->GetColliableGrounds(player));
	player->CheckWallCollision(grid->GetColliableWalls(player));
	player->x += player->vx * dt;
	player->y += player->vy * dt;
}

// Tải Scene lên màn hình bằng cách vẽ các Sprite trong Scene
void PlayScene::Render()
{
	mMap->Render();
	scoreboard->Render();
	for (auto o : visibleObjects)
		o->Render(mCamera->GetPositionX(), mCamera->GetPositionY());
	player->Render(mCamera->GetPositionX(),mCamera->GetPositionY());

}

void PlayScene::UpdateVisibleObjects()
{
	auto it = visibleObjects.begin();
	while (it != visibleObjects.end())
	{
		if ((*it)->tag != WEAPON)
		{
			it = visibleObjects.erase(it);
		}
		else ++it;
	}
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

