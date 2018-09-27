#pragma once

struct TruckTexture
{
	TruckTexture()
	{
		wstring fileName = L"./Textures/BattleTruck.png";
		DWORD colorKey = 0xFF00F8F8;
		TextureManager::GetInstance()->Load(fileName, colorKey);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap //128, 132
		(
			fileName, L"Truck_idle", 4, Point(31, 26), Size(128, 132), 21, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Truck_attack", 6, Point(5, 173), Size(128, 187), 26, colorKey
		);

		TextureManager::GetInstance()->Add(fileName, L"TruckMissile", &Rect(139, 964, 40, 58), colorKey);
	}
};