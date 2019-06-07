#include "GameMap.h"


GameMap::GameMap(const char* filePath)
{
	LoadMap(filePath);
	swordMans.push_back(new ESwordMan(1000,56));
	swordMans.push_back(new ESwordMan(100, 56));
	swordMans.push_back(new ESwordMan(150, 56));
	for(auto i = 0; i < swordMans.size(); ++i)
		swordMans[i]->ChangeState(RUNNING);
}

GameMap::~GameMap()
{
}

void GameMap::LoadMap(const char* filePath)
{
	ifstream input;
	input.open(filePath);
	if (input.is_open())
	{
		input >> rows >> columns;
		mWidth = columns << 4;
		mHeight = rows << 4;
		mapMatrix = new int*[rows];
		for (int i = 0; i < rows; ++i)
		{
			mapMatrix[i] = new int[columns];
			for (int j = 0; j < columns; ++j)
			{
				input >> mapMatrix[i][j];
			}
		}
	}

}


void GameMap::Render()
{
	for (int i = 0; i != rows; ++i)
	{
		for (int j = cBegin; j != cEnd; ++j)
		{
			SpriteManager::GetInstance()->GetSprite(70000 + mapMatrix[i][j])->Draw((j << 4) + (16 >> 1) - (int)mCamera->GetPositionX(), ((i << 4) + (16 >> 1)));
		}
	}
	for (auto i = 0; i < swordMans.size(); ++i)
		swordMans[i]->Render(mCamera->GetPositionX(), mCamera->GetPositionY());
}

int GameMap::getRow()
{
	return rows;
}

int GameMap::getColumn()
{
	return columns;
}

void GameMap::SetCamera(Camera * camera)
{
	this->mCamera = camera;
}

void GameMap::Update(float dt)
{
	mCamera->Update(mWidth, mHeight);
	cBegin = max(0, mCamera->GetPositionX() / 16);
	cEnd = min(cBegin + ((SCREEN_WIDTH >> 4) + 1), columns);
	for (auto i = 0; i < swordMans.size(); ++i)
		swordMans[i]->Update(dt);
}
