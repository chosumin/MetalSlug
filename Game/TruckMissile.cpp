#include "../stdafx.h"
#include "TruckMissile.h"

TruckMissile::TruckMissile(Point location, float angle)
	:Bullet(location, angle), flag(false)
{
	rect = Rect(139, 964, 40, 58);
	deadEffect = NULL;
	ImageCuttingManager::GetInstance()->CreateTexture(&drawer, L"TruckMissile", rect, Size(2, 2), 0);
}

TruckMissile::~TruckMissile()
{
	SAFE_DELETE(drawer);
	deadEffect = new DeadEffect1(GetRect(), Size(2, 2), L"BulletTrigger", 4, Size(26, 37));
	DeadClass::GetInstance()->Push(deadEffect);
}

void TruckMissile::Update()
{
	if (timeGetTime() - prevTime < 400)
	{
		location.y -= 7;
		angle = 180;
	}
	else
	{
		if (flag == false)
		{
			location.x = Math::RandomRange((int)location.x - 500, (int)location.x);
			flag = true;
		}
		location.y += 5;
		location.x += rand() % 2 == 0 ? -0.5f : 0.5f;
		angle = 0;
	}

	
}

void TruckMissile::Render()
{
	Direct2D::SetWorldRotationLocation(location, 0, rect.size, angle);
	drawer->Render();
}

