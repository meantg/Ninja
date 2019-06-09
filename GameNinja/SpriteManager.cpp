#include "SpriteManager.h"

SpriteManager * SpriteManager::_instance = NULL;

SpriteManager *SpriteManager::GetInstance()
{
	if (_instance == NULL) _instance = new SpriteManager();
	return _instance;
}


void SpriteManager::StartUp()
{
	//------------------Load Sprite Ninja
	SpriteManager * sprites = SpriteManager::GetInstance();
	LPDIRECT3DTEXTURE9 texPeople = TextureManager::GetInstance()->GetTexture(Ninja_Text);
	//Standing
	sprites->Add(10000, 2, 5, 21, 37, texPeople);

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

	//Attack-Standing
	sprites->Add(1001, 41, 5, 60, 37, texPeople);
	sprites->Add(1002, 66, 5, 101, 37, texPeople);
	sprites->Add(1003, 111, 5, 141, 37, texPeople);

	////BBox
	//LPDIRECT3DTEXTURE9 BBoxText = TextureManager::GetInstance()->GetTexture(BBox_Texture);
	//sprites->Add(99999, 0, 0, 222, 118, BBoxText);
	//Load TilesMap

	LPDIRECT3DTEXTURE9 texStage1 = TextureManager::GetInstance()->GetTexture(Stage3_1);
	for (int i = 0; i < 79; i++)
	{
		sprites->Add(70000+ i, i*16, 0, 16*(i+1), 16, texStage1);
	}

	//------------------LoadSprite Enemy
	LPDIRECT3DTEXTURE9 texEnemy = TextureManager::GetInstance()->GetTexture(Enemy_Texture);

	//SwordMan
	sprites->Add(80001, 211, 47, 240, 90, texEnemy);
	sprites->Add(80002, 240, 47, 269, 90, texEnemy);
	sprites->Add(80003, 278, 47, 307, 90, texEnemy);

	//BazokaMan
	sprites->Add(90001, 383, 61, 414, 90, texEnemy);
	sprites->Add(90002, 414, 61, 444, 90, texEnemy);

	//Run Man
	sprites->Add(11001, 0, 56, 20, 86, texEnemy);
	sprites->Add(11002, 21, 56, 41, 86, texEnemy);

	//GunMan
	sprites->Add(12001, 51, 56, 77, 87, texEnemy);
	sprites->Add(12002, 77, 56, 103, 877, texEnemy);
	sprites->Add(12003, 129, 56, 159, 87, texEnemy);
	sprites->Add(12004, 159, 56, 189, 87, texEnemy);
	sprites->Add(12005, 190, 62, 206, 73, texEnemy);

	//CloakMan
	sprites->Add(13001, 404, 0, 437, 43, texEnemy);
	sprites->Add(13002, 440, 0, 474, 43, texEnemy);
	sprites->Add(13003, 488, 0, 518, 43, texEnemy);

	//Panther
	sprites->Add(14001, 309, 74, 342, 90, texEnemy);
	sprites->Add(14002, 342, 74, 377, 90, texEnemy);

	//Eagle
	sprites->Add(15001, 471, 54, 497, 92, texEnemy);
	sprites->Add(15002, 500, 54, 526, 92, texEnemy);


	//----------------------LoadSprite Bullet
	LPDIRECT3DTEXTURE9 texBullet = TextureManager::GetInstance()->GetTexture(Enemy_Texture);

	//Bullet CloakMan
	sprites->Add(13004, 519, 5, 527, 21, texEnemy);
	sprites->Add(13005, 519, 23, 527, 38, texEnemy);
	sprites->Add(13006, 534, 7, 550, 17, texEnemy);
	sprites->Add(13007, 534, 27, 550, 38, texEnemy);

	//Bullet GunMan
	sprites->Add(12006, 192, 63, 203, 71, texEnemy);

	//Bullet BazokaMan
	sprites->Add(90003, 443, 60, 455, 75, texEnemy);
	sprites->Add(90004, 458, 62, 470, 77, texEnemy);
	//----------------------LoadSprite Item
	LPDIRECT3DTEXTURE9 texItem = TextureManager::GetInstance()->GetTexture(Item_Texture);

	//BlueSpirit
	sprites->Add(16001, 0, 7, 20, 24, texItem);
	//RedSpirit
	sprites->Add(16002, 20, 7, 40, 24, texItem);
	//GlassHour
	sprites->Add(16003, 400, 50, 416, 70, texItem);
	//BlueShuriken
	sprites->Add(16004, 50, 6, 68, 26, texItem);
	//RedBag
	sprites->Add(16005, 192, 6, 210, 26, texItem);
	//FireWheel
	sprites->Add(16006, 110, 6, 128, 26, texItem);
	//BlueBag
	sprites->Add(16007, 172, 6, 190, 26, texItem);
	//HealthPotion
	sprites->Add(16008, 227, 6, 245, 26, texItem);
	//RedShuriken
	sprites->Add(16009, 70, 8, 86, 24, texItem);
	//DEAD sprite for Enemy
	sprites->Add(18001, 363, 40, 397, 79, texItem);
	sprites->Add(18002, 316, 0, 350, 39, texItem);

	//----------------------LoadSprite Holder
	LPDIRECT3DTEXTURE9 texHolder = TextureManager::GetInstance()->GetTexture(Item_Texture);

	//ButterFly
	sprites->Add(17001, 83, 55, 96, 70, texHolder);
	sprites->Add(17002, 96, 53, 114, 70, texHolder);
	//Bird
	sprites->Add(17003, 116, 50, 136, 70, texItem);
	sprites->Add(17004, 139, 51, 159, 70, texItem);

	//----------------------LoadSprite FontScoreBoard
	LPDIRECT3DTEXTURE9 texFont = TextureManager::GetInstance()->GetTexture(Font_Texture);

	//Text
	sprites->AddFont(A, 5, 10, 14, 19, texFont);
	sprites->AddFont(C, 23, 10, 32, 19, texFont);
	sprites->AddFont(E, 42, 10, 51, 19, texFont);
	sprites->AddFont(S, 172, 10, 181, 19, texFont);
	sprites->AddFont(O, 135, 10, 144, 19, texFont);
	sprites->AddFont(R, 163, 10, 172, 19, texFont);
	sprites->AddFont(T, 183, 10, 192, 19, texFont);
	sprites->AddFont(G, 60, 10, 70, 20, texFont);
	sprites->AddFont(I, 80, 9, 88, 19, texFont);
	sprites->AddFont(M, 116, 9, 126, 23, texFont);
	sprites->AddFont(N, 125, 9, 135, 20, texFont);
	sprites->AddFont(J, 89, 9, 98, 19, texFont);
	sprites->AddFont(P, 144, 9, 154, 19, texFont);
	sprites->AddFont(Y, 228, 9, 237, 19, texFont);
	sprites->AddFont(Point, 185, 9, 188, 19, texFont);

	//Number
	sprites->Add(0, 4, 19, 15, 29, texFont);
	sprites->Add(1, 14, 19, 23, 29, texFont);
	sprites->Add(2, 23, 19, 33, 29, texFont);
	sprites->Add(3, 33, 19, 42, 29, texFont);
	sprites->Add(4, 42, 19, 51, 29, texFont);
	sprites->Add(5, 51, 19, 60, 29, texFont);
	sprites->Add(6, 60, 19, 70, 29, texFont);
	sprites->Add(7, 70, 19, 78, 29, texFont);
	sprites->Add(8, 79, 19, 88, 29, texFont);
	sprites->Add(9, 88, 19, 98, 29, texFont);
	sprites->AddFont(Cross, 256, 19, 166, 31, texFont);
}

void SpriteManager::AddFont(Font id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	CSprite* s = new CSprite(id, left, top, right, bottom, tex);
	_fonts[id] = s;
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