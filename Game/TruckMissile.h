#pragma once
#include "Bullet.h"

class TruckMissile : public Bullet
{
public:
	TruckMissile(Point location, float angle);
	~TruckMissile();

	void Update();
	void Render();
private:
	TextureDrawer* drawer;
	bool flag;
	IDeadEffect* deadEffect;
};
