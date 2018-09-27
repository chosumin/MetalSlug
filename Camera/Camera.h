#pragma once

class Camera
{
public:
	Camera(Point start);
	virtual ~Camera(); //���� �Ҹ���
	void Projection();

	Point GetLocation() const { return location; }
	void SetLocation(const Point a) { location = a; }
	void SetLocation(float x, float y) { location.x = x, location.y = y; }
	virtual	void Update();
protected:
	Point location;
	D3DXMATRIX view, projection;
};