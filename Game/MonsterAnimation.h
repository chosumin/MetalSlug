#pragma once

class MonsterAnimation
{
public:
	MonsterAnimation();
	virtual ~MonsterAnimation();

protected:
	Animation* idle_left;
	Animation* idle_right;

	Animation* move_left;
	Animation* move_right;

	Animation* jump_left;
	Animation* jump_right;

	Animation* attack_left;
	Animation* attack_right;

	Animation* dead_left;
	Animation* dead_right;
};