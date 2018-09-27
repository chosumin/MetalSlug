#pragma once
#include "Bullet.h"

class Pistol : public Bullet
{
public:
	Pistol(Point location, float angle);
	~Pistol();

	void Update();
	void Render();
private:
	TextureDrawer* drawer;
};
