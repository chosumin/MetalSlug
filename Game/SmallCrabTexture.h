#pragma once

struct SmallCrabTexture
{
	SmallCrabTexture()
	{
		wstring fileName = L"./Textures/Crab.png";
		DWORD colorKey = 0xFF6080B8;
		TextureManager::GetInstance()->Load(fileName, colorKey);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"SmallCrab_idle", 7, Point(4, 4), Size(53, 45), 0, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"SmallCrab_move", 6, Point(6, 80), Size(51, 45), 14, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"SmallCrab_jump", 2, Point(486, 70), Size(54, 52), 14, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"SmallCrab_meleeAttack", 8, Point(62, 415), Size(75, 51), 1, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"SmallCrab_rangeAttack", 6, Point(143, 491), Size(58, 46), 12, colorKey
			); 

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"SmallCrab_dead", 9, Point(142, 562), Size(58, 42), 10, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
			(
			fileName, L"SmallCrab_bubble", 5, Point(707, 504), Size(17, 17), 4, colorKey
			);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"SmallCrab_ruins", 5, Point(11, 808), Size(44, 31), 3, colorKey
		);
	}
};