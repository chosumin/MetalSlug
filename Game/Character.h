#pragma once
#include "CharacterAnimation.h"

enum CharacterImortal
{
	ImortalOn, ImotalOff
};
enum CharacterState
{
	IdleState, UpHoldState, 
	MoveState, UpHoldMoveState,
	JumpState, UpHoldJumpState,
	DownState, 
	SitState,
	DeadState
};

enum CharacterDirection//좌우 상태 변화
{
	LeftCharacterState, RightCharacterState	
};

enum CharacterAttack
{
	OnAttack, OffAttack
};

enum CharacterJump
{
	OnJump, OffJump
};

class Gun; //총 상태 변화
class Bullet;
class Character : public CharacterAnimation, public ITimer
{
public:
	Character(Rect rect, float speed = 3.0f);
	virtual ~Character();

	Animation* GetUpperAnimation();
	Animation* GetLowerAnimation();

	CharacterImortal GetCharacterImortal() const { return ci; }
	void SetCharacterImortal(CharacterImortal a) { ci = a; }

	void SetImortalTime(DWORD a) { imortalTime = a; }
	CharacterState GetCharacterState() const { return cs; }
	void SetState(CharacterState cs);
	void SetDirection(CharacterDirection cd);

	CharacterAttack GetAttackState() const { return ca; }
	void SetAttack(CharacterAttack ca);
	void SetLocation(const Point location)
	{
		rect.location = location;
	}
	void SetLocation(float x, float y)
	{
		rect.location.x = x;
		rect.location.y = y;
	}

	Rect& GetRect() { return rect; }
	void SetRect(const Rect a) { rect = a; }

	Point& GetUpperLocation() { return upperLocation; }
	void SetUpperLocation(const Point a) { upperLocation = a; }

	Point GetLocation() const { return rect.location; }
	void SetGunAngle();
	float GetSpeed() const { return speed; }

	Rect GetIntersectRect() const { return intersectRect; }
	void SetIntersectRect(const Rect a) { intersectRect = a; }

	CharacterDirection GetDireciton() const { return cd; }

	bool GetIsJump() const { return isJump; }
	void SetIsJump(bool a) { isJump = a; }

	void SetJumpPoint(const Point location) { jumpPoint = location; }

	Gun* GetGun() const { return gun; }

	DWORD GetAttackDelay() const { return attackDelay; }
	void SetAttackDelay(DWORD a) { attackDelay = a; }

	bool GetIsDead() const { return isDead; }
	void SetIsDead(bool a) { isDead = a; }

	bool GetIsCaptured() const { return isCaptured; }
	void SetIsCaptured(bool a) { isCaptured = a; }

	void PushBackBomb(Bullet* bomb);
	bool GetIsBomb() const { return isBomb; }
	void SetIsBomb(bool a) { isBomb = a; }
	int GetBombCount() const { return bombCount; }
	void SetBombCount() { bombCount -= 1; }

	vector<Bullet*> GetBombs() const { return bombs; }
	void SetGun(wstring name);
	virtual void Update();
	void Render();

	void Event();
protected:
	void Jump();
	void DeleteBombs();
	Rect rect; //하체가 가지는 렉트

	Point upperLocation; //상체 렉트
	Rect intersectRect;

	CharacterState cs;
	CharacterDirection cd;
	CharacterAttack ca;
	CharacterImortal ci;
	DWORD imortalTime;
	Gun* gun;

	float speed;

	DWORD attackDelay;

	bool isJump;
	Point jumpPoint;
	float jumpDst;
	float jumpPower;
	float jumpSpeed;

	bool isDead; //사망 뒤 렌더 방지, 캐릭터 선택용
	bool timer;

	bool isCaptured;

	bool isBomb;
	int bombCount;

	vector<Bullet*> bombs;

	RectDrawer* drawer;
};