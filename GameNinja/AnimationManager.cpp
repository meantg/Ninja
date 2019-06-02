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
	AnimationManager * animations = AnimationManager::GetInstance();
	LPANIMATION ani;

	// Anim-Idle [0]
	ani = new Animation(100);
	ani->Add(00000);
	animations->Add(PLAYER, STANDING, ani);

	// Anim-Attack-Standing [1]
	ani = new Animation(100);
	ani->Add(00001);
	ani->Add(00002);
	ani->Add(00003);
	animations->Add(PLAYER, ATK_STAND, ani);

	// Anim-Throwing [2]
	ani = new Animation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(PLAYER, THROWING, ani);

	//Anim-Climbing [3]
	ani = new Animation(100);
	ani->Add(20001);
	ani->Add(20002);
	animations->Add(PLAYER, CLIMBING, ani);

	//Anim-Running [4]
	ani = new Animation(100);
	ani->Add(30001);
	ani->Add(30002);
	ani->Add(30003);
	animations->Add(PLAYER, RUNNING, ani);

	//Anim-Sit [5]
	ani = new Animation(100);
	ani->Add(40000);
	animations->Add(PLAYER, SITTING, ani);

	//Anim-Attack-Sitting [6]
	ani = new Animation(100);
	ani->Add(40001);
	ani->Add(40002);
	ani->Add(40003);
	animations->Add(PLAYER, ATK_SIT, ani);

	//Anim-Jumping [7]
	ani = new Animation(100);
	ani->Add(50001);
	ani->Add(50002);
	ani->Add(50003);
	ani->Add(50004);
	animations->Add(PLAYER, JUMPING, ani);
	animations->Add(PLAYER, FALLING, ani);

	//Anim-Jumping-Attack 
	ani = new Animation(100);
	ani->Add(60001);
	ani->Add(60002);
	ani->Add(60003);
	ani->Add(60004);
	animations->Add(PLAYER, JUMPING_ATK, ani);
}

void AnimationManager::Add(TypeObject _type, State _state, LPANIMATION ani)
{
	unordered_map<TypeObject, LPANIMATION> anim;
	anim[_type] = ani;
	oAnimations[_state] = anim;
}

LPANIMATION AnimationManager::Get(TypeObject _type, State _state)
{
	unordered_map<TypeObject, LPANIMATION> anim;
	anim = oAnimations[_state];
	return anim[_type];
}