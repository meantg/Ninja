#pragma once
#include "GameGlobal.h"

class Camera
{
private:
	int cmWidth;
	int cmHeight;

	D3DXVECTOR2 mPosition;
	D3DXVECTOR2 maxPosition;
public:
	Camera(int width, int height, int row, int column);

	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR2 pos);
	int GetWidth();
	int GetHeight();
	D3DXVECTOR2 GetPosition();
	RECT GetBound();

	~Camera();
};