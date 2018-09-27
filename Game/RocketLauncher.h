#pragma once
#include "Bullet.h"

class RocketLauncher : public Bullet
{
public:
	RocketLauncher(Point location, float angle);
	~RocketLauncher();

	void Update();
	void Render();
private:
	TextureDrawer* drawer;
};
