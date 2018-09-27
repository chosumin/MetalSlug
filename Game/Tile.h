#pragma once

class Monster;
class Bullet;
class Character;
class Tile
{
public:
	Tile(bool isAnim, Point location, float depth, Rect rect, wstring name);
	~Tile();

	Animation** GetAnimation();
	TextureDrawer** GetDrawer();

	bool GetIsGen() const { return isGen; }
	void SetIsGen(bool a) { isGen = a; }
	
	bool GetIsOver() const { return isOver; }
	void SetIsOver(bool a) { isOver = a; }

	bool GetIsIntersect() const { return isIntersect; }
	void SetIsIntersect(bool a) { isIntersect = a; }

	Point GetLocation() const { return location; }
	void SetLocation(const Point a) { location = a; }

	float GetRight() const { return location.x + rect.size.width * 2; }
	float GetBottom() const { return location.y + rect.size.height * 2; }
	float GetWidth() const { return rect.size.width * 2; }
	float GetHeight() const { return rect.size.height * 2; }
	float GetTop() const { return location.y; }
	Rect GetRect() const { return rect; }
	Rect SetRect(const Point location, const Size size)
	{
		return Rect(location, size);
	}

	Rect GetIntersectRect() const
	{
		return Rect(location, rect.size * 2);
	}
	wstring GetName() const { return name; }

	void SetHp(int a) { hp -= a; }

	bool IsIntersect(Monster* monster);
	bool IsIntersect(Bullet* bullet);
	bool IsIntersect(Character* character);
	Rect::Direction IsIntersectDirection(Bullet* bullet, Rect& rect); //반환값이 다른 오버로딩은 허용안됨

	void RectPushBack(RectDrawer* rect);

	vector<RectDrawer*> GetRectDrawer() const;
	void InsertVector(vector<RectDrawer*> vec);
	void Update();
	void Render();
protected:
	wstring name;
	bool isAnim;
	bool isGen; //위치에 도달하면 생성
	bool isOver; //파괴됐는지 체크. true면 애니메이션 발생
	bool isIntersect; //객체와 부딫히면 이벤트 발생
	
	int hp;

	Point location;
	float depth;
	Animation* anim = NULL;
	TextureDrawer* drawer = NULL; 
	Rect rect;

	bool flag;
	vector<RectDrawer*> rects; //충돌 사각형
};