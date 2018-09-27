#include "../stdafx.h"
#include "SmallCrabTexture.h"
#include "TarmaTexture.h"
#include "FiolinaTexture.h"
#include "FlyTexture.h"
#include "CharacterBullet.h"
#include "NpcTexture.h"
#include "TruckTexture.h"
#include "DestroyTexture.h"
#include "UiTexture.h"
#include "IntroTexture.h"
#include "TextureAddManager.h"

TextureAddManager* TextureAddManager::instance = NULL;

TextureAddManager* TextureAddManager::GetInstance()
{
	if (instance == NULL)
		instance = new TextureAddManager();

	return instance;
}

void TextureAddManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void TextureAddManager::Initialize()
{
	FlyTexture();
	SmallCrabTexture();
	FiolinaTexture();
	TarmaTexture();
	CharacterBullet();
	NpcTexture();
	TruckTexture();
	DestroyTexture();
	UiTexture();
	IntroTexture();
}

TextureAddManager::TextureAddManager()
{}

TextureAddManager::~TextureAddManager()
{}