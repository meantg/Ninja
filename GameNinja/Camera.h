#pragma once
#include "GameGlobal.h"

class Camera
{
private:
	int cmWidth;
	int cmHeight;
	float x, y;
	static Camera* _instance;
public:
	Camera();
	static Camera* GetInstance();
	void SetPosition(float x, float y);
	int GetWidth();
	int GetHeight();
	float GetPositionX();
	float GetPositionY();
	Rect GetBound();
	void Update(int mWidth, int mHeight);
	void ConvertToViewport(float x, float y);
	~Camera();
};