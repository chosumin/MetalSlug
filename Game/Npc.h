#pragma once

enum NpcState
{
	IdleStateNpc, IntersectNpc, GiveItemNpc, ItemNpc, EndNpc
};
class Npc
{
public:
	Npc(Point location, wstring itemName);
	~Npc();

	NpcState GetNpcState() const { return ns; }
	void SetNpcState(NpcState a) 
	{
		ns = a; 
	}

	Point GetLocation() const { return location; }
	void SetLocation(const Point a) { location = a; }

	Rect GetRect() { return Rect(location, idle->GetSize()); }
	Rect GetItemRect() { return Rect(location, Size(52, 46)); }

	wstring GetName() const { return name; }

	void Update();
	void Render();
protected:
	void AddImage(wstring name);

	Animation* idle;
	Animation* giveItem;
	TextureDrawer* item;

	NpcState ns;
	Point location;
	RectDrawer* rect;

	wstring name;
};