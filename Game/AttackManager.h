#pragma once
#include "IManager.h"

class Character;
class MonsterManager;
class AttackManager : public IManager//플레이어의 위치에 따라 움직임이 결정됨
{
public:
	static AttackManager* GetInstance();
	void DeleteInstance();

	void Update(Character* character, MonsterManager* monsters);
private:
	AttackManager();
	~AttackManager();

	void CharacterOnAttack(Character* character, MonsterManager* monsters);
	void MonsterOnAttack(Character* character, MonsterManager* monsters);
	void MonsterBulletUpdate(MonsterManager* monsters);
	void MonsterBulletDelete(MonsterManager* monsters);
	static AttackManager* instance;
};