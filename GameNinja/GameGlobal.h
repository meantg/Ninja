#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <WinUser.h>
#include <unordered_map>

#define SCREEN_WIDTH 320			// Chiều rộng cửa sổ
#define SCREEN_HEIGHT 176			// Chiều dài cửa sổ
#define MAX_FRAME_RATE 120				// FPS
#define WIN_NAME "Game Ninja"
#define WIN_TITLE "Game Ninja"
#define KEYBOARD_BUFFER_SIZE	1024


//---------INFOR
	//NINJA 

#define NINJA_WALKING_SPEED		10.0f
#define NINJA_JUMPING_SPEED_Y	20.0f
#define NINJA_FALLING_SPEED_Y   8.0f
#define NINJA_GRAVITY			0.45f
#define NINJA_STANDING_HEIGHT   26
#define NINJA_SITTING_HEIGHT    18
#define NINJA_WIDTH				18

//State
#define NINJA_ATK				10
#define NINJA_RUN				11
#define NINJA_STAND

	//ENEMY
#define ENEMY_SWORDMAN_WIDTH 16
#define ENEMY_SWORDMAN_HEIGHT 25
#define ENEMY_SWORDMAN_SPEED 4.0f



extern LPD3DXSPRITE spriteHandler; //con tro sprite
extern LPDIRECT3DDEVICE9 d3ddev; //con tro den thiet bi
extern LPDIRECT3DSURFACE9 backBuffer; //
extern LPDIRECT3DSURFACE9 surface;
extern bool isGameRunning;
extern std::unordered_map<int, bool> keyCode;

extern enum State
{
	STANDING,			//0		
	RUNNING,//1
	RUNNING_LEFT,		//2
	RUNNING_RIGHT,		//3
	JUMPING,			//4
	FALLING,			//5
	SITTING,			//6
	ATTACKING,
	ATK_SIT,		//7
	ATK_STAND,	//8
	JUMPING_ATK,		//9
	THROWING,			//10
	CLIMBING,			//11
	CLINGING,
	INJURED,
	DEAD,
	E_SW_STANDING,
	E_SW_RUNNING,
};					

extern enum TypeObject
{
	PLAYER,
	ENEMY,
	E_SWORDMAN,
	E_BAZOKA,
	E_RUNMAN,
	E_GUNMAN,
	E_CLOAKMAN,
	E_PANTHER,
	E_EAGLE,
	ITEMHOLDER,
	IH_BUTTERFLY
};

extern enum Tag
{
	Ninja_Text,
	Stage3_1,
	BBox_Texture,
	Enemy_Texture,
	Holder_Texture,
	Item_Texture
};

extern enum TypeItem
{
	MANA,
	HEAL,
	TIME,
};
