#include "Camera.h"

Camera::Camera(int width, int height, int row, int column)
{
	cmWidth = width;
	cmHeight = height;	
	maxPosition = D3DXVECTOR2(column * 16 - width, row * 16 - height);
	mPosition = D3DXVECTOR2(0, 0);
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

	bound.left = mPosition.x - cmWidth / 2;
	bound.right = bound.left + cmWidth;;
	bound.top = mPosition.y - cmHeight / 2;
	bound.bottom = bound.top + cmHeight;

	return bound;
}

int Camera::GetWidth()
{
	return cmWidth;
}

int Camera::GetHeight()
{
	return cmHeight;
}