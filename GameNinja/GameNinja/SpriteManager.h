#pragma once
#include <unordered_map>
#include "Sprite.h"

using namespace std;
class SpriteManager : CSprite
{
private:
	unordered_map<int, LPSPRITE> _sprites;
	static SpriteManager *_instance;
public:
	void StartUp();
	void ShutDown();

	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	static SpriteManager * GetInstance();
	LPSPRITE GetSprite(int id);
};