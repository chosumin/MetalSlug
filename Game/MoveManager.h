#pragma once
#include "IManager.h"

class Character;
class MonsterManager;
class BackgroundManager;

class MoveManager : public IManager
{
public:
	static MoveManager* GetInstance();
	void DeleteInstance();

	void Update(Character* character, MonsterManager* monsters, BackgroundManager* back);
private:
	MoveManager();
	~MoveManager();

	void PlayerMove(Character* character);
	void DeleteTexture(MonsterManager* monsters, Character* character, BackgroundManager* back);
	void EventMove(MonsterManager* monsters, BackgroundManager* back, Character* character);
	static MoveManager* instance;

	float monsterRange;
};