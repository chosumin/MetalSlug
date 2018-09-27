#pragma once

struct Size
{
	Size();
	Size(const Size& size);
	Size(float width, float height);
	Size(const D3DXVECTOR2& vec);
	~Size();

	Size operator+(const Size& size) const;
	Size operator-(const Size& size) const;
	Size operator*(const Size& size) const;
	Size operator*(const float amount) const;
	Size operator/(const Size& size) const;
	Size operator/(const float amount) const;
	bool Equals(const Size& size) const;
	bool Empty() const;

	D3DXVECTOR2 ToVector2();

	float width;
	float height;
};