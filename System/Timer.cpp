#include "../stdafx.h"
#include "Timer.h"

Timer* Timer::instance = NULL;

Timer * Timer::GetInstance()
{
	if (instance == NULL)
		instance = new Timer();

	return instance;
}

void Timer::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void Timer::AddTimer(ITimer * timer, DWORD gap)
{
	TimerData* data = new TimerData();
	data->timer = timer;
	data->timeGap = gap;
	data->initTime = timeGetTime();

	timerDatas.push_back(data);
}

void Timer::RemoveTimer(TimerData * data)
{
	vector<TimerData*>::iterator iter = timerDatas.begin();

	for (; iter != timerDatas.end();)
	{
		if (*iter == data)
		{
			SAFE_DELETE(data);
			timerDatas.erase(iter);
			return;
		}
		else
			iter++;
	}
}

void Timer::Update()
{
	DWORD curTime = timeGetTime();
	for (size_t i = 0; i < timerDatas.size(); i++)
	{
		TimerData* data = timerDatas[i];
		if (curTime - data->initTime > data->timeGap)
		{
			data->timer->Event();
			RemoveTimer(data);
		}
	}
}

Timer::Timer()
{
}

Timer::~Timer()
{
	for (size_t i = 0; i < timerDatas.size(); i++)
	{
		SAFE_DELETE(timerDatas[i]);
	}
}
