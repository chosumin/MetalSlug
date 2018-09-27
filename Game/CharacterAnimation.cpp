#include "../stdafx.h"
#include "CharacterAnimation.h"

CharacterAnimation::CharacterAnimation()
{
}

CharacterAnimation::~CharacterAnimation()
{
	SAFE_DELETE(attackOn_upper_right_pistol_idle_1); //lower_idle
	SAFE_DELETE(attackOn_upper_right_pistol_upHold); //lower_idle
	SAFE_DELETE(attackOn_upper_right_pistol_down); //lower_jump
	SAFE_DELETE(attackOn_right_pistol_sit);

	SAFE_DELETE(attackOff_upper_right_pistol_idle_1); //lower_idle
	SAFE_DELETE(attackOff_upper_right_pistol_move); //lower_move
	SAFE_DELETE(attackOff_upper_right_pistol_jump); //lower_jump
	SAFE_DELETE(attackOff_upper_right_pistol_upHold); //lower_idle
	SAFE_DELETE(attackOff_right_pistol_sit);
	SAFE_DELETE(attackOff_upper_right_pistol_down); //lower_jump

	SAFE_DELETE(right_bomb);

	SAFE_DELETE(lower_right_idle);
	SAFE_DELETE(lower_right_move);
	SAFE_DELETE(lower_right_jump);

	/////////////////////////////////////////////////

	SAFE_DELETE(attackOn_upper_left_pistol_idle_1); //lower_idle
	SAFE_DELETE(attackOn_upper_left_pistol_upHold); //lower_idle
	SAFE_DELETE(attackOn_upper_left_pistol_down); //lower_jump
	SAFE_DELETE(attackOn_left_pistol_sit);

	SAFE_DELETE(attackOff_upper_left_pistol_idle_1); //lower_idle
	SAFE_DELETE(attackOff_upper_left_pistol_move); //lower_move
	SAFE_DELETE(attackOff_upper_left_pistol_jump); //lower_jump
	SAFE_DELETE(attackOff_upper_left_pistol_upHold); //lower_idle
	SAFE_DELETE(attackOff_left_pistol_sit);
	SAFE_DELETE(attackOff_upper_left_pistol_down); //lower_jump

	SAFE_DELETE(left_bomb);

	SAFE_DELETE(lower_left_idle);
	SAFE_DELETE(lower_left_move);
	SAFE_DELETE(lower_left_jump);

	//////////////Heavy Weapon//////////////

	SAFE_DELETE(attackOn_upper_right_heavyWeapon_idle_1); //lower_idle
	SAFE_DELETE(attackOn_upper_right_heavyWeapon_upHold); //lower_idle
	SAFE_DELETE(attackOn_upper_right_heavyWeapon_down); //lower_jump
	SAFE_DELETE(attackOn_right_heavyWeapon_sit);

	SAFE_DELETE(attackOff_upper_right_heavyWeapon_idle_1); //lower_idle
	SAFE_DELETE(attackOff_upper_right_heavyWeapon_move); //lower_move
	SAFE_DELETE(attackOff_upper_right_heavyWeapon_jump); //lower_jump
	SAFE_DELETE(attackOff_upper_right_heavyWeapon_upHold); //lower_idle
	SAFE_DELETE(attackOff_right_heavyWeapon_sit);
	SAFE_DELETE(attackOff_upper_right_heavyWeapon_down); //lower_jump

	SAFE_DELETE(attackOn_upper_left_heavyWeapon_idle_1); //lower_idle
	SAFE_DELETE(attackOn_upper_left_heavyWeapon_upHold); //lower_idle
	SAFE_DELETE(attackOn_upper_left_heavyWeapon_down); //lower_jump
	SAFE_DELETE(attackOn_left_heavyWeapon_sit);

	SAFE_DELETE(attackOff_upper_left_heavyWeapon_idle_1); //lower_idle
	SAFE_DELETE(attackOff_upper_left_heavyWeapon_move); //lower_move
	SAFE_DELETE(attackOff_upper_left_heavyWeapon_jump); //lower_jump
	SAFE_DELETE(attackOff_upper_left_heavyWeapon_upHold); //lower_idle
	SAFE_DELETE(attackOff_left_heavyWeapon_sit);
	SAFE_DELETE(attackOff_upper_left_heavyWeapon_down); //lower_jump

	SAFE_DELETE(dead_left);
	SAFE_DELETE(dead_right);
}
