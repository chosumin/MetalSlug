#include "../stdafx.h"
#include "SmallCrab.h"
#include "SmallCrabRange.h"
#include "Fly.h"
#include "Truck.h"
#include "Character.h"
#include "Tile.h"
#include "BackgroundManager.h"
#include "MonsterManager.h"

MonsterManager* MonsterManager::instance = NULL;

MonsterManager* MonsterManager::GetInstance()
{
	if (instance == NULL)
		instance = new MonsterManager();

	return instance;
}

void MonsterManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void MonsterManager::Update(Character* character, BackgroundManager* back)
{
	float x = character->GetLocation().x;
	if (x > 200)
		CreateFirst();

	if (x > 900)
		CreateSecond();

	if (x > 1100)
		CreateThird();

	if (x > 1600)
		CreateForth();

	if (x > 2590)
		CreateFifth();

	if (x > 3300)
		CreateSixth();

	if (x > 4000)
		CreateSeventh();

	if (x > 4800)
		CreateEighth();

	if (x > 5000)
	{
		if (flag == false)
		{
			Tile* tile = back->GetTile(L"TruckFloor");
			if (tile != NULL && tile->GetLocation().x <= 6400)
			{
				flag = true;
				CreateNinth();
			}
		}
	}
	Initialize();
	MonsterDead();
}

void MonsterManager::Render()
{
	for (size_t i = 0; i < monsters.size(); i++)
		monsters[i]->Render();
}


MonsterManager::MonsterManager()
{
	flag = false;
}

MonsterManager::~MonsterManager()
{
	for (size_t i = 0; i < monsters.size(); i++)
		SAFE_DELETE(monsters[i]);
}

void MonsterManager::Initialize()
{
	for (size_t i = 0; i < monsters.size(); i++)
	{
		monsters[i]->GetIMonster()->Initialize();
	}
}

void MonsterManager::MonsterDead()
{
	vector<Monster*>::iterator iter = monsters.begin();

	for (; iter != monsters.end();)
	{
		if ((*iter)->GetMonsterState() == deadState)
		{
			if ((*iter)->GetAnimation()->GetCurCount() >= (UINT)((*iter)->GetAnimation()->GetClipCount() - 1))
			{
				
				SAFE_DELETE((*iter));
				iter = monsters.erase(iter);
			}
			else
				iter++;
		}
		else
			iter++;
	}
}

void MonsterManager::CreateFirst()
{
	static bool isStart = false;

	if (isStart == false)
	{
		SmallCrab* crab1 = new SmallCrab(Point(900, 400), 0);
		SmallCrab* crab2 = new SmallCrab(Point(1100, 400), 0);

		monsters.push_back(crab1);
		monsters.push_back(crab2);

		isStart = true;
	}
}

void MonsterManager::CreateSecond()
{
	static bool isStart = false;

	if (isStart == false)
	{
		SmallCrab* crab1 = new SmallCrab(Point(1500, 300), 1);
		SmallCrab* crab2 = new SmallCrab(Point(1600, 300), 1);
		monsters.push_back(crab1);
		monsters.push_back(crab2);
		isStart = true;
	}
}

void MonsterManager::CreateThird()
{
	static int i = 0;
	static DWORD prevTime = timeGetTime();

	if (i == 0)
	{
		SmallCrabRange* crab1 = new SmallCrabRange(Point(810 * 2, 300), 0);
		monsters.push_back(crab1);
		i++;
	}
	else if (i < 4)
	{
		DWORD curTime = timeGetTime();

		if (curTime - prevTime > 2000)
		{
			SmallCrabRange* crab1 = new SmallCrabRange(Point(810 * 2, 300), 0);
			monsters.push_back(crab1);
			i++;
			prevTime = timeGetTime();
		}
	}
}

void MonsterManager::CreateForth()
{
	static bool isStart = false;

	if (isStart == false)
	{
		SmallCrab* crab1 = new SmallCrab(Point(2300, 500), 1);
		SmallCrabRange* crab2 = new SmallCrabRange(Point(2400, 500), 1);
		monsters.push_back(crab1);
		monsters.push_back(crab2);
		isStart = true;
	}
}

void MonsterManager::CreateFifth()
{
	static int j = 0;
	static DWORD prevTime = timeGetTime();

	if (j == 0)
	{
		SmallCrabRange* crab1 = new SmallCrabRange(Point(3100, 480), 1);
		monsters.push_back(crab1);
		SmallCrab* crab2 = new SmallCrab(Point(3150, 200), 2);
		monsters.push_back(crab2);
		j++;
	}
	else if (j < 3)
	{
		DWORD curTime = timeGetTime();

		if (curTime - prevTime > 2500)
		{
			SmallCrabRange* crab1 = new SmallCrabRange(Point(3100, 480), 1);
			monsters.push_back(crab1);
			SmallCrab* crab2 = new SmallCrab(Point(3150, 200), 2);
			monsters.push_back(crab2);
			j++;
			prevTime = timeGetTime();
		}
	}
}

void MonsterManager::CreateSixth() //3300
{
	static bool isStart = false;

	if (isStart == false)
	{
		SmallCrabRange* crab1 = new SmallCrabRange(Point(3900, 330), 0);
		monsters.push_back(crab1);
		SmallCrabRange* crab2 = new SmallCrabRange(Point(4500, 380), 0);
		monsters.push_back(crab2);
		
		Fly* fly1 = new Fly(Point(3200, 0), 0);
		monsters.push_back(fly1);
		isStart = true;
	}
}

void MonsterManager::CreateSeventh()
{
	static bool isStart = false;

	if (isStart == false)
	{
		Fly* fly1 = new Fly(Point(3900, 100), 0);
		monsters.push_back(fly1);
		isStart = true;
	}
}

void MonsterManager::CreateEighth() //4800
{
	static int i = 0;
	static DWORD prevTime = timeGetTime();

	if (i == 0)
	{
		Fly* fly1 = new Fly(Point(4700, 50), 0);
		monsters.push_back(fly1);
		i++;
	}
	else if (i < 2)
	{
		DWORD curTime = timeGetTime();

		if (curTime - prevTime > 2500)
		{
			Fly* fly1 = new Fly(Point(5500, 50), 1);
			monsters.push_back(fly1);
			fly1 = new Fly(Point(4700, 50), 0);
			monsters.push_back(fly1);
			i++;
			prevTime = timeGetTime();
		}
	}
}

void MonsterManager::CreateNinth() //카메라 위치 5740
{
	static bool isStart = false;

	if (isStart == false)
	{
		Truck* truck = new Truck(Point(6450, 300));
		monsters.push_back(truck);
		isStart = true;
	}
}
