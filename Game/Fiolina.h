#pragma once
#include "Character.h"

class Fiolina : public Character
{
public:
	Fiolina(Rect rect, float speed = 4.0f, Size ratio = Size(2, 2));
	~Fiolina();
private:
	void AddImage(Size ratio);
};