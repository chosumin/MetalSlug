#pragma once

class Bullet;
class Gun
{
public:
	Gun(Point location);
	virtual ~Gun();

	void SetLocation(const Point location)
	{
		this->location = location;
	}
	Point GetLocation() const
	{
		return location;
	}
	bool GetIsAttack() const { return isAttack; }
	void SetIsAttack(bool a) { isAttack = a; }
	void SetAngle(float angle) { this->angle = angle; }

	wstring GetName() const { return gunName; }
	void SetName(wstring a) { gunName = a; }

	int GetBulletCount() const { return bulletCount; }
	void SetBulletCount(wstring name);

	vector<Bullet*> GetBullet() const { return bullets; }

	void Attack();

	virtual void Update();
	void Render();
protected:
	void DeleteBullet();
	void HeavyWeaponAttack();
	float heavyAngle;
	bool isAttack;
	float angle;
	Rect r; //소스에서 자르는 위치, 크기
	vector<Bullet*> bullets;

	bool isHeavyAttack;
	Point location; //총알 발사 위치
	wstring gunName;
	DWORD prevTime;

	int bulletCount; //총알 제한 수
};