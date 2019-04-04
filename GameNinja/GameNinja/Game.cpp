#include "Game.h"


Game *Game::_instance = NULL;


void Game::GameInit()
{
	auto d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	// Lấy thông tin khung Windows để tạo Back Buffer
	RECT r;
	GetClientRect(hWnd, &r);
	d3dpp.BackBufferHeight = r.bottom + 1;
	d3dpp.BackBufferWidth = r.right + 1;

	// Tạo Device
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);

	// Lấy BackBuffer
	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	// Tạo Sprite Handler
	D3DXCreateSprite(d3ddev, &spriteHandler);
}

void Game::GameRun()
{
	MSG msg;
	auto frameStart = GetTickCount();
	auto tickPerFrame = 1000 / 120;

	while (isGameRunning)
	{
		// Nếu là thông điệp thoát thì thoát
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				isGameRunning = false;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// Vòng lặp game chính (cập nhật thời gian, thông số và Render lại Frame hình)
		auto now = GetTickCount();
		auto dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			Update(dt);
			Render();
		}
		else
		{
			Sleep(tickPerFrame - dt);
		}
	}
}

void Game::Render()
{
	auto scene = SceneManager::GetInstance()->GetCurScene();
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, scene->GetBackColor(), 0.0f, 0);

	if (d3ddev->BeginScene())
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		scene->Render();
		spriteHandler->End();
		d3ddev->EndScene();
	}
	d3ddev->Present(NULL, NULL, NULL, NULL);
}

void Game::GameStartUp()
{
	TextureManager::GetInstance()->StartUp();
	SpriteManager::GetInstance()->StartUp();
	AnimationManager::GetInstance()->StartUp();
}

Game *Game::GetInstance()
{
	if (_instance == NULL) _instance = new Game();
	return _instance;
}