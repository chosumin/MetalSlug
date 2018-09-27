#include "../stdafx.h"
#include "Character.h"
#include "Fly.h"

Fly::Fly(Point location, int version, Size ratio, float speed)
	:Monster(location, ratio, speed, 300, 300), i(0), dst(0)
	,enemyLocation(Point()), originalPoint(location), check(false), radian(0), check2(false)
	,version(version)
{
	iMonster = this;
	hp = 2;
	AddImage(Size(2, 2));
	isFly = true;
	rect.location = location;
	rect.size = GetAnimation()->GetSize();
	intersectRect = rect;
	drawer = new RectDrawer(rect, 0, 0xFFFFFFFF);
}

Fly::~Fly()
{

}

void Fly::Initialize()
{
	switch (version)
	{
		case 0:
		{
			if (i < 50)
			{
				md = rightDirection;
				ms = initialState;
				i++;
				rect.location.x += speed * 4;
				if (i >= 50)
				{
					ms = idleState;
				}
			}
		}
		break;
		case 1:
		{
			if (i < 50)
			{
				md = rightDirection;
				ms = initialState;
				i++;
				rect.location.x -= speed * 4;
				if (i >= 50)
				{
					ms = idleState;
				}
			}
		}
		break;
	}
	
	intersectRect = rect;
	attackCheckRect = Rect(intersectRect.location.x - attackCheckRange, intersectRect.location.y,
						   intersectRect.size.width + 2 * attackCheckRange, intersectRect.size.height + 2 * attackCheckRange);

	attackRect = Rect(intersectRect.location.x - attackRange, intersectRect.location.y,
					  intersectRect.size.width + 2 * attackRange, intersectRect.size.height + 2 * attackCheckRange);
}

void Fly::Idle()
{
	if (ms == initialState) return;
	ms = idleState;
	
	if (dst > 15)
		rect.location.y -= 0.5f;
	else
		rect.location.y += 0.5f;
		dst++;
	if (dst > 30)
		dst = 0;
}

void Fly::Attack(Character * character)
{
	if (ms != deadState)
	{
		ms = moveState;
		Rect rect = character->GetIntersectRect();

		if (Rect::Intersect(attackRect, rect)) //공격 범위
		{
			Point nowLocation;
			intersectRect.GetHalfLocation(&nowLocation);
			if (check == false)
			{
				rect.GetHalfLocation(&enemyLocation); //플레이어 위치
				intersectRect.GetHalfLocation(&originalPoint); //곤충 렉트
				radian = atan2(enemyLocation.y - originalPoint.y, enemyLocation.x - originalPoint.x);
				check = true;
			}

			this->rect.location.x += 5 * cosf(radian);
			this->rect.location.y += 5 * sinf(radian);
			
			if (nowLocation.y > enemyLocation.y)
				radian = Math::DegreeToRadian(270);

			if (Rect::Intersect(this->rect, rect))
			{
				character->SetIsCaptured(true);
				ms = attackState;
				character->SetLocation(Point(this->rect.location.x + 15, this->rect.GetBottom()));
			}

			if (nowLocation.y < originalPoint.y)
			{
				this->rect.location.y = originalPoint.y - 60;
				isAttack = false;
				check = false;
				if (Rect::Intersect(this->rect, rect))
					character->SetState(DeadState);
			}
		}
	}
}

void Fly::Dead()
{
	ms = deadState;
	if (isDead == false)
	{
		switch (Math::RandomRange(0, 1))
		{
			case 0:
				DeadClass::GetInstance()->Push
				(
					new DeadEffect2(GetIntersectRect(), Size(2, 2), L"Fly_ruins1", 7, Size(33, 35))
				);
				break;
			case 1:
				DeadClass::GetInstance()->Push
				(
					new DeadEffect2(GetIntersectRect(), Size(2, 2), L"Fly_ruins2", 6, Size(27, 30))
				);
				break;
		}
		
		isDead = true;
	}
}

void Fly::AddImage(Size ratio)
{
	//idle
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &idle_left, L"Fly_idle", 100, ratio, 6, Size(72, 58), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &idle_right, L"Fly_idle", 100, ratio, 6, Size(72, 58), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &move_left, L"Fly_move", 100, ratio, 4, Size(71, 60), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &move_right, L"Fly_move", 100, ratio, 4, Size(71, 60), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &jump_left, L"Fly_move", 100, ratio, 4, Size(71, 60), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &jump_right, L"Fly_move", 100, ratio, 4, Size(71, 60), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &attack_left, L"Fly_meleeAttack", 100, ratio, 2, Size(64, 60), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &attack_right, L"Fly_meleeAttack", 100, ratio, 2, Size(64, 60), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &dead_left, L"Fly_dead", 100, ratio, 8, Size(44, 61), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		true, &dead_right, L"Fly_dead", 100, ratio, 8, Size(44, 61), 0
		);
}