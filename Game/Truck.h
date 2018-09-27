#pragma once
#include "Monster.h"

class Truck : public Monster, public IMonster
{
public:
	Truck(Point location, Size ratio = Size(2, 2), float speed = 3);
	~Truck();

	void Initialize(); //���� �ǰ� �ʱ⿡ �ϴ� �����ӵ�
	void Idle();
	void Attack(Character* character);
	void Dead();
private:
	void AddImage(Size ratio);

	int i;
	bool attackFlag;
	DWORD truckAttack;

	IDeadEffect* deadEffect;
};