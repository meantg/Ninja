#pragma once
#include "d3d9.h"
#include "d3dx9.h"
#include "string"
#include "TextureManager.h"

using namespace std;

class CSprite
{
protected:
	int id; //sprite ID

	float left, top, right, bottom; //position of sprite in texture

	LPDIRECT3DTEXTURE9 texture;

	bool _isFlipVertical, _isFlipHorizontal;

public:
	CSprite() {};
	CSprite(int id, float left, float top, float right, float bottom, LPDIRECT3DTEXTURE9 tex);
	void Draw(float x = 0, float y = 0, bool _isFlipHoritzontal = false);
	void FlipHorizontal(bool flip);
	//void FlipVertical(bool flip);

	//bool isFlipVertical();
	bool isFlipHorizontal();

	float getWidth();
	float getHeight();
};

typedef CSprite * LPSPRITE;
