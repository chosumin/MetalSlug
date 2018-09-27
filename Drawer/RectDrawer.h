#pragma once
#include "Drawer.h"

class RectDrawer : public Drawer
{
public:
	RectDrawer(Rect rect, float depth = 0.f, DWORD color = 0xff000000);
	~RectDrawer();

	Rect& GetRect() { return rect; }
	void Render();
private:
	Rect rect;
	DWORD color;
};