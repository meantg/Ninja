﻿#include "GameGlobal.h"

LPD3DXSPRITE spriteHandler = nullptr;			// SpriteHanlder hiện tại
LPDIRECT3DDEVICE9 d3ddev = nullptr;				// Device directX hiện tại (nhằm đại diện card màn hình)
LPDIRECT3DSURFACE9 backBuffer = nullptr;		// BackBuffer
LPDIRECT3DSURFACE9 surface = nullptr;
bool isGameRunning = true;						// Kiểm tra trạng thái game đang chạy HINSTANCE hIN
std::unordered_map<int, bool> keyCode;