#include "../stdafx.h"
#include "Tarma.h"

Tarma::Tarma(Rect rect, float speed, Size ratio)
	:Character(rect, speed)
{
	AddImage(ratio);
}

Tarma::~Tarma()
{
}

void Tarma::AddImage(Size ratio)
{
	//attackOff_upper_right_pistol_idle_1
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOff_upper_right_pistol_idle_1,
		L"Tarma_attackOff_upper_pistol_idle1_",
		150,
		ratio,
		4,
		Size(31, 29),
		0, AniRepeatType_Loop, Point(16 - 7, 285 - 265)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOff_upper_left_pistol_idle_1,
		L"Tarma_attackOff_upper_pistol_idle1_",
		150,
		ratio,
		4,
		Size(31, 29),
		0, AniRepeatType_Loop, Point(16 - 7, 285 - 265)
		);

	//attackOff_upper_right_pistol_move
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOff_upper_right_pistol_move,
		L"Tarma_attackOff_upper_pistol_move_",
		100,
		ratio,
		9,
		Size(32, 30),
		0, AniRepeatType_Loop, Point(17 - 6, 603 - 581)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOff_upper_left_pistol_move,
		L"Tarma_attackOff_upper_pistol_move_",
		100,
		ratio,
		9,
		Size(32, 30),
		0, AniRepeatType_Loop, Point(17 - 6, 603 - 581)
		);
	//attackOff_upper_right_pistol_jump
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOff_upper_right_pistol_jump,
		L"Tarma_attackOff_upper_pistol_jump_",
		100,
		ratio,
		6,
		Size(29, 26),
		0, AniRepeatType_Loop, Point(20 - 5, 713 - 689)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOff_upper_left_pistol_jump,
		L"Tarma_attackOff_upper_pistol_jump_",
		100,
		ratio,
		6,
		Size(29, 26),
		0, AniRepeatType_Loop, Point(20 - 5, 713 - 689)
		);

	//attackOff_upper_right_pistol_upHold
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOff_upper_right_pistol_upHold,
		L"Tarma_attackOff_upper_pistol_upHold_",
		150,
		ratio,
		4,
		Size(33, 32),
		0, AniRepeatType_Loop, Point(172 - 162, 791 - 761)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOff_upper_left_pistol_upHold,
		L"Tarma_attackOff_upper_pistol_upHold_",
		150,
		ratio,
		4,
		Size(33, 32),
		0, AniRepeatType_Loop, Point(172 - 162, 791 - 761)
		);
	//attackOff_upper_right_pistol_down
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOff_upper_right_pistol_down,
		L"Tarma_attackOff_upper_pistol_down_",
		150,
		ratio,
		1,
		Size(20, 35),
		0, AniRepeatType_Loop, Point(82 - 74, 822 - 804)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOff_upper_left_pistol_down,
		L"Tarma_attackOff_upper_pistol_down_",
		150,
		ratio,
		1,
		Size(20, 35),
		0, AniRepeatType_Loop, Point(82 - 74, 822 - 804)
		);

	//attackOff_pistol_sit
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOff_right_pistol_sit,
		L"Tarma_attackOff_pistol_sit_",
		150,
		ratio,
		4,
		Size(34, 23),
		0, AniRepeatType_Loop, Point(301 - 289, 885 - 863)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOff_left_pistol_sit,
		L"Tarma_attackOff_pistol_sit_",
		150,
		ratio,
		4,
		Size(34, 23),
		0, AniRepeatType_Loop, Point(301 - 289, 885 - 863)
		);

	//lower_right_idle
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&lower_right_idle,
		L"Tarma_lower_idle_",
		0,
		ratio,
		1,
		Size(21, 16),
		0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&lower_left_idle,
		L"Tarma_lower_idle_",
		0,
		ratio,
		1,
		Size(21, 16),
		0
		);
	//lower_right_move
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&lower_right_move,
		L"Tarma_lower_move_",
		100,
		ratio,
		9,
		Size(32, 20),
		0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&lower_left_move,
		L"Tarma_lower_move_",
		100,
		ratio,
		9,
		Size(32, 20),
		0
		);

	//lower_right_jump
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&lower_right_jump,
		L"Tarma_lower_jump",
		100,
		ratio,
		6,
		Size(29, 25),
		0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&lower_left_jump,
		L"Tarma_lower_jump",
		100,
		ratio,
		6,
		Size(29, 25),
		0
		);

	//attackOn_pistol_idle
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOn_upper_right_pistol_idle_1,
		L"Tarma_attackOn_upper_pistol_idle_1_",
		30,
		ratio,
		10,
		Size(52, 28)
		, 0, AniRepeatType_End, Point(14 - 5, 953 - 931)
		, Point(43 - 5, 940 - 931)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOn_upper_left_pistol_idle_1,
		L"Tarma_attackOn_upper_pistol_idle_1_",
		30,
		ratio,
		10,
		Size(52, 28)
		,0, AniRepeatType_End, Point(14 - 5, 953 - 931)
		, Point(43 - 5, 940 - 931)
		);

	//attackOn_pistol_upHold
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOn_upper_right_pistol_upHold,
		L"Tarma_attackOn_upper_pistol_upHold_",
		70,
		ratio,
		4,
		Size(26, 58),
		0, AniRepeatType_End, Point(170 - 161, 1025 - 969)
		, Point(173 - 161, 980 - 969)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOn_upper_left_pistol_upHold,
		L"Tarma_attackOn_upper_pistol_upHold_",
		70,
		ratio,
		4,
		Size(26, 58),
		0, AniRepeatType_End, Point(170 - 161, 1025 - 969)
		, Point(173 - 161, 980 - 969)
		);

	//attackOn_pistol_down
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOn_upper_right_pistol_down,
		L"Tarma_attackOn_upper_pistol_down_",
		80,
		ratio,
		3,
		Size(20, 52),
		0, AniRepeatType_End, Point(15 - 8, 1054 - 1036)
		, Point(18 - 8, 1070 - 1036)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOn_upper_left_pistol_down,
		L"Tarma_attackOn_upper_pistol_down_",
		80,
		ratio,
		3,
		Size(20, 52),
		0, AniRepeatType_End, Point(15 - 8, 1054 - 1036)
		, Point(18 - 8, 1070 - 1036)
		);

	//attackOn_pistol_sit
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		&attackOn_right_pistol_sit,
		L"Tarma_attackOn_pistol_sit_",
		70,
		ratio,
		4,
		Size(50, 27),
		0, AniRepeatType_End, Point(17 - 7, 1163 - 1138)
		, Point(44 - 7, 1146 - 1138)
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true,
		&attackOn_left_pistol_sit,
		L"Tarma_attackOn_pistol_sit_",
		70,
		ratio,
		4,
		Size(50, 27),
		0, AniRepeatType_End, Point(17 - 7, 1163 - 1138)
		, Point(44 - 7, 1146 - 1138)
		);

	//헤비머신건, 로켓런쳐

	//idle
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_idle_1,
		L"Tarma_attackOff_upper_heavy_idle1_", 100,
		ratio, 4, Size(38, 29)
		, 0, AniRepeatType_Loop, Point(11 - 3, 2007 - 1985)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_idle_1,
		L"Tarma_attackOff_upper_heavy_idle1_", 100,
		ratio, 4, Size(38, 29)
		, 0, AniRepeatType_Loop, Point(11 - 3, 2007 - 1985)
	);

	//move
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_move,
		L"Tarma_attackOff_upper_heavy_move_", 100,
		ratio, 4, Size(38, 29)
		, 0, AniRepeatType_Loop, Point(11 - 3, 2007 - 1985)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_move,
		L"Tarma_attackOff_upper_heavy_move_", 100,
		ratio, 4, Size(38, 29)
		, 0, AniRepeatType_Loop, Point(11 - 3, 2007 - 1985)
	);

	//jump
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_jump,
		L"Tarma_attackOff_upper_heavy_jump_", 100,
		ratio, 6, Size(37, 28)
		, 0, AniRepeatType_Loop, Point(299 - 286, 2383 - 2362)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_jump,
		L"Tarma_attackOff_upper_heavy_jump_", 100,
		ratio, 6, Size(37, 28)
		, 0, AniRepeatType_Loop, Point(299 - 286, 2383 - 2362)
	);

	//uphold
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_upHold,
		L"Tarma_attackOff_upper_heavy_upHold_", 100,
		ratio, 4, Size(30, 36)
		, 0, AniRepeatType_Loop, Point(234 - 225, 2438 - 2408)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_upHold,
		L"Tarma_attackOff_upper_heavy_upHold_", 100,
		ratio, 4, Size(30, 36)
		, 0, AniRepeatType_Loop, Point(234 - 225, 2438 - 2408)
	);

	//down
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_down, 
		L"Tarma_attackOff_upper_heavy_down_", 100,
		ratio, 1, Size(34, 41)
		, 0, AniRepeatType_Loop, Point(104 - 90, 2474 - 2455)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_down,
		L"Tarma_attackOff_upper_heavy_down_", 100,
		ratio, 1, Size(34, 41)
		, 0, AniRepeatType_Loop, Point(104 - 90, 2474 - 2455)
	);

	//sit
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_right_heavyWeapon_sit, 
		L"Tarma_attackOff_heavy_sit_", 100,
		ratio, 4, Size(41, 24)
		, 0, AniRepeatType_Loop, Point(168 - 158, 2539 - 2517)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_left_heavyWeapon_sit,
		L"Tarma_attackOff_heavy_sit_", 100,
		ratio, 4, Size(41, 24)
		, 0, AniRepeatType_Loop, Point(168 - 158, 2539 - 2517)
	);


	//attackOn_heavy_idle
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_upper_right_heavyWeapon_idle_1, 
		L"Tarma_attackOn_upper_heavy_idle_1_", 100,
		ratio, 4, Size(60, 28), 0, AniRepeatType_End
		, Point(13 - 4, 2611 - 2589), Point(41 - 4, 2605 - 2589)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_upper_left_heavyWeapon_idle_1,
		L"Tarma_attackOn_upper_heavy_idle_1_", 100,
		ratio, 4, Size(60, 28), 0, AniRepeatType_End
		, Point(13 - 4, 2611 - 2589), Point(41 - 4, 2605 - 2589)
	);

	//attackOn_heavy_upHold
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_upper_right_heavyWeapon_upHold, 
		L"Tarma_attackOn_upper_heavy_upHold_", 100,
		ratio, 4, Size(24, 70), 0, AniRepeatType_End
		, Point(157 - 147, 2690 - 2623), Point(154 - 147, 2637 - 2623)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_upper_left_heavyWeapon_upHold,
		L"Tarma_attackOn_upper_heavy_upHold_", 100,
		ratio, 4, Size(24, 70), 0, AniRepeatType_End
		, Point(157 - 147, 2690 - 2623), Point(154 - 147, 2637 - 2623)
	);

	//attackOn_heavy_down
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_upper_right_heavyWeapon_down, 
		L"Tarma_attackOn_upper_heavy_down_", 100,
		ratio, 4, Size(34, 64), 0, AniRepeatType_End
		, Point(155 - 141, 2725 - 2706), Point(151 - 141, 2748 - 2706)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_upper_left_heavyWeapon_down,
		L"Tarma_attackOn_upper_heavy_down_", 100,
		ratio, 4, Size(34, 64), 0, AniRepeatType_End
		, Point(155 - 141, 2725 - 2706), Point(151 - 141, 2748 - 2706)
	);

	//attackOn_heavy_sit
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_right_heavyWeapon_sit, 
		L"Tarma_attackOn_heavy_sit_", 100,
		ratio, 4, Size(67, 27), 0, AniRepeatType_End
		, Point(14 - 3, 2881 - 2856), Point(48 - 3, 2862 - 2856)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_left_heavyWeapon_sit,
		L"Tarma_attackOn_heavy_sit_", 100,
		ratio, 4, Size(67, 27), 0, AniRepeatType_End
		, Point(14 - 3, 2881 - 2856), Point(48 - 3, 2862 - 2856)
	);

	//dead
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &dead_right,
		L"Tarma_dead_", 100,
		ratio, 8, Size(31, 34), 0, AniRepeatType_End
		, Point(334 - 318, 5756 - 5724)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &dead_left,
		L"Tarma_dead_", 100,
		ratio, 8, Size(31, 34), 0, AniRepeatType_End
		, Point(334 - 318, 5756 - 5724)
	);

	//bomb
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &right_bomb,
		L"Tarma_bomb_", 100,
		ratio, 4, Size(37, 31), 0, AniRepeatType_End
		, Point(264 - 249, 1231 - 1207), Point(278 - 249, 1212 - 1207)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &left_bomb,
		L"Tarma_bomb_", 100,
		ratio, 4, Size(37, 31), 0, AniRepeatType_End
		, Point(264 - 249, 1231 - 1207), Point(278 - 249, 1212 - 1207)
	);
}
