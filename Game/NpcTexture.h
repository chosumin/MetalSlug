#pragma once

struct NpcTexture
{
	NpcTexture()
	{
		wstring fileName = L"./Textures/NPC.png";
		DWORD colorKey = 0xFFFFFFFF;
		TextureManager::GetInstance()->Load(fileName, colorKey);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"IdleNpc", 9, Point(0, 16), Size(42, 38), 0, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"GiveItem", 5, Point(155, 397), Size(44, 41), 0, colorKey
			);

		fileName = L"./Textures/WeaponSFX.png";
		colorKey = 0xFF00F800;
		TextureManager::GetInstance()->Add(fileName, L"ItemRocketLauncher", &Rect(250, 326, 26, 23), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"ItemHeavyWeapon", &Rect(570, 9, 26, 23), colorKey);
	}
};