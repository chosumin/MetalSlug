#pragma once
#include "Bullet.h"

class Bomb : public Bullet
{
public:
	Bomb(Point location, float angle, bool isRight);
	~Bomb();

	void Update();
	void Render();
private:
	TextureDrawer* drawer;
};