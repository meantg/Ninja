#include "Animation.h"

//
//void Animation::SetPosition(float x, float y)
//{
//	_sprite->SetPosition(x, y);
//}
//
void Animation::FlipHorizontal(bool flag)
{
	frames[curFrame]->GetSprite()->FlipHorizontal(flag);
}
//
//void Animation::FlipVertical(bool flag)
//{
//	_sprite->FlipVertical(flag);
//}


//Class Animation
void Animation::Add(int spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t = this->defaultTime;

	LPSPRITE sprite = SpriteManager::GetInstance()->GetSprite(spriteId);

	LPANIMATIONFRAME frame = new AnimationFrame(sprite, t);
	frames.push_back(frame);
}

void Animation::Render(float x, float y)
{
	DWORD now = GetTickCount();
	if (curFrame == 0) {
		curFrame++;
		lastFrameTime = now;
		if (curFrame == frames.size()) curFrame = 0;
	}

	else
	{
		DWORD t = frames[curFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			curFrame++;
			lastFrameTime = now;
			if (curFrame == frames.size()) curFrame = 0;
		}

	}
	frames[curFrame]->GetSprite()->Draw(x, y, frames[curFrame]->GetSprite()->isFlipHorizontal());
}

