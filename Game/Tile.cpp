#include "../stdafx.h"
#include "Monster.h"
#include "Bullet.h"
#include "Character.h"
#include "CameraPlayerManager.h"
#include "Tile.h"

Tile::Tile(bool isAnim, Point location, float depth, Rect rect, wstring name)
	:isAnim(isAnim), location(location), depth(depth), rect(rect)
	, name(name), isIntersect(false), hp(5), isOver(false), isGen(false)
	, flag(false)
{
}

Tile::~Tile()
{
	SAFE_DELETE(anim);
	SAFE_DELETE(drawer);
}

Animation ** Tile::GetAnimation()
{
	return &anim;
}

TextureDrawer ** Tile::GetDrawer()
{
	return &drawer;
}

bool Tile::IsIntersect(Monster* monster)
{
	bool isIntersect = false;
	for (size_t i = 0; i < rects.size(); i++)
	{
		if (Rect::Intersect(monster->GetRect(), rects[i]->GetRect()))
		{
			Rect rect = monster->GetRect();
			monster->SetLocation(rect.location.x,
				rects[i]->GetRect().location.y - rect.size.height + 0.1f);
			if (monster->GetMonsterState() == jumpState)
				monster->SetMonsterState(idleState);
			isIntersect = true;
		}
	}

	if (rects.size() <= 0)
		isIntersect = true;
	return isIntersect;
}

bool Tile::IsIntersect(Bullet* bullet)
{
	for (size_t i = 0; i < rects.size(); i++)
	{
		if (Rect::Intersect(rects[i]->GetRect(), bullet->GetRect()))
			return true;
	}
	return false;
}

bool Tile::IsIntersect(Character * character)
{
	for (size_t i = 0; i < rects.size(); i++)
	{
		if (Rect::Intersect(rects[i]->GetRect(), character->GetIntersectRect()))
			return true;
	}
	return false;
}

Rect::Direction Tile::IsIntersectDirection(Bullet * bullet, Rect& rect)
{
	for (size_t i = 0; i < rects.size(); i++)
	{
		if (Rect::Intersect(rects[i]->GetRect(), bullet->GetRect()))
		{
			rect = rects[i]->GetRect();
			return Rect::IntersectDir(rects[i]->GetRect(), bullet->GetRect());
		}
	}
	return Rect::Direction::None;
}

void Tile::RectPushBack(RectDrawer * rect)
{
	rects.push_back(rect);
}

vector<RectDrawer*> Tile::GetRectDrawer() const
{
	return rects;
}

void Tile::InsertVector(vector<RectDrawer*> vec)
{
	rects.insert(rects.end(), vec.begin(), vec.end());
}

void Tile::Update()
{
	if (isAnim)
	{
		if (anim->GetCurCount() >= (UINT)anim->GetClipCount() - 1)
			flag = true;
		anim->Update();
		if (wcscmp(name.c_str(), L"Beach4_BigShipGate") == 0)
		{
			if (isGen == false)
				anim->SetCurCount(0);
		}
	}

	if (hp <= 0)
	{
		//TODO 파괴 애니메이션 호출 및 애니메이션 종료시 isover = true
		if (wcscmp(name.c_str(), L"TargetGate") == 0)
			//TargetGate2
		{
			DeadClass::GetInstance()->Push
			(
				new DeadEffect1(GetIntersectRect(), Size(2, 2), L"ExplosionBig", 5, Size(114, 118))
			);
			DeadClass::GetInstance()->Push
			(
				new DeadEffect2(GetIntersectRect(), Size(5, 5), L"BuildingDestroy", 9, Size(46, 39))
			);
		}
		isOver = true;
	}
}

void Tile::Render()
{
	Direct2D::SetWorldLocation(location, depth, Size());

	if (isAnim)
		anim->Render();
	else
		drawer->Render();

	/*for (size_t i = 0; i < rects.size(); i++)
	{
		Direct2D::SetWorldLocation(rects[i]->GetRect().location, -1, Size(2, 2));
		rects[i]->Render();
	}*/
}
