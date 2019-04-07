#include "TextureManager.h"
TextureManager * TextureManager::_instance = NULL;
void TextureManager::StartUp()
{
	TextureManager * textures = TextureManager::GetInstance();

	textures->Add(1, "Ninja.png", D3DCOLOR_XRGB(255, 163, 177));
}

void TextureManager::Add(int id, LPCSTR filePath, D3DCOLOR transparentColor)
{
}

LPDIRECT3DTEXTURE9 TextureManager::GetTexture(int _state)
{
	return LPDIRECT3DTEXTURE9();
}

TextureManager * TextureManager::GetInstance()
{
	if (_instance == NULL) _instance = new TextureManager();
	return _instance;
}
