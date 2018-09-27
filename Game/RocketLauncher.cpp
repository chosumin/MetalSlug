#include "../stdafx.h"
#include "RocketLauncher.h"

RocketLauncher::RocketLauncher(Point location, float angle)
	:Bullet(location, angle)
{
	rect = Rect(57, 254, 42, 8);
	ImageCuttingManager::GetInstance()->CreateTexture(&drawer, L"RocketLauncher", rect, Size(2, 2), 0);
}

RocketLauncher::~RocketLauncher()
{
	SAFE_DELETE(drawer);
}

void RocketLauncher::Update()
{
	float radian = Math::DegreeToRadian(angle);
	location.x += cosf(radian) * 15;
	location.y += sinf(radian) * 15;
}

void RocketLauncher::Render()
{
	Direct2D::SetWorldRotationLocation(location, 0, rect.size, angle);
	drawer->Render();
}

