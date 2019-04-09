#include "Object.h"

Object::Object()
{
	x = y = 0;
	vx = 0.1f;
}

void Object::Update(DWORD dt)
{
	//Dich chuyen vi tri cua Anim
	x += vx * dt;
	if ((vx > 0 && x >= SCREEN_WIDTH) || (x < 0 && vx < 0))
		vx = -vx;
}

void Object::Render()
{	
}

void Object::AddAnimation(State _state)
{
	LPANIMATION ani = AnimationManager::GetInstance()->Get(_state);
	animations[_state] = ani;
}

Object::~Object(){}