#pragma once
#include "Monster.h"

class Fly : public Monster, public IMonster
{
public:
	Fly(Point location, int version, Size ratio = Size(2, 2), float speed = 3);
	~Fly();

	void Initialize(); //���� �ǰ� �ʱ⿡ �ϴ� �����ӵ�
	void Idle();
	void Attack(Character* character);
	void Dead();
private:
	void AddImage(Size ratio);

	int i;
	int dst;
	
	bool check;
	bool check2;
	Point originalPoint;
	Point enemyLocation;
	float radian;
	int version;
};