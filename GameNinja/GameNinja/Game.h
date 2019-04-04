#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Game
{
private:
	 HWND hWnd; // window handle
	 HINSTANCE hInstance; // The hien
	 LPD3DXSPRITE spriteHandler; //con tro sprite
	 LPDIRECT3DDEVICE9 d3ddev; //con tro den thiet bi
	 int width, height; // thuoc tinh cua window
	 LPDIRECT3DSURFACE9 backBuffer; //
	 LPDIRECT3DSURFACE9 surface;
	 bool isGameRunning;
public:
	void GameInit();
	void KeyboardInit();
	void GameRun();
	virtual void Update(float dt);
	void Render();
};