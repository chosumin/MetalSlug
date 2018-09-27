#pragma once
#include "Camera.h"

class IFollowCamera
{
public:
	virtual void GetCameraPoint(Rect* rect) = 0;
};

class FollowCamera : public Camera
{
public:
	FollowCamera(IFollowCamera* camera);
	~FollowCamera();

	void ChangeCamera(IFollowCamera* camera);

	void Update();

private:
	IFollowCamera* camera;
	Point adjustLocation; //위치 보정
};