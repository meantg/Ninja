#include "Camera.h"

Camera::Camera(int width, int height)
{
	cmWidth = width;
	cmHeight = height;
	mPosition = D3DXVECTOR2(0, height);
}


Camera::~Camera()
{

}

void Camera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR2(x, y));
}

void Camera::SetPosition(D3DXVECTOR2 pos)
{
	mPosition = pos;
}

D3DXVECTOR2 Camera::GetPosition()
{
	return mPosition;
}

RECT Camera::GetBound()
{
	RECT bound;

	bound.left = mPosition.x;
	bound.right = bound.left + cmWidth;
	bound.top = mPosition.y;
	bound.bottom = bound.top + cmHeight;

	return bound;
}

void Camera::Update(int mWidth, int mHeight)
{
	if (this->GetPosition().x <= 0)
	{
		this->SetPosition(0, this->GetPosition().y);
	}

	else if (this->GetPosition().x >= mWidth - this->GetWidth())
	{
		this->SetPosition(mWidth - this->GetWidth(), this->GetPosition().y);
	}
}

void Camera::ConvertToViewport(float x, float y)
{
	float newx = x - mPosition.x;
	float newy = y - mPosition.y;
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