#pragma once
#include "GameGlobal.h"
#include "Player.h"

class Camera
{
private:
	int cmWidth;
	int cmHeight;

	D3DXVECTOR2 mPosition;
public:
	Camera(int width, int height);

	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR2 pos);
	int GetWidth();
	int GetHeight();
	D3DXVECTOR2 GetPosition();
	RECT GetBound();
	void Update(int mWidth, int mHeight);
	void ConvertToViewport(float x, float y);
	~Camera();
};