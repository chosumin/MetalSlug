#pragma once
#include "Bullet.h"

class HeavyWeapon : public Bullet
{
public:
	HeavyWeapon(Point location, float angle);
	~HeavyWeapon();

	void Update();
	void Render();
private:
	TextureDrawer* drawer;
};
