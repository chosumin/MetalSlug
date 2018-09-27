#include "../stdafx.h"
#include "FadeEffect.h"

FadeEffect::FadeEffect()
	:color(D3DXCOLOR(0,0,0,0)), i(0)
{ //00 투명 FF 검정
	for (int j = 0; j < 100; j++)
	{
		DWORD co = color;
		RectDrawer* rect = new RectDrawer(Rect(0, 0, WIN_WIDTH, WIN_HEIGHT), -6, co);
		rects.push_back(rect);
		color.a = 0.01f * j;
	}
}

FadeEffect::~FadeEffect()
{
	for (size_t i = 0; i < rects.size(); i++)
		SAFE_DELETE(rects[i]);
}

void FadeEffect::SetFirst()
{
	i = 0;
}

bool FadeEffect::GetLast()
{
	if ((size_t)i >= rects.size() - 1)
		return true;
	else
		i++;
	return false;
}

void FadeEffect::Render()
{
	Point zeroPoint = Point(2 * 2, 170);
	Direct2D::SetWorldLocation(zeroPoint, -5);
	rects[i]->Render();
}


////////////////////////////////////

FadeClass* FadeClass::instance = NULL;

FadeClass * FadeClass::GetInstance()
{
	if (instance == NULL)
		instance = new FadeClass();

	return instance;
}

void FadeClass::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void FadeClass::Add()
{
	effects = new FadeEffect();
}

bool FadeClass::GetLast()
{
	if (effects != NULL)
	{
		return effects->GetLast();
	}

	return false;
}

void FadeClass::DeleteEffect()
{
	if (effects != NULL)
	{
		SAFE_DELETE(effects);
		effects = NULL;
	}
}

void FadeClass::Update()
{
	if(effects != NULL)
		effects->GetLast();
}

void FadeClass::Render()
{
	if (effects != NULL)
		effects->Render();
}


FadeClass::FadeClass()
	: effects(NULL)
{
}

FadeClass::~FadeClass()
{
	SAFE_DELETE(effects);
}