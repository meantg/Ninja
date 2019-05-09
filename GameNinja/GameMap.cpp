#include "GameMap.h"


GameMap::GameMap(const char* filePath)
{
	LoadMap(filePath);
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
		input >> row >> column;
		mapMatrix = new int*[row];
		for (int i = 0; i < row; i++)
		{
			mapMatrix[i] = new int[column];
			for (int j = 0; j < column; j++)
			{
				input >> mapMatrix[i][j];
			}
		}
	}

}


void GameMap::Draw()
{
	RECT r = mCamera->GetBound();
	for (int i = 0; i < r.bottom/16; i++)
	{
		for (int j = 0, curX = r.left/16; curX < r.right/16; j++,curX++)
		{	
			SpriteManager::GetInstance()->GetSprite(70000 + mapMatrix[i][curX])->Draw(j * 16, i * 16);
		}
	}
}

int GameMap::getRow()
{
	return row;
}

int GameMap::getColumn()
{
	return column;
}

void GameMap::SetCamera(Camera * camera)
{
	this->mCamera = camera;
}
