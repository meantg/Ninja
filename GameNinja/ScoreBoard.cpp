#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{
	time = 140;
	score = 00000;
	health = 10;
	mana = 10;
}

//ScoreBoard * ScoreBoard::GetInstance()
//{
//	if (_instance == NULL)
//		return _instance = new ScoreBoard();
//	else
//		return _instance;
//}

void ScoreBoard::Render()
{
	//140
	//Time
	if (time >= 0)
	{
		int realtime = time * 1000;

		int i = (realtime / 100000);
		int j = ((realtime % 100000) / 10000);
		int k = ((realtime % 100000) % 10000);

		SpriteManager::GetInstance()->GetSprite(i)->Draw(10, 10);
		SpriteManager::GetInstance()->GetSprite(j)->Draw(17, 10);
		SpriteManager::GetInstance()->GetSprite(k)->Draw(24, 10);
	}
}
