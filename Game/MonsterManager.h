#pragma once

class Monster;
class Character;
class BackgroundManager;
class MonsterManager //���� �� ���� ����
{
public:
	static MonsterManager* GetInstance();
	void DeleteInstance();

	vector<Monster*> GetMonsters() const { return monsters; }
	void Update(Character* character, BackgroundManager* back);
	void Render();
private:
	MonsterManager();
	~MonsterManager();

	void Initialize();
	void MonsterDead();
	void CreateFirst();
	void CreateSecond();
	void CreateThird();
	void CreateForth();
	void CreateFifth();
	void CreateSixth();
	void CreateSeventh();
	void CreateEighth();
	void CreateNinth();

	static MonsterManager* instance;

	bool flag;

	vector<Monster*> monsters;
};