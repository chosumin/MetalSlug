#pragma once
class Direct2D
{
public:
	static void Create(HWND winHandle);
	static void Delete();

	static LPDIRECT3DDEVICE9 Device() { return device; }

	static void BeginScene();
	static void EndScene(); //�׸��� ������ �������� ������

	static void SetWorldLocation(Point& location, float depth, Size size = Size(), float angle = 0);
	static void SetWorldRotationLocation(Point& location, float depth, Size size, float angle = 0);
private:
	static LPDIRECT3D9 d3d;
	static LPDIRECT3DDEVICE9 device;
};

