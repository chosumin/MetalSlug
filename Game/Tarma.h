#pragma once
#include "Character.h"

class Tarma : public Character
{
public:
	Tarma(Rect rect, float speed = 4.0f, Size ratio = Size(2, 2));
	~Tarma();
private:
	void AddImage(Size ratio);
};