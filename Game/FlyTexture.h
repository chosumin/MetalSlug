#pragma once

struct FlyTexture
{
	FlyTexture()
	{
		wstring fileName = L"./Textures/locust.png";
		DWORD colorKey = 0x00FF0000;
		TextureManager::GetInstance()->Load(fileName, colorKey);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"Fly_idle", 6, Point(33, 1), Size(72, 58), 22, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"Fly_move", 4, Point(298, 118), Size(71, 60), 6, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"Fly_meleeAttack", 2, Point(327, 313), Size(64, 60), 24, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"Fly_dead", 8, Point(273, 1273), Size(44, 61), 0, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fly_ruins1", 7, Point(19, 1474), Size(33, 35), 0, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fly_ruins2", 6, Point(309, 1479), Size(27, 30), 0, colorKey
		);
	}
};