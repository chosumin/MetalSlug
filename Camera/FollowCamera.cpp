#include "../stdafx.h"
#include "FollowCamera.h"

FollowCamera::FollowCamera(IFollowCamera* camera)
	:Camera(Point(0, 0)), camera(camera), adjustLocation(Point(0, 0))
{
}

FollowCamera::~FollowCamera()
{
}

void FollowCamera::ChangeCamera(IFollowCamera * camera)
{
	this->camera = camera;
}

void FollowCamera::Update()
{
	Rect rect;
	camera->GetCameraPoint(&rect);

	Point temp = rect.location;
	temp.x -= (float)WIN_WIDTH * 0.5f;
	temp.y -= (float)WIN_HEIGHT * 0.5f;

	temp.x += rect.size.width * 0.5f;
	temp.y += rect.size.height * 0.5f;

	this->location = temp - adjustLocation;

	Camera::Update();
}
