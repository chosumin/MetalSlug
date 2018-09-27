#pragma once
#include "MonsterAnimation.h"

enum MonsterState
{
	initialState, idleState, moveState, jumpState, attackState, deadState
	, flyState
};

enum MonsterDirection
{
	leftDirection, rightDirection
};

class Bullet;
class Character;

class IMonster
{
public:
	virtual void Initialize() = 0; //생성 되고 초기에 하는 움직임들
	virtual void Idle() = 0;
	virtual void Attack(Character* character) = 0;
	virtual void Dead() = 0;
};

class Monster : public MonsterAnimation
{
public:
	Monster(Point location, Size ratio, float speed, float attackRange, float attackCheckRange);
	virtual ~Monster();

	Animation* GetAnimation();
	MonsterState GetMonsterState() const { return ms; }
	void SetMonsterState(MonsterState ms);
	MonsterDirection GetDirection() const { return md; }
	void SetMonsterDirection(MonsterDirection md);

	float GetSpeed() const { return speed; }

	Point GetLocation() const { return rect.location; }
	void SetLocation(float x, float y)
	{
		rect.location.x = x;
		rect.location.y = y;
	}

	Rect GetRect() const { return rect; }
	void SetRect(const Rect a) { rect = a; }
	Rect GetIntersectRect() const { return intersectRect; }
	void SetIntersectRect(Rect a) { intersectRect = a; }

	Rect GetAttackCheckRect() const { return attackCheckRect; }
	void SetAttackCheckRect(Rect a) { attackCheckRect = a; }

	Rect GetAttackRect() const { return attackRect; }
	void SetAttackRect(Rect a) { attackRect = a; }

	float GetAttackRange() const { return attackRange; }
	float GetAttackCheckRange() const { return attackCheckRange; }

	bool GetIsAttack() const { return isAttack; }
	void SetIsAttack(bool a) { isAttack = a; }

	DWORD GetAttackDelay() const { return attackDelay; }
	DWORD GetPrevTime() const { return prevTime; }

	void SetPrevTime(DWORD a) { prevTime = a; }

	bool GetIsFly() const { return isFly; }
	void SetIsFly(bool a) { isFly = a; }

	bool GetIsStopTraffic() const { return isStopTraffic; }
	void SetIsStopTraffic(bool a) { isStopTraffic = a; }

	DWORD GetIdlePrevTime() const { return idlePrevTime; }
	void SetIdlePrevTime(DWORD a) { idlePrevTime = a; }

	int GetHp() const { return hp; }
	void SetHp(int a) { hp -= a; }

	int GetDst() const { return dst; }
	void SetDst(int a) { dst = a; }

	vector<Bullet*> GetBullet() { return bullets; }

	IMonster* GetIMonster() const { return iMonster; }

	void Render();

	void DeleteBullet();
protected:
	virtual void AddImage(Size ratio) = 0;

	Rect rect;

	Rect intersectRect;
	Rect attackCheckRect;
	Rect attackRect;
	Size ratio;
	float speed;

	int hp;

	float attackRange;
	float attackCheckRange;
	bool isAttack;
	DWORD attackDelay;
	DWORD prevTime;

	MonsterState ms;
	MonsterDirection md;
	vector<Bullet*> bullets;

	int version;

	DWORD idlePrevTime;
	int dst;
	bool isIntersectWithPlayer;
	bool isFly;

	bool isDead; //데드 애니메이션 생성용

	bool isStopTraffic;
	RectDrawer* drawer;

	IMonster* iMonster; //전략 패턴
};