#pragma once
#include "GameGlobal.h"

class Camera
{
private:
	int cmWidth;
	int cmHeight;
	float x, y;

public:
	Camera(int width, int height);

	void SetPosition(float x, float y);
	int GetWidth();
	int GetHeight();
	float GetPositionX();
	float GetPositionY();
	RECT GetBound();
	void Update(int mWidth, int mHeight);
	void ConvertToViewport(float x, float y);
	~Camera();
};