#include "TextureManager.h"

void TextureManager::StartUp()
{
	TextureManager * textures = TextureManager::GetInstance();

	textures->Add(1, "Ninja.png", D3DCOLOR_XRGB(255, 163, 177));
}
