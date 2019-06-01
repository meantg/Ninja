#include "Animation.h"

//
//void Animation::SetPosition(float x, float y)
//{
//	_sprite->SetPosition(x, y);
//}
//

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
	frames[curFrame]->GetSprite()->FlipHorizontal(isReverse);
	frames[curFrame]->GetSprite()->Draw(x, y, frames[curFrame]->GetSprite()->isFlipHorizontal());
}

void Animation::Update(float dt)
{
	DWORD t = frames[curFrame]->GetTime();
	if (curFrameTime > t) {
		curFrameTime = 0;
		if (++curFrame == frames.size()) {
			isLastFrame = true;
			curFrame = 0;
		}
	}
	else
	{
		isLastFrame = false;
		curFrameTime += dt;
	}
}
