#pragma once
#include "Animation.h"

class AnimationManager
{
	static AnimationManager * _instance;
	unordered_map<State, LPANIMATION> animations;
public:
	void StartUp();
	void ShutDown();

	void Add(State _state, LPANIMATION ani);
	LPANIMATION Get(State _state);

	static AnimationManager * GetInstance();
};