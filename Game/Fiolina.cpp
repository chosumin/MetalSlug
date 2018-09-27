#include "../stdafx.h"
#include "Fiolina.h"

Fiolina::Fiolina(Rect rect, float speed, Size ratio)
	:Character(rect, speed)
{
	AddImage(ratio);
}

Fiolina::~Fiolina()
{
}

void Fiolina::AddImage(Size ratio)
{
	//attackOff_upper_right_pistol_idle_1
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOff_upper_right_pistol_idle_1,
		L"Fiolina_attackOff_upper_pistol_idle1_",
		100,
		ratio,
		5,
		Size(28, 26),
		0, AniRepeatType_Loop, Point(92 - 83, 22 - 4)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOff_upper_left_pistol_idle_1,
		L"Fiolina_attackOff_upper_pistol_idle1_",
		100,
		ratio,
		5,
		Size(28, 26),
		0, AniRepeatType_Loop, Point(92 - 83, 22 - 4)
	);

	//attackOff_upper_right_pistol_move
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOff_upper_right_pistol_move,
		L"Fiolina_attackOff_upper_pistol_move_",
		100,
		ratio,
		5,
		Size(29, 26),
		0, AniRepeatType_Loop, Point(316 - 308, 21 - 4)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOff_upper_left_pistol_move,
		L"Fiolina_attackOff_upper_pistol_move_",
		100,
		ratio,
		5,
		Size(29, 26),
		0, AniRepeatType_Loop, Point(316 - 308, 21 - 4)
	);
	//attackOff_upper_right_pistol_jump
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOff_upper_right_pistol_jump,
		L"Fiolina_attackOff_upper_pistol_jump_",
		100,
		ratio,
		6,
		Size(30, 27),
		0, AniRepeatType_Loop, Point(807 - 791, 23 - 0)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOff_upper_left_pistol_jump,
		L"Fiolina_attackOff_upper_pistol_jump_",
		100,
		ratio,
		6,
		Size(30, 27),
		0, AniRepeatType_Loop, Point(807 - 791, 23 - 0)
	);

	//attackOff_upper_right_pistol_upHold
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOff_upper_right_pistol_upHold,
		L"Fiolina_attackOff_upper_pistol_upHold_",
		150,
		ratio,
		4,
		Size(25, 23),
		0, AniRepeatType_Loop, Point(191 - 184, 132 - 112)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOff_upper_left_pistol_upHold,
		L"Fiolina_attackOff_upper_pistol_upHold_",
		150,
		ratio,
		4,
		Size(25, 23),
		0, AniRepeatType_Loop, Point(191 - 184, 132 - 112)
	);
	//attackOff_upper_right_pistol_down
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOff_upper_right_pistol_down,
		L"Fiolina_attackOff_upper_pistol_down_",
		150,
		ratio,
		1,
		Size(18, 37),
		0, AniRepeatType_Loop, Point(1061 - 1053, 62 - 42)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOff_upper_left_pistol_down,
		L"Fiolina_attackOff_upper_pistol_down_",
		150,
		ratio,
		1,
		Size(18, 37),
		0, AniRepeatType_Loop, Point(1061 - 1053, 62 - 42)
	);

	//attackOff_pistol_sit
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOff_right_pistol_sit,
		L"Fiolina_attackOff_pistol_sit_",
		150,
		ratio,
		4,
		Size(35, 25),
		0, AniRepeatType_Loop, Point(287 - 274, 237 - 214)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOff_left_pistol_sit,
		L"Fiolina_attackOff_pistol_sit_",
		150,
		ratio,
		4,
		Size(35, 25),
		0, AniRepeatType_Loop, Point(287 - 274, 237 - 214)
	);

	//lower_right_idle
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&lower_right_idle,
		L"Fiolina_lower_idle_",
		0,
		ratio,
		1,
		Size(20, 19),
		0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&lower_left_idle,
		L"Fiolina_lower_idle_",
		0,
		ratio,
		1,
		Size(20, 19),
		0
	);
	//lower_right_move
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&lower_right_move,
		L"Fiolina_lower_move_",
		100,
		ratio,
		6,
		Size(30, 20),
		0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&lower_left_move,
		L"Fiolina_lower_move_",
		100,
		ratio,
		6,
		Size(30, 20),
		0
	);

	//lower_right_jump
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&lower_right_jump,
		L"Fiolina_lower_jump",
		100,
		ratio,
		6,
		Size(23, 24),
		0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&lower_left_jump,
		L"Fiolina_lower_jump",
		100,
		ratio,
		6,
		Size(23, 24),
		0
	);

	//attackOn_pistol_idle
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOn_upper_right_pistol_idle_1,
		L"Fiolina_attackOn_upper_pistol_idle_1_",
		100,
		ratio,
		3,
		Size(51, 20)
		, 0, AniRepeatType_End, Point(50 - 43, 62 - 45)
		, Point(77 - 43, 51 - 45)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOn_upper_left_pistol_idle_1,
		L"Fiolina_attackOn_upper_pistol_idle_1_",
		100,
		ratio,
		3,
		Size(51, 20)
		, 0, AniRepeatType_End, Point(50 - 43, 62 - 45)
		, Point(77 - 43, 51 - 45)
	);

	//attackOn_pistol_upHold
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOn_upper_right_pistol_upHold,
		L"Fiolina_attackOn_upper_pistol_upHold_",
		70,
		ratio,
		4,
		Size(20, 64),
		0, AniRepeatType_End, Point(307 - 299, 133 - 71)
		, Point(306 - 299, 94 - 71)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOn_upper_left_pistol_upHold,
		L"Fiolina_attackOn_upper_pistol_upHold_",
		70,
		ratio,
		4,
		Size(20, 64),
		0, AniRepeatType_End, Point(307 - 299, 133 - 71)
		, Point(306 - 299, 94 - 71)
	);

	//attackOn_pistol_down
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOn_upper_right_pistol_down,
		L"Fiolina_attackOn_upper_pistol_down_",
		80,
		ratio,
		3,
		Size(18, 58),
		0, AniRepeatType_End, Point(1081 -1073, 62 - 41)
		, Point(1083 - 1073, 78 - 41)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOn_upper_left_pistol_down,
		L"Fiolina_attackOn_upper_pistol_down_",
		80,
		ratio,
		3,
		Size(18, 58),
		0, AniRepeatType_End, Point(1081 - 1073, 62 - 41)
		, Point(1083 - 1073, 78 - 41)
	);

	//attackOn_pistol_sit
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false,
		&attackOn_right_pistol_sit,
		L"Fiolina_attackOn_pistol_sit_",
		70,
		ratio,
		3,
		Size(52, 27),
		0, AniRepeatType_End, Point(703 - 693, 238 - 213)
		, Point(730 - 693, 219 - 213)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true,
		&attackOn_left_pistol_sit,
		L"Fiolina_attackOn_pistol_sit_",
		70,
		ratio,
		3,
		Size(52, 27),
		0, AniRepeatType_End, Point(703 - 693, 238 - 213)
		, Point(730 - 693, 219 - 213)
	);

	//헤비머신건, 로켓런쳐

	//idle
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_idle_1,
		L"Fiolina_attackOff_upper_heavy_idle1_", 100,
		ratio, 4, Size(38, 25)
		, 0, AniRepeatType_Loop, Point(79 - 70, 584 - 566)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_idle_1,
		L"Fiolina_attackOff_upper_heavy_idle1_", 100,
		ratio, 4, Size(38, 25)
		, 0, AniRepeatType_Loop, Point(79 - 70, 584 - 566)
	);

	//move
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_move,
		L"Fiolina_attackOff_upper_heavy_move_", 100,
		ratio, 4, Size(38, 25)
		, 0, AniRepeatType_Loop, Point(79 - 70, 584 - 566)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_move,
		L"Fiolina_attackOff_upper_heavy_move_", 100,
		ratio, 4, Size(38, 25)
		, 0, AniRepeatType_Loop, Point(79 - 70, 584 - 566)
	);

	//jump
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_jump,
		L"Fiolina_attackOff_upper_heavy_jump_", 100,
		ratio, 5, Size(36, 25)
		, 0, AniRepeatType_Loop, Point(771 - 760, 585 - 564)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_jump,
		L"Fiolina_attackOff_upper_heavy_jump_", 100,
		ratio, 5, Size(36, 25)
		, 0, AniRepeatType_Loop, Point(771 - 760, 585 - 564)
	);

	//uphold
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_upHold,
		L"Fiolina_attackOff_upper_heavy_upHold_", 100,
		ratio, 4, Size(20, 45)
		, 0, AniRepeatType_Loop, Point(650 - 642, 708 - 665)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_upHold,
		L"Fiolina_attackOff_upper_heavy_upHold_", 100,
		ratio, 4, Size(20, 45)
		, 0, AniRepeatType_Loop, Point(650 - 642, 708 - 665)
	);

	//down
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_upper_right_heavyWeapon_down,
		L"Fiolina_attackOff_upper_heavy_down_", 100,
		ratio, 1, Size(28, 38)
		, 0, AniRepeatType_Loop, Point(1184 - 1170, 686 - 666)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_upper_left_heavyWeapon_down,
		L"Fiolina_attackOff_upper_heavy_down_", 100,
		ratio, 1, Size(28, 38)
		, 0, AniRepeatType_Loop, Point(1184 - 1170, 686 - 666)
	);

	//sit
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOff_right_heavyWeapon_sit,
		L"Fiolina_attackOff_heavy_sit_", 100,
		ratio, 4, Size(46, 25)
		, 0, AniRepeatType_Loop, Point(422 - 409, 850 - 828)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOff_left_heavyWeapon_sit,
		L"Fiolina_attackOff_heavy_sit_", 100,
		ratio, 4, Size(46, 25)
		, 0, AniRepeatType_Loop, Point(422 - 409, 850 - 828)
	);


	//attackOn_heavy_idle
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_upper_right_heavyWeapon_idle_1,
		L"Fiolina_attackOn_upper_heavy_idle_1_", 100,
		ratio, 4, Size(59, 26), 0, AniRepeatType_End
		, Point(40 - 32, 660 - 641), Point(70 - 32, 656 - 641)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_upper_left_heavyWeapon_idle_1,
		L"Fiolina_attackOn_upper_heavy_idle_1_", 100,
		ratio, 4, Size(59, 26), 0, AniRepeatType_End
		, Point(40 - 32, 660 - 641), Point(70 - 32, 656 - 641)
	);

	//attackOn_heavy_upHold
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_upper_right_heavyWeapon_upHold,
		L"Fiolina_attackOn_upper_heavy_upHold_", 100,
		ratio, 4, Size(20, 68), 0, AniRepeatType_End
		, Point(455 - 446, 660 - 594), Point(456 - 446, 614 - 594)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_upper_left_heavyWeapon_upHold,
		L"Fiolina_attackOn_upper_heavy_upHold_", 100,
		ratio, 4, Size(20, 68), 0, AniRepeatType_End
		, Point(455 - 446, 660 - 594), Point(456 - 446, 614 - 594)
	);

	//attackOn_heavy_down
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_upper_right_heavyWeapon_down,
		L"Fiolina_attackOn_upper_heavy_down_", 100,
		ratio, 3, Size(30, 65), 0, AniRepeatType_End
		, Point(850 - 839, 616 - 596), Point(848 - 839, 638 - 596)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_upper_left_heavyWeapon_down,
		L"Fiolina_attackOn_upper_heavy_down_", 100,
		ratio, 3, Size(30, 65), 0, AniRepeatType_End
		, Point(850 - 839, 616 - 596), Point(848 - 839, 638 - 596)
	);

	//attackOn_heavy_sit
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attackOn_right_heavyWeapon_sit,
		L"Fiolina_attackOn_heavy_sit_", 100,
		ratio, 3, Size(65, 25), 0, AniRepeatType_End
		, Point(117 - 107, 889 - 866), Point(146 - 107, 869 - 866)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &attackOn_left_heavyWeapon_sit,
		L"Fiolina_attackOn_upper_heavy_down_", 100,
		ratio, 3, Size(65, 25), 0, AniRepeatType_End
		, Point(117 - 107, 889 - 866), Point(146 - 107, 869 - 866)
	);

	//dead
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &dead_right,
		L"Fiolina_dead_", 100,
		ratio, 7, Size(41, 49), 0, AniRepeatType_End
		, Point(449 - 420, 3182 - 3135)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &dead_left,
		L"Fiolina_dead_", 100,
		ratio, 7, Size(41, 49), 0, AniRepeatType_End
		, Point(442 - 420, 3182 - 3135)
	);

	//bomb
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &right_bomb,
		L"Fiolina_bomb_", 100,
		ratio, 4, Size(31, 29), 0, AniRepeatType_End
		, Point(810 - 801, 64 - 43), Point(829 - 801, 48 - 43)
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		true, &left_bomb,
		L"Fiolina_bomb_", 100,
		ratio, 4, Size(31, 29), 0, AniRepeatType_End
		, Point(810 - 801, 64 - 43), Point(829 - 801, 48 - 43)
	);
}
