#include "../stdafx.h"
#include "Bomb.h"

Bomb::Bomb(Point location, float angle, bool isRight) //초기 각도는 60으로
	:Bullet(location, angle)
{
	this->isRight = isRight;
	rotateTheta = 0;
	drawer = new TextureDrawer(Size(25, 40), L"Bomb", -1);
	
	rect = Rect(0, 0, 12.5f, 20);
	xDelta = 0;
	yDelta = 0;
	start = location;
	intersectRect = Rect(location.x - 100, location.y - 100, 200, 200);
}

Bomb::~Bomb()
{
	SAFE_DELETE(drawer);
}

void Bomb::Update()
{
	rotateTheta += 5;

	float radian = Math::DegreeToRadian(angle);

	xDelta = cosf(radian) * speed;
	yDelta = sinf(radian) * speed;

	if(isRight == true) //좌우 벽에 부딫힘
		location.x = start.x + xDelta * time;
	else
		location.x = start.x - xDelta * time;
	intersectRect.location.x = location.x - 100;
	
	float dst = yDelta * time + 0.5f * (-9.8f) * time * time;
	if (isTop == true) //위아래 벽에                                                                    부딫힘
		location.y = start.y - dst;
	else //위아래 벽에 부딫힘
		location.y = start.y + dst;
	intersectRect.location.y = location.y - 100;
	
	if(speed > 0)
		time += 0.3f;
}

void Bomb::Render()
{
	Direct2D::SetWorldRotationLocation(location, -1, Size(25, 40), rotateTheta);
	drawer->Render();
}
