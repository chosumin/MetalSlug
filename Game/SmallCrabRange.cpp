#include "../stdafx.h"
#include "Character.h"
#include "Bullet.h"
#include "Bubble.h"
#include "SmallCrabRange.h"

SmallCrabRange::SmallCrabRange(Point location, int version, Size ratio, float speed)
	:Monster(location, ratio, speed, 200, 400), i(0)
{
	iMonster = this;
	hp = 2;
	this->version = version;
	AddImage(Size(2, 2));
	rect.location = location;
	rect.size = GetAnimation()->GetSize();
	intersectRect = rect;
	drawer = new RectDrawer(rect, 0, 0xFFFFFFFF);
}

SmallCrabRange::~SmallCrabRange()
{

}

void SmallCrabRange::Initialize()
{
	switch (version)
	{
		case 0:
		{
			if (i < 60)
			{
				i++;
				rect.location.x -= speed;

				if (i >= 60)
				{
					ms = idleState;
				}
			}
		}
		break;
		case 1:
		{
			if (i < 100)
			{
				i++;
				rect.location.x -= speed;

				ms = moveState;
				if (i >= 100)
				{
					ms = idleState;
				}
			}
		}
		break;
		case 2:
		{
			if(ms == initialState)
				ms = idleState;
		}
		break;
	}
	intersectRect = rect;

	attackCheckRect = Rect(intersectRect.location.x - attackCheckRange, intersectRect.location.y,
						   intersectRect.size.width + 2 * attackCheckRange, intersectRect.size.height);

	attackRect = Rect(intersectRect.location.x - attackRange, intersectRect.location.y,
					  intersectRect.size.width + 2 * attackRange, intersectRect.size.height);
}

void SmallCrabRange::Idle()
{
	if (ms == initialState) return;

	DWORD curTime = timeGetTime();
	if (curTime - idlePrevTime > 2000)
	{
		if (dst == 0)
		{
			md = rand() % 2 == 0 ? rightDirection : leftDirection;
			dst = 1;
		}
		switch (md)
		{
			case rightDirection:
				rect.location.x += 1;
				break;
			case leftDirection:
				rect.location.x -= 1;
				break;
		}
		ms = moveState;
	}

	if (curTime - idlePrevTime > 2100)
	{
		dst = 0;
		ms = idleState;
		idlePrevTime = timeGetTime();
	}
}

void SmallCrabRange::Attack(Character * character)
{
	if (ms != deadState)
	{
		Rect rect = character->GetIntersectRect();
		Point point = intersectRect.location;
		if (Rect::Intersect(attackRect, rect))
		{
			switch (Rect::IntersectDir(attackRect, rect))
			{
				case Rect::Direction::Right:
					md = leftDirection;
					break;
				case Rect::Direction::Left:
					md = rightDirection;
					point.x += intersectRect.GetRight();
					break;
			}
			point.y += 30;
			ms = attackState;
			if (GetAnimation()->GetCurCount() >= (UINT)(GetAnimation()->GetClipCount()) - 1)
			{
				isAttack = false;
				prevTime = timeGetTime();
				float angle = md == rightDirection ? (float)0 : (float)180;
				Bullet* bullet = new Bubble(point, angle);
				bullets.push_back(bullet);
			}
		}
		else
		{
			ms = moveState;
			switch (Rect::IntersectDir(attackRect, rect))
			{
				case Rect::Direction::Right:
					md = leftDirection;
					this->rect.location.x -= speed;
					break;
				case Rect::Direction::Left:
					md = rightDirection;
					this->rect.location.x += speed;
					break;
			}
		}
	}
}

void SmallCrabRange::Dead()
{
	ms = deadState;
	if (isDead == false)
	{
		DeadClass::GetInstance()->Push
		(
			new DeadEffect2(GetIntersectRect(), Size(2, 2), L"SmallCrab_ruins", 5, Size(44, 31))
		);
		isDead = true;
	}
}

void SmallCrabRange::AddImage(Size ratio)
{
	//idle
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &idle_left, L"SmallCrab_idle", 100, ratio, 7, Size(53, 45), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &idle_right, L"SmallCrab_idle", 100, ratio, 7, Size(53, 45), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &move_left, L"SmallCrab_move", 100, ratio, 6, Size(51, 45), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &move_right, L"SmallCrab_move", 100, ratio, 6, Size(51, 45), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &jump_left, L"SmallCrab_jump", 100, ratio, 2, Size(54, 52), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &jump_right, L"SmallCrab_jump", 100, ratio, 2, Size(54, 52), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &attack_left, L"SmallCrab_rangeAttack", 100, ratio, 6, Size(58, 46), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &attack_right, L"SmallCrab_rangeAttack", 100, ratio, 6, Size(58, 46), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &dead_left, L"SmallCrab_dead", 100, ratio, 9, Size(58, 42), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &dead_right, L"SmallCrab_dead", 100, ratio, 9, Size(58, 42), 0
		);
}