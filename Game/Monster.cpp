#include "../stdafx.h"
#include "Bullet.h"
#include "Monster.h"

Monster::Monster(Point location, Size ratio, float speed, float attackRange, float attackCheckRange)
	: rect(Rect()), ms(initialState), md(leftDirection), ratio(ratio), speed(speed)
	, attackRange(attackRange), attackCheckRange(attackCheckRange), attackDelay(200), isAttack(true)
	, prevTime(timeGetTime()), attackCheckRect(Rect()), attackRect(Rect())
	, isIntersectWithPlayer(false), isFly(false), idlePrevTime(timeGetTime())
	, dst(0), isStopTraffic(false), isDead(false)
{
}

Monster::~Monster()
{
	for (size_t i = 0; i < bullets.size(); i++)
	{
		SAFE_DELETE(bullets[i]);
	}
}

Animation* Monster::GetAnimation()
{
	switch (md)
	{
		case leftDirection:
			switch (ms)
			{
				case initialState:	return move_left;
				case idleState:		return idle_left;
				case moveState:		return move_left;
				case jumpState:		return jump_left;
				case attackState:	return attack_left;
				case deadState:		return dead_left;
			}
		case rightDirection:
			switch (ms)
			{
				case initialState:	return move_right;
				case idleState:		return idle_right;
				case moveState:		return move_right;
				case jumpState:		return jump_right;
				case attackState:	return attack_right;
				case deadState:		return dead_right;
			}
	}

	return idle_left;
}

void Monster::SetMonsterState(MonsterState ms)
{
	this->ms = ms;
}

void Monster::SetMonsterDirection(MonsterDirection md)
{
	this->md = md;
}

void Monster::Render()
{
	Point location = rect.location;
	Size size = GetAnimation()->GetSize();
	location.y += rect.size.height - size.height;
	GetAnimation()->Update();
	Direct2D::SetWorldLocation(location, 0, Size(2, 2));
	GetAnimation()->Render();

	for (size_t i = 0; i < bullets.size(); i++)
		bullets[i]->Render();
	/*Direct2D::SetWorldLocation(rect.location, 0, Size(2, 2));
	drawer->Render();*/
}

void Monster::DeleteBullet()
{
	vector<Bullet*>::iterator iter = bullets.begin();
	for (; iter != bullets.end();)
	{
		if ((*iter)->GetIsIntersect() == true || timeGetTime() - (*iter)->GetPrevTime() > 2000)
		{
			SAFE_DELETE(*iter);
			iter = bullets.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}