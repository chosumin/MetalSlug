#include "../stdafx.h"
#include "Character.h"
#include "SmallCrab.h"

SmallCrab::SmallCrab(Point location, int version, Size ratio, float speed)
	:Monster(location, ratio, speed, 0, 150), i(0)
{
	iMonster = this;
	this->version = version;
	AddImage(Size(2, 2));
	hp = 2;
	rect.location = location;
	rect.size = GetAnimation()->GetSize();
	intersectRect = rect;
	drawer = new RectDrawer(rect, 0, 0xFFFFFFFF);
}

SmallCrab::~SmallCrab()
{

}

void SmallCrab::Initialize()
{
	switch (version)
	{
		case 0:
		{
			if (ms == initialState)
				ms = idleState;
		}
		break;
		case 1:
		{
			if (i < 100)
			{
				i++;
				rect.location.x -= speed;

				if (i >= 100)
				{
					ms = idleState;
				}
			}
		}
		break;
		case 2:
		{
			if (i < 150)
			{
				i++;
				rect.location.x -= speed;

				if (i >= 150)
				{
					ms = idleState;
				}
			}
		}
		break;
	}
	intersectRect = rect;

	attackCheckRect = Rect(intersectRect.location.x - attackCheckRange, intersectRect.location.y,
						   intersectRect.size.width + 2 * attackCheckRange, intersectRect.size.height);

	attackRect = Rect(intersectRect.location.x - attackRange, intersectRect.location.y,
						   intersectRect.size.width + 2 * attackRange, intersectRect.size.height);
}

void SmallCrab::Idle()
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
		float a = (float)Math::RandomRange(1, 5);
		switch (md)
		{
			case rightDirection:
				rect.location.x += a;
				break;
			case leftDirection:
				rect.location.x -= a;
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

void SmallCrab::Attack(Character * character)
{
	if (ms != deadState)
	{
		Rect rect = character->GetIntersectRect();

		if (Rect::Intersect(attackRect, rect))
		{
			switch (Rect::IntersectDir(attackRect, rect))
			{
				case Rect::Direction::Right:
					md = leftDirection;
					break;
				case Rect::Direction::Left:
					md = rightDirection;
					break;
			}
			ms = attackState;
			if (GetAnimation()->GetCurCount() >= (UINT)(GetAnimation()->GetClipCount()) - 1)
			{
				isAttack = false;
				prevTime = timeGetTime();
				character->SetState(DeadState);
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

void SmallCrab::Dead()
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

void SmallCrab::AddImage(Size ratio)
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
		false, &attack_left, L"SmallCrab_meleeAttack", 100, ratio, 8, Size(75, 51), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &attack_right, L"SmallCrab_meleeAttack", 100, ratio, 8, Size(75, 51), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &dead_left, L"SmallCrab_dead", 100, ratio, 6, Size(58, 46), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &dead_right, L"SmallCrab_dead", 100, ratio, 6, Size(58, 46), 0
		);
}
