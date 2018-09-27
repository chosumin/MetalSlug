#pragma once

class IDeadEffect
{
public:
	virtual ~IDeadEffect();
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual bool Last() = 0;
};
class DeadEffect1 : public IDeadEffect//�ִϸ��̼� �ϳ���
{
public:
	DeadEffect1(Rect rect, Size ratio, wstring name, int repeatTime,Size srcSize);
	~DeadEffect1();

	void Update();
	void Render();
	bool Last();
private:
	Rect rect;
	Animation* anim;
};

class DeadEffect2 : public IDeadEffect//�翷���� �𳯸�
{
public:
	DeadEffect2(Rect rect, Size ratio, wstring name, int repeatTime, Size srcSize);
	~DeadEffect2();

	void Update();
	void Render();
	bool Last();
private:
	Rect rect;
	Point location;
	Point location1;
	Animation* anim;
	Animation* anim1;
};

class DeadClass //����
{
public:
	static DeadClass* GetInstance();
	static void DeleteInstance();

	void Push(IDeadEffect*);
	void Update();
	void Render();
private:
	DeadClass();
	~DeadClass();

	static DeadClass* instance;

	vector<IDeadEffect*> vec;
};