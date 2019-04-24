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
	int row, column;
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

int** GameMap::isContain(int **matrix)
{
	//Kiem tra xem nhung tilemap nao co trong camera
	float column = SCREEN_WIDTH / 32;
	float row = SCREEN_HEIGHT / 32;
	ceil(column); ceil(row);

	int **_matrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		_matrix[i] = new int[column];
		for (int j = 0; j < column; j++)
		{
			_matrix[i][j] = matrix[i][j];
		}
	}
	return _matrix;
}




void GameMap::Draw()
{
	/*int **_mapMatrix = isContain(mapMatrix);*/
	RECT r = mCamera->GetBound();

	for (int i = 0; i < r.bottom/32; i++)
	{
		for (int j = 0, curX = r.left/32; curX < r.right/32; j++,curX++)
		{
			
			SpriteManager::GetInstance()->GetSprite(70000 + mapMatrix[i][curX])->Draw(j * 32, i * 32);
		}
	}
}

void GameMap::SetCamera(Camera * camera)
{
	this->mCamera = camera;
}
