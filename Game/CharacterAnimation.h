#pragma once

class CharacterAnimation
{
public:
	CharacterAnimation();
	virtual ~CharacterAnimation();

protected:
	Animation* attackOn_upper_right_pistol_idle_1; //lower_idle
	Animation* attackOn_upper_right_pistol_upHold; //lower_idle
	Animation* attackOn_upper_right_pistol_down; //lower_jump
	Animation* attackOn_right_pistol_sit;

	Animation* attackOff_upper_right_pistol_idle_1; //lower_idle
	Animation* attackOff_upper_right_pistol_move; //lower_move
	Animation* attackOff_upper_right_pistol_jump; //lower_jump
	Animation* attackOff_upper_right_pistol_upHold; //lower_idle
	Animation* attackOff_upper_right_pistol_down; //lower_jump
	Animation* attackOff_right_pistol_sit;

	Animation* right_bomb;

	Animation* lower_right_idle;
	Animation* lower_right_move;
	Animation* lower_right_jump;

	//////////////////////////////////////

	Animation* attackOn_upper_left_pistol_idle_1; //lower_idle
	Animation* attackOn_upper_left_pistol_upHold; //lower_idle
	Animation* attackOn_upper_left_pistol_down; //lower_jump
	Animation* attackOn_left_pistol_sit;

	Animation* attackOff_upper_left_pistol_idle_1; //lower_idle
	Animation* attackOff_upper_left_pistol_move; //lower_move
	Animation* attackOff_upper_left_pistol_jump; //lower_jump
	Animation* attackOff_upper_left_pistol_upHold; //lower_idle
	Animation* attackOff_upper_left_pistol_down; //lower_jump
	Animation* attackOff_left_pistol_sit;

	Animation* left_bomb;

	Animation* lower_left_idle;
	Animation* lower_left_move;
	Animation* lower_left_jump;

	////////Heavy Weapon/////////

	Animation* attackOn_upper_right_heavyWeapon_idle_1; //lower_idle
	Animation* attackOn_upper_right_heavyWeapon_upHold; //lower_idle
	Animation* attackOn_upper_right_heavyWeapon_down; //lower_jump
	Animation* attackOn_right_heavyWeapon_sit;

	Animation* attackOff_upper_right_heavyWeapon_idle_1; //lower_idle
	Animation* attackOff_upper_right_heavyWeapon_move; //lower_move
	Animation* attackOff_upper_right_heavyWeapon_jump; //lower_jump
	Animation* attackOff_upper_right_heavyWeapon_upHold; //lower_idle
	Animation* attackOff_upper_right_heavyWeapon_down; //lower_jump
	Animation* attackOff_right_heavyWeapon_sit;

	Animation* attackOn_upper_left_heavyWeapon_idle_1; //lower_idle
	Animation* attackOn_upper_left_heavyWeapon_upHold; //lower_idle
	Animation* attackOn_upper_left_heavyWeapon_down; //lower_jump
	Animation* attackOn_left_heavyWeapon_sit;

	Animation* attackOff_upper_left_heavyWeapon_idle_1; //lower_idle
	Animation* attackOff_upper_left_heavyWeapon_move; //lower_move
	Animation* attackOff_upper_left_heavyWeapon_jump; //lower_jump
	Animation* attackOff_upper_left_heavyWeapon_upHold; //lower_idle
	Animation* attackOff_upper_left_heavyWeapon_down; //lower_jump
	Animation* attackOff_left_heavyWeapon_sit;

	Animation* dead_left;
	Animation* dead_right;
};