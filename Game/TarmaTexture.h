#pragma once

struct TarmaTexture
{
	TarmaTexture()
	{
		wstring fileName = L"./Textures/TarmaRoving.png";
		DWORD colorKey = 0xff56b1de;

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_pistol_idle1_", 4,
			Point(7, 265), Size(31, 29), 4, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_pistol_move_", 9,
			Point(6, 581), Size(32, 30), 4, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_pistol_jump_", 6,
			Point(5, 689), Size(29, 26), 5, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_pistol_upHold_", 4,
			Point(162, 761), Size(33, 32), 6, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_pistol_down_", 1,
			Point(74, 804), Size(20, 35), 0, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_pistol_sit_", 4,
			Point(289, 863), Size(34, 23), 4, colorKey
		);

		//lower_idle
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName,
			L"Tarma_lower_idle_",
			1,
			Point(161, 276),
			Size(21, 16),
			0,
			colorKey
		);

		//lower_move
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName,
			L"Tarma_lower_move_",
			9,
			Point(6, 618),
			Size(32, 20),
			4,
			colorKey
		);

		//lower_jump
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName,
			L"Tarma_lower_jump",
			6,
			Point(5, 730),
			Size(29, 25),
			5,
			colorKey
		);

		//attackOn_pistol_idle
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_upper_pistol_idle_1_", 10,
			Point(5, 931), Size(52, 28), 4, colorKey
		);

		//attackOn_pistol_upHold
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_upper_pistol_upHold_", 4,
			Point(161, 969), Size(26, 58), 4, colorKey
		);

		//attackOn_pistol_down
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_upper_pistol_down_", 3,
			Point(8, 1036), Size(20, 52), 8, colorKey
		);
		//Point(289, 863), Size(34, 23)
		//attackOn_pistol_sit
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_pistol_sit_", 4,
			Point(7, 1138), Size(50, 27), 7, colorKey
		);

		//헤비머신건, 로켓런처 애니메이션
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_heavy_idle1_", 4,
			Point(3, 1985), Size(38, 29), 7, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_heavy_move_", 4,
			Point(3, 1985), Size(38, 29), 7, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_heavy_jump_", 6,
			Point(286, 2362), Size(37, 28), 7, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_heavy_upHold_", 4,
			Point(225, 2408), Size(30, 36), 7, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_upper_heavy_down_", 1,
			Point(90, 2455), Size(34, 41), 0, colorKey
		);

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOff_heavy_sit_", 4,
			Point(158, 2517), Size(41, 24), 7, colorKey
		);

		//attackOn_heavy_idle
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_upper_heavy_idle_1_", 4,
			Point(4, 2589), Size(60, 28), 9, colorKey
		);

		//attackOn_heavy_upHold
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_upper_heavy_upHold_", 4,
			Point(147, 2623), Size(24, 70), 13, colorKey
		);

		//attackOn_heavy_down
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_upper_heavy_down_", 4,
			Point(141, 2706), Size(34, 64), 6, colorKey
		);

		//attackOn_heavy_sit
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_attackOn_heavy_sit_", 4,
			Point(3, 2856), Size(67, 27), 9, colorKey
		);

		//dead
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_dead_", 8,
			Point(318, 5724), Size(31, 34), 0, colorKey
		);//334, 5756

		 //bomb
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Tarma_bomb_", 4,
			Point(249, 1207), Size(37, 31), 1, colorKey
		);//264, 1231		//278, 1212
	}
};