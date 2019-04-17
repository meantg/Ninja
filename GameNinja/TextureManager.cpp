#include "TextureManager.h"
TextureManager * TextureManager::_instance = NULL;
void TextureManager::StartUp()
{
	TextureManager * textures = TextureManager::GetInstance();

	textures->Add(1, "Ninja.png", D3DCOLOR_XRGB(255, 163, 177));
}

void TextureManager::Add(int id, LPCSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);

	LPDIRECT3DTEXTURE9 texture;

	result = D3DXCreateTextureFromFileEx(
		d3ddev,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);

	textures[id] = texture;
}

LPDIRECT3DTEXTURE9 TextureManager::GetTexture(int id)
{
	return textures[id];
}

TextureManager * TextureManager::GetInstance()
{
	if (_instance == NULL) _instance = new TextureManager();
	return _instance;
}
