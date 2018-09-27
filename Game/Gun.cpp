#include "../stdafx.h"
#include "Bullet.h"
#include "Pistol.h"
#include "RocketLauncher.h"
#include "HeavyWeapon.h"
#include "../Camera/Camera.h"
#include "Gun.h"

Gun::Gun(Point location)
	: location(location), r(Rect()), angle(0), isAttack(false), gunName(L"Pistol")
	, isHeavyAttack(false), prevTime(timeGetTime()), heavyAngle(0), bulletCount(0)
{
}

Gun::~Gun()
{
	for (size_t i = 0; i < bullets.size(); i++)
		SAFE_DELETE(bullets[i]);
}

void Gun::SetBulletCount(wstring name)
{
	if (wcscmp(name.c_str(), L"HeavyWeapon") == 0)
		bulletCount = 25;
	else
		bulletCount = 10;
}

void Gun::Attack()
{
	Bullet* bullet = NULL;
	if (wcscmp(gunName.c_str(), L"Pistol") == 0)
	{
		bullet = new Pistol(location, angle);
	}
	else if (wcscmp(gunName.c_str(), L"RocketLauncher") == 0)
	{
		bullet = new RocketLauncher(location, angle);
		bulletCount--;
	}
	else if (wcscmp(gunName.c_str(), L"HeavyWeapon") == 0)
	{
		heavyAngle = angle;
		isHeavyAttack = true;
	}
	if(bullet != NULL)
		bullets.push_back(bullet);
}

void Gun::Update()
{
	HeavyWeaponAttack();
	for (size_t i = 0; i < bullets.size(); i++)
		bullets[i]->Update();

	if (bulletCount <= 0)
	{
		gunName = L"Pistol";
		bulletCount = 0;
	}
	DeleteBullet();
}

void Gun::Render()
{
	for (size_t i = 0; i < bullets.size(); i++)
		bullets[i]->Render();
}

void Gun::DeleteBullet()
{
	vector<Bullet*>::iterator iter = bullets.begin();

	for (; iter != bullets.end();)
	{
		if ((*iter)->GetIsIntersect() == true)
		{
			if (wcscmp(gunName.c_str(), L"RocketLauncher") == 0)
			{
				DeadClass::GetInstance()->Push
				(
					new DeadEffect1((*iter)->GetRect(), Size(1, 1), L"RocketDestroy", 4, Size(71, 80))
				);
			}
			else
			{
				DeadClass::GetInstance()->Push
				(
					new DeadEffect1((*iter)->GetRect(), Size(0.5f, 0.5f), L"BulletDestroy", 4, Size(55, 47))
				);
			}
			SAFE_DELETE(*iter);
			iter = bullets.erase(iter);
		}
		else
			iter++;
	}
}

void Gun::HeavyWeaponAttack()
{
	static int count = 0;
	if (isHeavyAttack == true)
	{
		if (timeGetTime() - prevTime > 100)
		{
			count++;
			Bullet* bullet = new HeavyWeapon(location, angle);
			bullets.push_back(bullet);
			prevTime = timeGetTime();
			bulletCount--;
		}

		if (count > 2)
		{
			isHeavyAttack = false;
			count = 0;
		}
	}

}
