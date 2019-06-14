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

	//--------------LoadAnimation PLAYER
	// Anim-Idle [0]
	ani = new Animation(100);
	ani->Add(10000);
	animations->Add(PLAYER, STANDING, ani);	

	//Anim - ATK STAND
	ani = new Animation(120);
	ani->Add(1001);		
	ani->Add(1002);		
	ani->Add(1003);
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
	ani = new Animation(120);
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

	//Anim-Injured
	ani = new Animation(100);
	ani->Add(50001);
	animations->Add(PLAYER, INJURED, ani);

	////--------------LoadAnimation ENEMY

	////SwordMan
	ani = new Animation(100);
	ani->Add(80001);
	animations->Add(E_SWORDMAN, STANDING, ani);
	ani = new Animation(400);
	ani->Add(80001);
	ani->Add(80002);
	ani->Add(80003);
	animations->Add(E_SWORDMAN, RUNNING, ani);
	ani = new Animation(100);
	ani->Add(18001);
	ani->Add(18002);
	animations->Add(E_SWORDMAN, DEAD, ani);

	////Bazoka
	ani = new Animation(100);
	ani->Add(90001);
	animations->Add(E_BAZOKA, STANDING, ani);
	ani = new Animation(100);
	ani->Add(90001);
	animations->Add(E_BAZOKA, RUNNING, ani);
	ani = new Animation(100);
	ani->Add(90001);
	ani->Add(90002);
	animations->Add(E_BAZOKA, ATTACKING, ani);

	//RunMan
	ani = new Animation(100);
	ani->Add(11001);
	animations->Add(E_RUNMAN, STANDING, ani);
	ani = new Animation(100);
	ani->Add(11002);
	animations->Add(E_RUNMAN, RUNNING, ani);

	//GunMan
	ani = new Animation(100);
	ani->Add(12001);
	animations->Add(E_GUNMAN, STANDING, ani);
	ani = new Animation(100);
	ani->Add(12001);
	ani->Add(12002);
	animations->Add(E_GUNMAN, RUNNING, ani);
	ani = new Animation(100);
	ani->Add(12003);
	ani->Add(12004);
	animations->Add(E_GUNMAN, ATTACKING, ani);
	ani = new Animation(100);
	ani->Add(12005);
	animations->Add(E_GUNMAN, ATK_WITH_WEAPON, ani);

	//CLOAKMAN
	ani = new Animation(100);
	ani->Add(13001);
	animations->Add(E_CLOAKMAN, STANDING, ani);
	ani = new Animation(100);
	ani->Add(13001);
	ani->Add(13002);
	animations->Add(E_CLOAKMAN, RUNNING, ani);
	ani = new Animation(300);
	ani->Add(13002);
	ani->Add(13003);
	animations->Add(E_CLOAKMAN, ATTACKING, ani);
		//WEAPON CLOAKMAN
	ani = new Animation(200);
	ani->Add(13004);
	ani->Add(13005);
	ani->Add(13006);
	ani->Add(13007);
	animations->Add(E_CLOAKMAN, ATK_WITH_WEAPON, ani);

	//PANTHER
	ani = new Animation(100);
	ani->Add(14001);
	animations->Add(E_PANTHER, STANDING, ani);
	ani = new Animation(200);
	ani->Add(14001);
	ani->Add(14002);
	animations->Add(E_PANTHER, RUNNING, ani);

	
	//EAGLE
	ani = new Animation(100);
	ani->Add(15001);
	animations->Add(E_EAGLE, STANDING, ani);
	ani = new Animation(200);
	ani->Add(15001);
	ani->Add(15002);
	animations->Add(E_EAGLE, RUNNING, ani);

	//DEAD
	ani = new Animation(500);
	ani->Add(18001);
	ani->Add(18002);
	animations->Add(E_EAGLE, DEAD, ani);
	animations->Add(E_PANTHER, DEAD, ani);
	animations->Add(E_CLOAKMAN, DEAD, ani);
	animations->Add(E_GUNMAN, DEAD, ani);
	animations->Add(E_RUNMAN, DEAD, ani);
	animations->Add(E_BAZOKA, DEAD, ani);
	animations->Add(E_SWORDMAN, DEAD, ani);
	/*animations->Add(ENEMY, DEAD, ani);*/

	//------------LoadAnimation Item Holder
	ani = new Animation(100);
	ani->Add(17001);
	ani->Add(17002);
	animations->Add(IH_BUTTERFLY, STANDING, ani);
	ani = new Animation(100);
	ani->Add(17001);
	ani->Add(17002);
	animations->Add(IH_BUTTERFLY, RUNNING, ani);
	
}

void AnimationManager::Add(TypeObject _type, State _state, LPANIMATION ani)
{
	unordered_map<TypeObject, LPANIMATION> anim;
	anim[_type] = ani;
	oAnimations.insert({ _state , anim });
}

LPANIMATION AnimationManager::Get(TypeObject _type, State _state)
{
	pair< unordered_multimap<State, unordered_map<TypeObject, LPANIMATION>>::iterator, unordered_multimap<State, unordered_map<TypeObject, LPANIMATION>>::iterator> range = oAnimations.equal_range(_state);
	unordered_multimap<State, unordered_map<TypeObject, LPANIMATION>>::iterator it;
	for (it = range.first; it != range.second; ++it) {
		if (it->second.find(_type) != it->second.end()) {
			return it->second[_type];
		}	
	}
	return NULL;
}
