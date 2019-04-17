#pragma once
#include "Animation.h"

class AnimationManager
{
	static AnimationManager * _instance;
	unordered_map<State, unordered_map<TypeObject, LPANIMATION>> oAnimations;
public:
	void StartUp();
	void ShutDown();

	void Add(TypeObject _type, State _state, LPANIMATION ani);
	LPANIMATION Get(TypeObject _type, State _state);

	static AnimationManager * GetInstance();
};