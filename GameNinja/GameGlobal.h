#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

#define SCREEN_WIDTH 608				// Chiều rộng cửa sổ
#define SCREEN_HEIGHT 176			// Chiều dài cửa sổ
#define MAX_FRAME_RATE 60					// FPS
#define WIN_NAME "Game Ninja"
#define WIN_TITLE "Game Ninja"
#define FPS 60
#define KEYBOARD_BUFFERD_SIZE	1024
#define NINJA_WALKING_SPEED		0.2f
#define NINJA_JUMPING_SPEED_Y	0.5f
#define NINJA_GRAVITY			0.2f

//State
#define NINJA_ATK				10
#define NINJA_RUN				11
#define NINJA_STAND

//Animation
#define NINJA_IDLE				0
#define NINJA_ATK_STANDING		1
#define NINJA_THROWING			2
#define NINJA_CLIMBING			3
#define NINJA_RUN_RIGHT			4
#define NINJA_RUN_LEFT			9
#define NINJA_SITTING			5
#define NINJA_ATK_SITTING		6
#define NINJA_JUMP				7
#define NINJA_JUMP_ATK			8


extern LPD3DXSPRITE spriteHandler; //con tro sprite
extern LPDIRECT3DDEVICE9 d3ddev; //con tro den thiet bi
extern LPDIRECT3DSURFACE9 backBuffer; //
extern LPDIRECT3DSURFACE9 surface;
extern bool isGameRunning;

extern enum State
{
	STANDING,			//0		
	
	RUNNING,//1
	RUNNING_LEFT,		//2
	RUNNING_RIGHT,		//3
	JUMPING,			//4
	FALLING,			//5
	SITTING,			//6
	ATTACKING_SIT,		//7
	ATTACKING_STAND	,	//8
	JUMPING_ATK,		//9
	THROWING,			//10
	CLIMBING,			//11	
};					

extern enum TypeObject
{
	PLAYER,
};

extern enum Tag
{
	Ninja_Text,
	Stage3_1,
};