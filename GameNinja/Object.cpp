#include "Object.h"

Object::Object()
{
	x = y = 0;
	vx = 0.1f;
}

void Object::Update(DWORD dt)
{
	//Dich chuyen vi tri cua Anim
	/*x += vx * dt;
	if ((vx > 0 && x >= SCREEN_WIDTH) || (x < 0 && vx < 0))
		vx = -vx;*/
}

void Object::Render()
{	
}

Hitbox Object::GetHitbox()
{
	Hitbox box;
	box.top = y + (height >> 1);
	box.left = x - (width >> 1);
	box.right = box.left + width;
	box.bottom = box.top - height;

	return box;
}

void Object::AddAnimation(State _state)
{
}

Object::~Object(){}




