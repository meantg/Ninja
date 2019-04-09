#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "SceneManager.h"
#include "TextureManager.h"
#include "AnimationManager.h"
#include "SpriteManager.h"

class Game
{
private:
	//LPKEYEVENTHANDLER keyHandler;
	static Game* _instance;
	HWND hWnd;
	WNDCLASSEX wc;
	LPDIRECTINPUT8 di8;
	LPDIRECTINPUTDEVICE8 didv8;
	BYTE keyStates[256];
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFERD_SIZE];
	//SceneManager *gSceneManager;
	AnimationManager *gAnimationManager;
	TextureManager *gTextureManager;
	SpriteManager *gSpriteManager;

public:
	Game();
	//void InitKeyboard(LPKEYEVENTHANDLER handler, HINSTANCE hInstance);

	void GameInit(HINSTANCE hInstance, int cmdShow);
	void GameRun(); //Khoi chay game
	void GameStartUp();
	void GameShutDown();

	//virtual void Update(int dt); //cap nhat game theo 1 khoang thoi gian dt
	void Render();//ve khung hinh

	//Xu ly ban phim
	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom);
	static Game* GetInstance();
};
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);