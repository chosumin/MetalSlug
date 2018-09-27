#include "../stdafx.h"
#include "Character.h"
#include "Bullet.h"
#include "TruckMissile.h"
#include "Truck.h"

Truck::Truck(Point location, Size ratio, float speed)
	:Monster(location, ratio, speed, 400, 400), i(0), attackFlag(false)
	,truckAttack(timeGetTime())
{
	iMonster = this;
	isFly = true;
	hp = 12;
	AddImage(Size(2, 2));
	rect.location = location;
	rect.size = GetAnimation()->GetSize();
	intersectRect = rect;
	deadEffect = NULL;
	drawer = new RectDrawer(rect, 0, 0xFFFFFFFF);
}

Truck::~Truck()
{

}

void Truck::Initialize()
{
	if (i < 150)
	{
		i++;
		rect.location.x -= 2;

		if (i >= 150)
		{
			ms = idleState;
			isStopTraffic = true;
		}
	}

	intersectRect = rect;

	intersectRect.size.height = GetAnimation()->GetSize().height;
	attackCheckRect = Rect(intersectRect.location.x - attackCheckRange, intersectRect.location.y,
						   intersectRect.size.width + 2 * attackCheckRange, intersectRect.size.height);

	attackRect = Rect(intersectRect.location.x - attackRange, intersectRect.location.y,
					  intersectRect.size.width + 2 * attackRange, intersectRect.size.height);
}

void Truck::Idle()
{
	//do-nothing
	ms = idleState;
}

void Truck::Attack(Character * character)
{
	static int j = 0;
	if (ms != deadState)
	{
		ms = attackState;

		if (timeGetTime() - truckAttack > attackDelay)
		{
			TruckMissile* missile = new TruckMissile(Point(rect.location.x + 50, rect.location.y), 0);
			bullets.push_back(missile);
			j++;
			truckAttack = timeGetTime();
		}

		if (j >= 5)
		{
			isAttack = false;
			prevTime = timeGetTime();
			attackFlag = false;
			j = 0;
		}
	}
}

void Truck::Dead()
{
	if (deadEffect == NULL)
	{
		deadEffect = new DeadEffect1(rect, Size(2, 2), L"ExplosionBig", 5, Size(114, 118));
		DeadClass::GetInstance()->Push(deadEffect);
	}
	ms = deadState;
}

void Truck::AddImage(Size ratio)
{
	//idle
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &idle_left, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &idle_right, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &move_left, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &move_right, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &jump_left, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &jump_right, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attack_left, L"Truck_attack", 100, ratio, 6, Size(128, 187), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &attack_right, L"Truck_attack", 100, ratio, 6, Size(128, 187), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &dead_left, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &dead_right, L"Truck_idle", 100, ratio, 4, Size(128, 132), 0
	);
}