#include "Object.h"

Object::Object()
{
}

void Object::Update(DWORD dt)
{
}

void Object::Render()
{	
}

RECT Object::GetRect()
{
	RECT box;
	box.top = y + (height >> 1);
	box.left = x - (width >> 1);
	box.right = box.left + width;
	box.bottom = box.top - height;
	return box;
}

//void Object::AddAnimation(State _state)
//{
//}

Object::~Object(){}




