#include "../stdafx.h"
#include "Character.h"
#include "Gun.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "Bullet.h"
#include "Bomb.h"
#include "AttackManager.h"

AttackManager* AttackManager::instance = NULL;

AttackManager* AttackManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new AttackManager();
		Text::GetInstance()->Add(L"", &Rect(0, 0, 100, 20), 0xffffffff);
	}
	return instance;
}

void AttackManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void AttackManager::Update(Character* character, MonsterManager* monsters)
{
	if (isOperate == true)
	{
		if(character->GetIsCaptured() == false)
			CharacterOnAttack(character, monsters);
		MonsterOnAttack(character, monsters);
	}
	MonsterBulletDelete(monsters);
	MonsterBulletUpdate(monsters);
}

AttackManager::AttackManager()
{
}

AttackManager::~AttackManager()
{
}

void AttackManager::CharacterOnAttack(Character* character, MonsterManager* monsters)
{
	CharacterAttack ca = character->GetAttackState();
	CharacterDirection cd = character->GetDireciton();
	Point point = character->GetIntersectRect().location;
	Animation* anim = character->GetUpperAnimation();

	Point trigger = character->GetUpperAnimation()->GetGunPoint();
	Point upper = character->GetUpperLocation();
	if (cd == LeftCharacterState)
		trigger.x = character->GetUpperAnimation()->GetSize().width - trigger.x;
	trigger.x = trigger.x + upper.x;
	trigger.y = trigger.y + upper.y;
	character->GetGun()->SetLocation(trigger);

	if(wcscmp(character->GetGun()->GetName().c_str() ,L"RocketLauncher") != 0)
		character->SetGunAngle();
	else
	{
		vector<Monster*> monster = monsters->GetMonsters();
		float radian = 0;
		if (monster.size() != 0)
		{
			int target = Math::RandomRange(0, monster.size() - 1);
			Point point1;
			monster[target]->GetIntersectRect().GetHalfLocation(&point1);
			radian = atan2(point1.y - point.y, point1.x - point.x);
		}
		character->GetGun()->SetAngle(Math::RadianToDegree(radian));
	}

	trigger = character->GetUpperAnimation()->GetGunPoint();
	upper = character->GetUpperLocation();
	if (cd == LeftCharacterState)
		trigger.x = character->GetUpperAnimation()->GetSize().width - trigger.x;
	trigger.x = trigger.x + upper.x;
	trigger.y = trigger.y + upper.y;
	if (KEYBOARD()->KeyDown('S'))
	{
		if (ca != OnAttack)
		{
			character->SetAttack(OnAttack);
			character->GetGun()->SetLocation(trigger);
			character->GetGun()->Attack();
		}
	}
	else if (KEYBOARD()->KeyDown('W'))
	{
		if (character->GetBombCount() > 0)
		{
			character->SetIsBomb(true);
			character->SetBombCount();
			if (cd == RightCharacterState)
				character->PushBackBomb(new Bomb(trigger, 45, true));
			else
				character->PushBackBomb(new Bomb(trigger, 45, false));
		}
	}

	if (ca == OnAttack)
	{
		if (anim->GetCurCount() >= (UINT)anim->GetClipCount() - 1)
		{
			anim->SetCurCount(0);
			character->SetAttack(OffAttack);
		}
	}
	if (character->GetIsBomb() == true) //bomb애니메이션 종료
	{
		if (anim->GetCurCount() >= (UINT)anim->GetClipCount() - 1)
		{
			character->SetIsBomb(false);
			anim->SetCurCount(0);
		}
	}
}

void AttackManager::MonsterOnAttack(Character* character, MonsterManager* monsters)
{ 
	//TODO attackstate이고 마지막 애니메이션 호출시(몬스터마다 다름)
	//플레이어 사망 구현하기
	vector<Monster*> monster = monsters->GetMonsters();

	for (size_t i = 0; i < monster.size(); i++)
	{
		if (monster[i]->GetIsAttack() == false)
		{
			DWORD curTime = timeGetTime();
			DWORD prevTime = monster[i]->GetPrevTime();
			if (curTime - prevTime > 3000)
			{
				monster[i]->SetIsAttack(true);
				monster[i]->SetPrevTime(curTime);
			}
		}
	}
}

void AttackManager::MonsterBulletUpdate(MonsterManager * monsters)
{
	vector<Monster*> monster = monsters->GetMonsters();

	for (size_t i = 0; i < monster.size(); i++)
	{
		vector<Bullet*> bullets = monster[i]->GetBullet();
		for (size_t j = 0; j < bullets.size(); j++)
		{
			bullets[j]->Update();
		}
	}
}

void AttackManager::MonsterBulletDelete(MonsterManager * monsters)
{
	vector<Monster*> monster = monsters->GetMonsters();

	for (size_t i = 0; i < monster.size(); i++)
	{
		monster[i]->DeleteBullet();
	}
}
