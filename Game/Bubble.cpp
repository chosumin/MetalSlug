#include "../stdafx.h"
#include "Bubble.h"

Bubble::Bubble(Point location, float angle)
	:Bullet(location, angle)
{
	rect = Rect(707, 504, 17, 17);
	ImageCuttingManager::GetInstance()->CreateAnimation
	(false, &anim, L"SmallCrab_bubble", 100, Size(2, 2), 5, Size(17, 17), -1);
}

Bubble::~Bubble()
{
	SAFE_DELETE(anim);
}

void Bubble::Update()
{
	float radian = Math::DegreeToRadian(angle);
	location.y += rand() % 2 == 0 ? -0.5f : 0.5f;
	location.x += cosf(radian) * 2;
	location.y += sinf(radian) * 2;

	anim->Update();
}

void Bubble::Render()
{
	Direct2D::SetWorldRotationLocation(location, 0, rect.size, angle);
	anim->Render();
}
