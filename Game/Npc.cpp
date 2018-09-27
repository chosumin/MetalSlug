#include "../stdafx.h"
#include "Npc.h"

Npc::Npc(Point location, wstring itemName)
	: location(location), ns(IdleStateNpc), name(itemName)
{
	AddImage(itemName);
	
	rect = new RectDrawer(GetRect(), 0, 0xFFFFFFFF);
}

Npc::~Npc()
{
	SAFE_DELETE(idle);
	SAFE_DELETE(giveItem);
	SAFE_DELETE(item);
}

void Npc::Update()
{
	if (ns == IdleStateNpc || ns == IntersectNpc)
		idle->Update();
	else if (ns == GiveItemNpc)
		giveItem->Update();
}

void Npc::Render()
{
	Direct2D::SetWorldLocation(location, 0, Size(2, 2));
	if (ns == IdleStateNpc)
	{
		idle->SetCurCount(0);
		idle->Render();
	}
	else if (ns == IntersectNpc)
	{
		idle->Render();
		if (idle->GetCurCount() >= (UINT)idle->GetClipCount() - 1)
			ns = GiveItemNpc;
	}
	else if (ns == GiveItemNpc)
	{
		giveItem->Render();
		if (giveItem->GetCurCount() >= (UINT)giveItem->GetClipCount() - 1)
			ns = ItemNpc;
	}
	else if (ns == ItemNpc)
	{
		Point point = location;
		point.x += 5;
		point.y += 40;
		Direct2D::SetWorldLocation(point, 0, Size(2, 2));
		item->Render();
	}
	//rect->Render();
}

void Npc::AddImage(wstring name)
{
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &idle, L"IdleNpc", 100, Size(2, 2), 9, Size(42, 38), 0
		);

	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false, &giveItem, L"GiveItem", 100, Size(2, 2), 5, Size(42, 38), 0
		);

	if (wcscmp(name.c_str(), L"RocketLauncher") == 0)
	{
		ImageCuttingManager::GetInstance()->CreateTexture
		(
			&item, L"ItemRocketLauncher", Rect(250, 326, 26, 23), Size(2, 2), 0
		);
	}
	else
	{
		ImageCuttingManager::GetInstance()->CreateTexture
		(
			&item, L"ItemHeavyWeapon", Rect(570, 9, 26, 23), Size(2, 2), 0
		);
	}
}