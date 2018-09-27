#pragma once

struct FiolinaTexture
{
	FiolinaTexture()
	{
		wstring fileName = L"./Textures/FiolinaGermi.png";
		DWORD colorKey = 0x00FF0000;

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_pistol_idle1_", 5,
			Point(83, 4), Size(28, 26), 4, colorKey
		);//92,22

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_pistol_move_", 6,
			Point(308, 4), Size(29, 26), 3, colorKey
		);//316 ,21

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_pistol_jump_", 6,
			Point(791, 0), Size(30, 27), 4, colorKey
		);//807, 23

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_pistol_upHold_", 4,
			Point(184, 112), Size(25, 23), 4, colorKey
		);//191, 132

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_pistol_down_", 1,
			Point(1053, 42), Size(18, 37), 0, colorKey
		);//1061, 62    //1063,78

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_pistol_sit_", 4,
			Point(274, 214), Size(35, 25), 5, colorKey
		);//287, 237

		//lower_idle
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName,
			L"Fiolina_lower_idle_",
			1,
			Point(150, 1607),
			Size(20, 19),
			0,
			colorKey
		);

		//lower_move
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName,
			L"Fiolina_lower_move_",
			6,
			Point(174, 1606),
			Size(30, 20),
			1,
			colorKey
		);

		//lower_jump
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName,
			L"Fiolina_lower_jump",
			6,
			Point(454, 1602),
			Size(23, 24),
			4,
			colorKey
		);

		//attackOn_pistol_idle
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_upper_pistol_idle_1_", 3,
			Point(43, 45), Size(51, 20), 4, colorKey
		);//50,62	//77,51

		//attackOn_pistol_upHold
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_upper_pistol_upHold_", 4,
			Point(299, 71), Size(20, 64), 5, colorKey
		);//307, 133	//306, 94

		//attackOn_pistol_down
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_upper_pistol_down_", 3,
			Point(1073, 41), Size(18, 58), 5, colorKey
		);//1081,62		//1083, 78
		//Point(289, 863), Size(34, 23)
		//attackOn_pistol_sit
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_pistol_sit_", 3,
			Point(693, 213), Size(52, 27), 5, colorKey
		);//703, 238	//730,219

		//헤비머신건, 로켓런처 애니메이션
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_heavy_idle1_", 4,
			Point(70, 566), Size(38, 25), 6, colorKey
		);//79, 584

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_heavy_move_", 4,
			Point(70, 566), Size(38, 25), 6, colorKey
		);//79, 584

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_heavy_jump_", 5,
			Point(760, 564), Size(36, 25), 4, colorKey
		);//771,585

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_heavy_upHold_", 4,
			Point(642, 665), Size(20, 45), 3, colorKey
		);//650,708

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_upper_heavy_down_", 1,
			Point(1170, 666), Size(28, 38), 0, colorKey
		);//1184, 686

		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOff_heavy_sit_", 4,
			Point(409, 828), Size(46, 25), 5, colorKey
		);//422, 850

		//attackOn_heavy_idle
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_upper_heavy_idle_1_", 4,
			Point(32, 641), Size(59, 26), 7, colorKey
		);//40, 660		//70,656

		//attackOn_heavy_upHold
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_upper_heavy_upHold_", 4,
			Point(446, 594), Size(20, 68), 6, colorKey
		);//455,660		//456,614

		//attackOn_heavy_down
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_upper_heavy_down_", 3,
			Point(839, 596), Size(30, 65), 5, colorKey
		);//850,616		//848,638

		//attackOn_heavy_sit
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_attackOn_heavy_sit_", 3,
			Point(107, 866), Size(65, 25), 5, colorKey
		);//117, 889	//146,869

		//dead
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_dead_", 7,
			Point(420, 3135), Size(41, 49), 34, colorKey
		);//449, 3182

		 //bomb
		ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
		(
			fileName, L"Fiolina_bomb_", 4,
			Point(801, 43), Size(31, 29), 1, colorKey
		);//810, 64		//829,48
	}
};