#pragma once
#include "Object.h"

class ItemHolder : public Object
{
protected:
	LPANIMATION holderanim;
public:
	int itemID;

	ItemHolder()
	{
		this->tag = ITEMHOLDER;
		this->width = ITEMHOLDER_WIDTH;
		this->height = ITEMHOLDER_HEIGHT;
	}
	~ItemHolder() {};

	void Render(float cameraX, float cameraY)
	{
		screenX = x - cameraX;
		screenY = cameraY - y;
		if (isActive == true)
		{
			holderanim ->isReverse = isReverse;
			holderanim ->Render(screenX, screenY);
		}
	}

	void Update(float dt)
	{
		holderanim->Update(dt);
	}
};