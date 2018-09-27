#pragma once

enum IntroState
{
	FirstState, SelectCharacterState, GameStartState
};
class Character;
class IntroManager : ITimer
{
public:
	static IntroManager* GetInstance();
	void DeleteInstance();

	IntroState GetIntroState() const { return is; }

	void Update(Character** character);
	void Render();

	void Event();
private:
	IntroManager();
	~IntroManager();

	void AddImage();
	void DownM3(Point p);
	static IntroManager* instance;

	IntroState is;

	Size windowSize;
	TextureDrawer* mainScreen;
	TextureDrawer* insertCoin;
	TextureDrawer* blank;

	TextureDrawer* selectMain;
	TextureDrawer* p1_Icon;
	TextureDrawer* m3;
	TextureDrawer* tarmaBlack;
	TextureDrawer* tarmaLight;
	TextureDrawer* tarmaPick;
	TextureDrawer* fiolinaBlack;
	TextureDrawer* fiolinaLight;
	TextureDrawer* fiolinaPick;
	Animation* idleAnim;

	bool flash; //코인 삽입 문구 깜빡임
	Point p;
	float dst;
	bool select; //캐릭터 선택창 용
	bool choice;
	Point tarmaPoint;
	Point fiolinaPoint;
};