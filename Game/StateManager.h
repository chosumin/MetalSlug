#pragma once

enum GameState
{
	CharacterOn, CharacterDead, CharacterSelect
};

class Character;
class Camera;
class IManager;
class StateManager : public ITimer
{
public:
	static StateManager* GetInstance();
	void DeleteInstance();

	GameState GetGameState() const { return gs; }
	void SetGameState(GameState a) { gs = a; }

	vector<IManager*> GetVector() const { return managers; }
	void PushBack(IManager* manager) { managers.push_back(manager); }
	void Update(Character** character, Camera* camera);
	void Render();

	void Event();
private:
	StateManager();
	~StateManager();

	void AddImage();
	void Time();
	void SelectPhase();
	static StateManager* instance;
	int i; //�ð� ��� �뵵
	int player; //������ ĳ����
	bool isTime; //Ÿ�̸ӿ�
	GameState gs;
	vector<IManager*> managers;
	Camera* camera;
	Character** character;
	TextureDrawer* arms;
	TextureDrawer* bombs;

	TextureDrawer* tarmaSelect;
	TextureDrawer* fiolinaSelect;

	TextureDrawer* tarmaChoice;
	TextureDrawer* fiolinaChoice;

	vector<TextureDrawer*> numbers;
	vector<TextureDrawer*> numbers1;
};