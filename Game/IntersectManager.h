#pragma once
#include "IManager.h"
class BackgroundManager;
class Character;
class MonsterManager;
class Npc;
class IntersectManager : public IManager
{
public:
	static IntersectManager* GetInstance();
	void DeleteInstance();

	void Update(Character* character, MonsterManager* monsters, BackgroundManager* background, vector<Npc*> npc);
private:
	IntersectManager();
	~IntersectManager();

	void CheckAttackRange(Character* character, MonsterManager* monsters);
	void CharacterMapIntersect(Character* character, BackgroundManager* back);
	void MonsterMapIntersect(MonsterManager* monsters, BackgroundManager* back);
	void BulletMonsterIntersect(Character* character, MonsterManager* monsters);
	void BulletCharacterIntersect(Character* character, MonsterManager* monsters);
	void BulletTileIntersect(Character* character, BackgroundManager* back);
	void BombIntersect(Character* character, BackgroundManager* back, MonsterManager* monsters);
	void CharacterNpcIntersect(Character* character, vector<Npc*> npc);
	void BackgroundEvent(Character* character, BackgroundManager* back);

	static IntersectManager* instance;
};