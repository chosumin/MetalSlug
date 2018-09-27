#pragma once
#include "Monster.h"

class SmallCrab : public Monster, public IMonster
{
public:
	SmallCrab(Point location, int version, Size ratio = Size(2, 2), float speed = 3);
	~SmallCrab();

	void Initialize(); //���� �ǰ� �ʱ⿡ �ϴ� �����ӵ�
	void Idle();
	void Attack(Character* character);
	void Dead();
private:
	void AddImage(Size ratio);
	int i;
};