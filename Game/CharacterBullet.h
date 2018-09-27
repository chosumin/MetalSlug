#pragma once

struct CharacterBullet
{
	CharacterBullet()
	{
		wstring fileName = L"./Textures/WeaponSFX.png";
		DWORD colorKey = 0xFF00F800;
		TextureManager::GetInstance()->Load(fileName, colorKey);
		
		TextureManager::GetInstance()->Add(fileName, L"Pistol", &Rect(247, 201, 9, 6), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"HeavyWeapon", &Rect(4, 20, 30, 5), colorKey);
		
		TextureManager::GetInstance()->Add(fileName, L"RocketLauncher", &Rect(57, 254, 42, 8), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Bomb", &Rect(5, 5956, 11, 18), colorKey);
	}
};