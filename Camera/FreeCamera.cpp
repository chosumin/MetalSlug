#include "../stdafx.h"
#include "FreeCamera.h"

FreeCamera::FreeCamera(Point start, float speed)
	:Camera(start), speed(speed)
{
}

FreeCamera::~FreeCamera()
{
}

void FreeCamera::Update()
{
	if (KEYBOARD()->KeyPress(VK_UP))
		location.y -= speed;
	else if (KEYBOARD()->KeyPress(VK_DOWN))
		location.y += speed;

	if (KEYBOARD()->KeyPress(VK_LEFT))
		location.x -= speed;
	else if (KEYBOARD()->KeyPress(VK_RIGHT))
		location.x += speed;

	Camera::Update(); //부모의 역할을 수행해줌
}
