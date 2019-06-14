#include "Camera.h"


Camera* Camera::_instance = NULL;
Camera::Camera()
{
	cmWidth = SCREEN_WIDTH;
	cmHeight = SCREEN_HEIGHT;
	x = 0;
	y = SCREEN_HEIGHT;
}

Camera * Camera::GetInstance()
{
	if (_instance == NULL) _instance = new Camera();
	return _instance;
}

Camera::~Camera()
{

}

void Camera::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}


float Camera::GetPositionX()
{
	return x;
}
float Camera::GetPositionY() {
	return y;
}

Rect Camera::GetBound()
{
	Rect bound;

	bound.x = x;
	bound.width = cmWidth;
	bound.y = y;
	bound.height = cmHeight;

	return bound;
}

void Camera::Update(int mWidth, int mHeight)
{
	if (this->GetPositionX() <= 0)
	{
		this->SetPosition(0, this->GetPositionY());
	}

	else if (this->GetPositionX() >= mWidth - this->GetWidth())
	{
		this->SetPosition(mWidth - this->GetWidth(), this->GetPositionY());
	}
}

void Camera::ConvertToViewport(float x, float y)
{
	float newx = x - this->x;
	float newy = y - this->y;
	this->SetPosition(newx, newy);
}


int Camera::GetWidth()
{
	return cmWidth;
}

int Camera::GetHeight()
{
	return cmHeight;
}