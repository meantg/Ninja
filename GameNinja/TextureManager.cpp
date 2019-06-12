#include "TextureManager.h"
TextureManager * TextureManager::_instance = NULL;
void TextureManager::StartUp()
{
	TextureManager * textures = TextureManager::GetInstance();

	textures->Add(Ninja_Text, "Ninja.png", D3DCOLOR_XRGB(255, 163, 177));
	textures->Add(Stage3_1, "MapReader/tiles.png", D3DCOLOR_XRGB(255, 163, 177));
	textures->Add(BBox_Texture, "Bbox.png", D3DCOLOR_XRGB(255, 163, 177));
	textures->Add(Enemy_Texture, "Enemy.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(Item_Texture, "item.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(Font_Texture, "Font.png", D3DCOLOR_XRGB(0, 0, 0));
}

void TextureManager::Add(Tag tag, LPCSTR filePath, D3DCOLOR transparentColor)
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

	textures[tag] = texture;
}

LPDIRECT3DTEXTURE9 TextureManager::GetTexture(Tag tag)
{
	return textures[tag];
}

TextureManager * TextureManager::GetInstance()
{
	if (_instance == NULL) _instance = new TextureManager();
	return _instance;
}
