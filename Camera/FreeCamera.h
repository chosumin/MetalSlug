#pragma once
#include "Camera.h"

class FreeCamera
	: public Camera
{
public:
	FreeCamera(Point start, float speed = 5.0f);
	~FreeCamera();

	void Update();
private:
	float speed;
};