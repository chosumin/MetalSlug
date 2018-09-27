#pragma once

class ITimer
{
public:
	virtual void Event() = 0;
};

struct TimerData
{
	ITimer* timer;
	DWORD initTime;
	DWORD timeGap;
};

class Timer
{
public:
	static Timer* GetInstance();
	static void DeleteInstance();

	void AddTimer(ITimer* timer, DWORD gap);
	
	void Update(); //���� ���鼭 �ð� üũ
private:
	Timer();
	~Timer();

	void RemoveTimer(TimerData* data);

	static Timer* instance;
	vector<TimerData*> timerDatas;
};