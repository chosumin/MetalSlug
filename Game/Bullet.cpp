#include "../stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Point location, float angle)
	:location(location), rect(rect), angle(angle), prevTime(timeGetTime())
	, isIntersect(false), attackPower(1), speed(40), isRight(false),time(0)
	, start(Point()), isTop(true)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
}

void Bullet::Render()
{
}
