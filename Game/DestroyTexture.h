#pragma once

struct DestroyTexture
{
	DestroyTexture()
	{
		wstring fileName = L"./Textures/ExplosionSFX.png";
		DWORD colorKey = 0xFF00F800;
		TextureManager::GetInstance()->Load(fileName, colorKey);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"ExplosionBig", 5, Point(2, 2852), Size(114, 118), 0, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"WaterExplosion", 3, Point(8, 1903), Size(53, 16), 7, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"BulletTrigger", 4, Point(60, 48), Size(26, 37), 0, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"BulletDestroy", 4, Point(59, 1464), Size(55, 47), 0, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"RocketDestroy", 4, Point(294, 406), Size(71, 80), 0, colorKey
		);
		fileName = L"./Textures/Mission1_river.png";
		colorKey = 0xFFFFFFFF;
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"BuildingDestroy", 9, Point(1102, 1090), Size(112, 86), 3, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Dust", 9, Point(567, 1290), Size(46, 39), 0, colorKey
		);

		fileName = L"./Textures/Blood.png";
		colorKey = 0x00FF0000;

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Blood", 5, Point(87, 95), Size(41, 34), 0, colorKey
		);
	}
};