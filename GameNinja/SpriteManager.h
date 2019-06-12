#pragma once
#include <unordered_map>
#include "Sprite.h"

using namespace std;
class SpriteManager : CSprite
{
private:
	unordered_map<int, LPSPRITE> _sprites;
	unordered_map<Font, LPSPRITE> _fonts;
	static SpriteManager *_instance;
public:
	void StartUp();
	void ShutDown();

	void AddFont(Font character, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	static SpriteManager * GetInstance();
	LPSPRITE GetSprite(int id);
	LPSPRITE GetSprite(Font character);
};