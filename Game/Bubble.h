#pragma once
#include "Bullet.h"

class Bubble : public Bullet
{
public:
	Bubble(Point location, float angle);
	~Bubble();

	void Update();
	void Render();
private:
	Animation* anim;
};