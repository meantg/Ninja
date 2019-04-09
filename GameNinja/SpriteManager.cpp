#include "SpriteManager.h"

SpriteManager * SpriteManager::_instance = NULL;

SpriteManager *SpriteManager::GetInstance()
{
	if (_instance == NULL) _instance = new SpriteManager();
	return _instance;
}


void SpriteManager::StartUp()
{
	SpriteManager * sprites = SpriteManager::GetInstance();
	LPDIRECT3DTEXTURE9 texPeople = TextureManager::GetInstance()->GetTexture(1);
	//Idle
	sprites->Add(00000, 2, 4, 21, 37, texPeople);
	//Attack-Standing
	sprites->Add(00001, 41, 4, 60, 37, texPeople);
	sprites->Add(00002, 66, 4, 101, 37, texPeople);
	sprites->Add(00003, 111, 4, 141, 37, texPeople);

	//Throwing
	sprites->Add(10001, 164, 4, 182, 37, texPeople);
	sprites->Add(10002, 189, 4, 215, 37, texPeople);
	sprites->Add(10003, 227, 4, 253, 37, texPeople);

	//Climbing
	sprites->Add(20001, 266, 4, 284, 37, texPeople);
	sprites->Add(20002, 288, 4, 306, 37, texPeople);

	//Run
	sprites->Add(30001, 339, 4, 361, 37, texPeople);
	sprites->Add(30002, 368, 4, 390, 37, texPeople);
	sprites->Add(30003, 400, 4, 421, 37, texPeople);

	//Sitting
	sprites->Add(40000, 3, 45, 21, 77, texPeople);

	//Attack-Sitting
	sprites->Add(40001, 35, 45, 53, 77, texPeople);
	sprites->Add(40002, 58, 45, 99, 77, texPeople);
	sprites->Add(40003, 99, 45, 130, 77, texPeople);

	//Jump
	sprites->Add(50001, 142, 45, 158, 77, texPeople);
	sprites->Add(50002, 166, 45, 189, 77, texPeople);
	sprites->Add(50003, 193, 45, 210, 77, texPeople);
	sprites->Add(50004, 216, 45, 240, 77, texPeople);

	//Jump-Attack
	sprites->Add(60001, 262, 45, 288, 77, texPeople);
	sprites->Add(60002, 293, 45, 321, 77, texPeople);
	sprites->Add(60003, 325, 45, 353, 77, texPeople);
	sprites->Add(60004, 357, 45, 385, 77, texPeople);
}

void SpriteManager::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	CSprite* s = new CSprite(id, left, top, right, bottom, tex);
	_sprites[id] = s;
}

LPSPRITE SpriteManager::GetSprite(int id)
{
	return _sprites[id];
}