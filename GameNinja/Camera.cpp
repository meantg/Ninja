#include "Camera.h"

Camera::Camera(int width, int height)
{
	cmWidth = width;
	cmHeight = height;
	x = 0;
	y = height;
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

RECT Camera::GetBound()
{
	RECT bound;

	bound.left = x;
	bound.right = bound.left + cmWidth;
	bound.top = y;
	bound.bottom = bound.top + cmHeight;

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