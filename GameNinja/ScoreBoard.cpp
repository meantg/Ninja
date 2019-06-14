#include "ScoreBoard.h"
ScoreBoard *ScoreBoard::_instance = NULL;
ScoreBoard::ScoreBoard()
{
	time = 140;
	score = 00000;
	health = 10;
	mana = 10;
	curTime = 0;
}

ScoreBoard * ScoreBoard::GetInstance()
{
	if (_instance == NULL) {
		_instance = new ScoreBoard();
	}
	return _instance;
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
	//SCORE
	SpriteManager::GetInstance()->GetSprite(S)->DrawFont(48, 10);
	SpriteManager::GetInstance()->GetSprite(C)->DrawFont(56, 10);
	SpriteManager::GetInstance()->GetSprite(O)->DrawFont(64, 10);
	SpriteManager::GetInstance()->GetSprite(R)->DrawFont(72, 10);
	SpriteManager::GetInstance()->GetSprite(E)->DrawFont(80, 10);

	SpriteManager::GetInstance()->GetSprite(Cross)->Draw(90, 10);

	

	//TIMER
	SpriteManager::GetInstance()->GetSprite(T)->DrawFont(48, 22);
	SpriteManager::GetInstance()->GetSprite(I)->DrawFont(56, 22);
	SpriteManager::GetInstance()->GetSprite(M)->DrawFont(64, 22);
	SpriteManager::GetInstance()->GetSprite(E)->DrawFont(72, 22);
	SpriteManager::GetInstance()->GetSprite(R)->DrawFont(80, 22);

	//Stage name
	SpriteManager::GetInstance()->GetSprite(P)->DrawFont(48, 34);
	SpriteManager::GetInstance()->GetSprite(Cross)->Draw(56, 34);

	if (time >= 0)
	{
		int i = (time / 100);
		int j = ((time % 100) / 10);
		int k = ((time % 100) % 10);

		SpriteManager::GetInstance()->GetSprite(i)->DrawFont(100, 22);
		SpriteManager::GetInstance()->GetSprite(j)->DrawFont(108, 22);
		SpriteManager::GetInstance()->GetSprite(k)->DrawFont(116, 22);
	}

	if (this->score > 0) {
		int i = (score / 100000);
		int j = ((score % 100000) / 10000);
		int k = ((score % 100000) % 10000 / 1000);
		int l = ((score % 100000) % 10000 % 1000/ 100);
		int m = ((score % 100000) % 10000 % 1000 % 100/10);
		int n = ((score % 100000) % 10000 % 1000 % 100 % 10);

		SpriteManager::GetInstance()->GetSprite(i)->DrawFont(100, 10);
		SpriteManager::GetInstance()->GetSprite(j)->DrawFont(108, 10);
		SpriteManager::GetInstance()->GetSprite(k)->DrawFont(116, 10);
		SpriteManager::GetInstance()->GetSprite(l)->DrawFont(124, 10);
		SpriteManager::GetInstance()->GetSprite(m)->DrawFont(132, 10);
		SpriteManager::GetInstance()->GetSprite(n)->DrawFont(140, 10);
	}
	//STAGE
	SpriteManager::GetInstance()->GetSprite(S)->DrawFont(180, 10);
	SpriteManager::GetInstance()->GetSprite(T)->DrawFont(188, 10);
	SpriteManager::GetInstance()->GetSprite(A)->DrawFont(196, 10);
	SpriteManager::GetInstance()->GetSprite(G)->DrawFont(204, 10);
	SpriteManager::GetInstance()->GetSprite(E)->DrawFont(212, 10);

	//NINJA
	SpriteManager::GetInstance()->GetSprite(N)->DrawFont(180, 22);
	SpriteManager::GetInstance()->GetSprite(I)->DrawFont(188, 22);
	SpriteManager::GetInstance()->GetSprite(N)->DrawFont(196, 22);
	SpriteManager::GetInstance()->GetSprite(J)->DrawFont(204, 22);
	SpriteManager::GetInstance()->GetSprite(A)->DrawFont(212, 22);

	SpriteManager::GetInstance()->GetSprite(Line)->DrawFont(222, 22);

	//ENEMY
	SpriteManager::GetInstance()->GetSprite(E)->DrawFont(180, 34);
	SpriteManager::GetInstance()->GetSprite(N)->DrawFont(188, 34);
	SpriteManager::GetInstance()->GetSprite(E)->DrawFont(196, 34);
	SpriteManager::GetInstance()->GetSprite(M)->DrawFont(204, 34);
	SpriteManager::GetInstance()->GetSprite(Y)->DrawFont(212, 34);

	SpriteManager::GetInstance()->GetSprite(Line)->DrawFont(222, 34);

}

void ScoreBoard::Update(float dt)
{
	if (curTime >= 1000)
	{
		time--;
		curTime = 0;
	}
	else
		curTime += dt * 100;

}
