#pragma once
#include "Animation.h"

class AnimationManager
{
	static AnimationManager * _instance;
	unordered_map<TypeObject, LPANIMATION> oAnimations;
public:
	void StartUp();
	void ShutDown();

	void Add(TypeObject _state, LPANIMATION ani);
	LPANIMATION Get(TypeObject _state);

	static AnimationManager * GetInstance();
};