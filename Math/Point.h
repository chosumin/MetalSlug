#pragma once

struct Size;
struct Point
{
	Point();
	Point(const Point& point);
	Point(const Size& size);
	Point(float x, float y);
	Point(const D3DXVECTOR2& vec);
	~Point();

	Point operator+(const Point& point) const;
	Point operator+(const Size& size) const;
	Point operator-(const Point& point) const;
	Point operator*(const Point& point) const;
	Point operator*(const float amount) const;
	Point operator/(const Point& point) const;
	Point operator/(const float amount) const;
	bool Equals(const Point& point) const;

	D3DXVECTOR2 ToVector2();

	static float Distance(const Point& a, const Point& b);

	float x;
	float y;
};