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

	//Bomb 전용
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
	Rect rect; //자르는 크기, 위치

	Point location;

	bool isIntersect;

	//Bomb 전용
	float yDelta; //y 초기속도
	float xDelta; //x 초기속도
	float time; //시간(시간에 대한 속도 변화 측정)
	float rotateTheta; //이미지 회전 각

	float speed; //속도 증감량
	Rect intersectRect; //터진뒤 공격 범위

	Point start;
	bool isRight;
	bool isTop;
};