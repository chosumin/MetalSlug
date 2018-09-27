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
	
	void Update(); //루프 돌면서 시간 체크
private:
	Timer();
	~Timer();

	void RemoveTimer(TimerData* data);

	static Timer* instance;
	vector<TimerData*> timerDatas;
};