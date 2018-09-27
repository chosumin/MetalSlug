#include "../stdafx.h"
#include "Pistol.h"

Pistol::Pistol(Point location, float angle)
	:Bullet(location, angle)
{
	rect = Rect(247, 201, 9, 6);
	ImageCuttingManager::GetInstance()->CreateTexture(&drawer, L"Pistol", rect, Size(2, 2), 0);
}

Pistol::~Pistol()
{
	SAFE_DELETE(drawer);
}

void Pistol::Update()
{
	float radian = Math::DegreeToRadian(angle);
	location.x += cosf(radian) * 10;
	location.y += sinf(radian) * 10;
}

void Pistol::Render()
{
	Direct2D::SetWorldRotationLocation(location, 0, rect.size, angle);
	drawer->Render(); 
}

