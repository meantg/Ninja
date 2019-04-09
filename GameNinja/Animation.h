#pragma once
#include <vector>
#include "Sprite.h"
#include "SpriteManager.h"

class AnimationFrame
{
	LPSPRITE sprite;
	DWORD time;
public:
	AnimationFrame(LPSPRITE sprite, int time) { this->sprite = sprite; this->time = time; }
	DWORD GetTime() { return time; }
	LPSPRITE GetSprite() { return sprite; }
};
typedef AnimationFrame *LPANIMATIONFRAME;

class Animation
{
	DWORD lastFrameTime;
	int defaultTime;
	int curFrame;

	int totalFrames;
	int timeperFrames;
	vector<LPANIMATIONFRAME> frames;

public:

	Animation(int defaultTime) { this->defaultTime = defaultTime; lastFrameTime = -1; curFrame = 0; totalFrames = frames.size(); }
	void Add(int spriteId, DWORD time = 0);
	void Render(float x, float y);
	void FlipHorizontal(bool flag);
	/*void SetPosition(float x, float y);

	void FlipVertical(bool flag);*/
};
typedef Animation *LPANIMATION;

