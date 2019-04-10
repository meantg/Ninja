#include "AnimationManager.h"

//Class Animations
AnimationManager * AnimationManager::_instance = NULL;

AnimationManager * AnimationManager::GetInstance()
{
	if (_instance == NULL) _instance = new AnimationManager();
	return _instance;
}

void AnimationManager::StartUp()
{
	AnimationManager * animations = new AnimationManager(); 
	animations->GetInstance();
	LPANIMATION ani;

	// Anim-Idle [0]
	ani = new Animation(100);
	ani->Add(00000);
	animations->Add(PLAYER, ani);

	// Anim-Attack-Standing [1]
	ani = new Animation(100);
	ani->Add(00001);
	ani->Add(00002);
	ani->Add(00003);
	animations->Add(PLAYER, ani);

	// Anim-Throwing [2]
	ani = new Animation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(THROWING, ani);

	//Anim-Climbing [3]
	ani = new Animation(100);
	ani->Add(20001);
	ani->Add(20002);
	animations->Add(CLIMBING, ani);

	//Anim-Running [4]
	ani = new Animation(100);
	ani->Add(30001);
	ani->Add(30002);
	ani->Add(30003);
	animations->Add(RUNNING, ani);

	//Anim-Sit [5]
	ani = new Animation(100);
	ani->Add(40000);
	animations->Add(SITTING, ani);

	//Anim-Attack-Sitting [6]
	ani = new Animation(100);
	ani->Add(40001);
	ani->Add(40002);
	ani->Add(40003);
	animations->Add(ATTACKING_SIT, ani);

	//Anim-Jumping [7]
	ani = new Animation(100);
	ani->Add(50001);
	ani->Add(50002);
	ani->Add(50003);
	ani->Add(50004);
	animations->Add(JUMPING, ani);
	animations->Add(FALLING, ani);

	//Anim-Jumping-Attack 
	ani = new Animation(100);
	ani->Add(60001);
	ani->Add(60002);
	ani->Add(60003);
	ani->Add(60004);
	animations->Add(JUMPING_ATK, ani);
}

void AnimationManager::Add(TypeObject _state, LPANIMATION ani)
{
	animations[_state] = ani;
}

LPANIMATION AnimationManager::Get(TypeObject _state)
{
	return animations[_state];
}