#include "../stdafx.h"
#include "DeadAnimation.h"

DeadEffect1::DeadEffect1(Rect rect, Size ratio, wstring name, int repeatTime, Size srcSize)
	:rect(rect)
{
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &anim, name, 100, ratio, repeatTime, srcSize, -2
	);
}

DeadEffect1::~DeadEffect1()
{
	SAFE_DELETE(anim);
}

void DeadEffect1::Update()
{
	anim->Update();
}

void DeadEffect1::Render()
{
	Point location;
	rect.GetHalfLocation(&location);
	location.x -= anim->GetSize().width * 0.5f;
	location.y -= anim->GetSize().height * 0.5f;
	Direct2D::SetWorldLocation(location, 0, Size(), 0);
	anim->Render();
}

bool DeadEffect1::Last()
{
	if ((UINT)anim->GetClipCount() - 1 <= anim->GetCurCount())
		return true;

	return false;
}

///////////////////////////////////

DeadEffect2::DeadEffect2(Rect rect, Size ratio, wstring name, int repeatTime, Size srcSize)
	:rect(rect)
{
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &anim, name, 100, ratio, repeatTime, srcSize, -1
	);

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, &anim1, name, 100, ratio, repeatTime, srcSize, -1
	);
	location = rect.location;
	location1 = Point(rect.GetRight() - srcSize.width * ratio.width, rect.GetTop());
}

DeadEffect2::~DeadEffect2()
{
	SAFE_DELETE(anim);
	SAFE_DELETE(anim1);
}

void DeadEffect2::Update()
{
	location.x -= 1;
	location.y += 2;

	location1.x += 1;
	location1.y += 2;

	anim->Update();
	anim1->Update();
}

void DeadEffect2::Render()
{
	Direct2D::SetWorldLocation(location, 0, Size(), 0);
	anim->Render();

	Direct2D::SetWorldLocation(location1, 0, Size(), 0);
	anim1->Render();
}

bool DeadEffect2::Last()
{
	if ((UINT)anim->GetClipCount() - 1 <= anim->GetCurCount())
		return true;

	return false;
}
/////////////////////////////////
DeadClass* DeadClass::instance = NULL;

DeadClass * DeadClass::GetInstance()
{
	if (instance == NULL)
		instance = new DeadClass();

	return instance;
}

void DeadClass::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void DeadClass::Push(IDeadEffect* a)
{
	vec.push_back(a);
}

void DeadClass::Update()
{
	vector<IDeadEffect*>::iterator iter = vec.begin();

	for (; iter != vec.end();)
	{
		if ((*iter)->Last() == true)
			iter = vec.erase(iter);
		else
			iter++;
	}

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i]->Update();
	}
}

void DeadClass::Render()
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i]->Render();
	}
}

DeadClass::DeadClass()
{
}

DeadClass::~DeadClass()
{
	for (size_t i = 0; i < vec.size(); i++)
		SAFE_DELETE(vec[i]);
}

IDeadEffect::~IDeadEffect()
{
}
