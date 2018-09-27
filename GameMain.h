#pragma once
#include "./System/Window.h"

class Camera; //�� ī�޶�� �������� ��� ����
class Character;
class BackgroundManager;
class CameraPlayerManager;
class MonsterManager;
class SmallCrab;
class Npc;
class GameMain
	:public Window
{
public:
	GameMain(HINSTANCE instance);
	~GameMain();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

private:
	Camera* camera;
	Character* character;
	BackgroundManager* back;
	vector<Npc*> npc;
};

