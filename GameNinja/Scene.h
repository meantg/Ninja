#pragma once
#include "d3d9.h"
#include "d3dx9.h"

class Scene
{
protected:
	D3DCOLOR _backColor;						// Màu nền
	Scene();									// Constructor khởi tạo cho abstract factory

public:
	virtual void Update(float dt) {};			// Update các thông số sau khoảng delta-time
	virtual void Render() {};					// Render các UI Components lên Scene
	D3DCOLOR GetBackColor();			
	
	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
};