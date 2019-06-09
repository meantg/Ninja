#include "Object.h"

Object::Object()
{
}

void Object::Update(float dt)
{
}

void Object::Render(float cameraX, float cameraY)
{	
}

void Object::RenderBoundingBox(float x, float y)
{
	Hitbox hitbox = GetHitbox();
	RECT r;
	r.left = hitbox.left;
	r.top = hitbox.top;
	r.right = hitbox.right;
	r.bottom = hitbox.bottom;
	LPDIRECT3DTEXTURE9 texture = TextureManager::GetInstance()->GetTexture(BBox_Texture);
	D3DXVECTOR3 p(x, y, 0);
	int _width = r.right - r.left;
	int _height = r.bottom - r.top;

	// Nếu có lật hình (theo Ox hay Oy) thì thiết đặt biến đổi hình băng ma trận
	auto pCenter = D3DXVECTOR3(_width >> 1, _height >> 1, 0);
	auto pPosition = D3DXVECTOR3(x, y, 0);
	auto pRotationCenter = D3DXVECTOR2(_width >> 1, _height >> 1);
	auto pScalingCenter = D3DXVECTOR2(x, y);

	D3DXMATRIX oldMatrix, curMatrix;
	D3DXMatrixTransformation2D(&curMatrix, &pScalingCenter, 0, NULL, &pRotationCenter, 0, NULL);
	spriteHandler->GetTransform(&oldMatrix);
	spriteHandler->SetTransform(&curMatrix);
	spriteHandler->Draw(texture, &r, &pCenter, &pPosition, D3DCOLOR_XRGB(255, 255, 255));
	spriteHandler->SetTransform(&oldMatrix);
}

RECT Object::GetRect()
{
	RECT box;
	box.top = y + (height >> 1);
	box.left = x - (width >> 1);
	box.right = box.left + width;
	box.bottom = box.top - height;
	return box;
}

//void Object::AddAnimation(State _state)
//{
//}

Object::~Object(){}




