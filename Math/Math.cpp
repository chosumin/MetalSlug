#include "../stdafx.h"
#include "Math.h"

const float Math::PI = 3.14159265f;

float Math::DegreeToRadian(float degree)
{
	return degree * PI / 180.0f;
}

float Math::RadianToDegree(float radian)
{
	return radian * 180.0f / PI;
}

//r1 : 랜덤의 하한값
//r2 : 랜덤의 상한값
int Math::RandomRange(int r1, int r2)
{
	return (int)(rand() % (r2 - r1 + 1)) + r1;
}