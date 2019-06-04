#include "SpriteManager.h"

SpriteManager * SpriteManager::_instance = NULL;

SpriteManager *SpriteManager::GetInstance()
{
	if (_instance == NULL) _instance = new SpriteManager();
	return _instance;
}


void SpriteManager::StartUp()
{
	//Load Sprite Ninja
	//

	SpriteManager * sprites = SpriteManager::GetInstance();
	LPDIRECT3DTEXTURE9 texPeople = TextureManager::GetInstance()->GetTexture(Ninja_Text);
	//Idle
	sprites->Add(00000, 2, 5, 21, 37, texPeople);
	//Attack-Standing
	sprites->Add(00001, 41, 5, 60, 37, texPeople);
	sprites->Add(00002, 66, 5, 101, 37, texPeople);
	sprites->Add(00003, 111, 5, 141, 37, texPeople);

	//Throwing
	sprites->Add(10001, 164, 5, 182, 37, texPeople);
	sprites->Add(10002, 189, 5, 215, 37, texPeople);
	sprites->Add(10003, 227, 4, 253, 37, texPeople);

	//Climbing
	sprites->Add(20001, 266, 5, 284, 37, texPeople);
	sprites->Add(20002, 288, 5, 306, 37, texPeople);

	//Run
	sprites->Add(30001, 339, 5, 361, 37, texPeople);
	sprites->Add(30002, 368, 5, 390, 37, texPeople);
	sprites->Add(30003, 400, 5, 421, 37, texPeople);

	//Sitting
	sprites->Add(40000, 4, 52, 20, 77, texPeople);

	//Attack-Sitting
	sprites->Add(40001, 33, 52, 54, 77, texPeople);
	sprites->Add(40002, 58, 52, 83, 77, texPeople);
	sprites->Add(40003, 99, 52, 122, 77, texPeople);

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


	////BBox
	//LPDIRECT3DTEXTURE9 BBoxText = TextureManager::GetInstance()->GetTexture(BBox_Texture);
	//sprites->Add(99999, 0, 0, 222, 118, BBoxText);
	//Load TilesMap

	LPDIRECT3DTEXTURE9 texStage1 = TextureManager::GetInstance()->GetTexture(Stage3_1);
	for (int i = 0; i < 79; i++)
	{
		sprites->Add(70000+ i, i*16, 0, 16*(i+1), 16, texStage1);
	}
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