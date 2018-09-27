#pragma once

class Bullet
{
public:
	Bullet(Point location, float angle);
	virtual ~Bullet();

	float GetAngle() { return angle; }
	void SetAngle(float angle) { this->angle = angle; }
	
	Point GetLocation() const { return location; }
	void SetLocation(Point point) { location = point; }

	bool GetIsIntersect() const { return isIntersect; }
	void SetIsIntersect(bool a) { isIntersect = a; }

	int GetAttackPower() const { return attackPower; }

	Rect GetRect() { return Rect(location, rect.size); }
	DWORD GetPrevTime() const { return prevTime; }

	//Bomb ����
	void SetReverseX() { xDelta *= -1; }
	float GetXDelta() const { return xDelta; };

	void SetReverseY() { yDelta *= -1; }
	float GetYDelta() const { return yDelta; }

	float GetSpeed() const { return speed; }
	void SetSpeed(float a)
	{
		speed -= a; 
		if (speed <= 0)
			speed = 0;
	}

	bool GetIsRight() const { return isRight; }
	void SetIsRight(bool a) { isRight = a; }

	bool GetIsTop() const { return isTop; }
	void SetIsTop(bool a) { isTop = a; }

	void SetStartX(float a) { start.x = a; }
	void SetStartY(float a) { start.y = a; }

	void SetTime(float a) { time = a; }
	Rect GetIntersectRect() const { return intersectRect; }
	void SetIntersectRect(const Rect a) { intersectRect = a; }
	virtual void Update() = 0;
	virtual void Render() = 0;
protected:
	int attackPower;
	bool isAnim;
	DWORD prevTime;
	float angle;
	Rect rect; //�ڸ��� ũ��, ��ġ

	Point location;

	bool isIntersect;

	//Bomb ����
	float yDelta; //y �ʱ�ӵ�
	float xDelta; //x �ʱ�ӵ�
	float time; //�ð�(�ð��� ���� �ӵ� ��ȭ ����)
	float rotateTheta; //�̹��� ȸ�� ��

	float speed; //�ӵ� ������
	Rect intersectRect; //������ ���� ����

	Point start;
	bool isRight;
	bool isTop;
};