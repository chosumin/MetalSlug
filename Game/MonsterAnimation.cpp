#include "../stdafx.h"
#include "MonsterAnimation.h"

MonsterAnimation::MonsterAnimation()
{

}

MonsterAnimation::~MonsterAnimation()
{
	SAFE_DELETE(idle_left);
	SAFE_DELETE(idle_right);

	SAFE_DELETE(move_left);
	SAFE_DELETE(move_right);

	SAFE_DELETE(jump_left);
	SAFE_DELETE(jump_right);

	SAFE_DELETE(attack_left);
	SAFE_DELETE(attack_right);

	SAFE_DELETE(dead_left);
	SAFE_DELETE(dead_right);
}