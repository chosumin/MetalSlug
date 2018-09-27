#include "../stdafx.h"
#include "HeavyWeapon.h"

HeavyWeapon::HeavyWeapon(Point location, float angle)
	:Bullet(location, angle)
{
	rect = Rect(4, 20, 30, 5);
	ImageCuttingManager::GetInstance()->CreateTexture(&drawer, L"HeavyWeapon", rect, Size(2, 2), 0);
}

HeavyWeapon::~HeavyWeapon()
{
	SAFE_DELETE(drawer);
}

void HeavyWeapon::Update()
{
	float radian = Math::DegreeToRadian(angle);
	location.x += cosf(radian) * 14;
	location.y += sinf(radian) * 14;
}

void HeavyWeapon::Render()
{
	Direct2D::SetWorldRotationLocation(location, 0, rect.size, angle);
	drawer->Render();
}

