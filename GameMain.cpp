#include "stdafx.h"
#include "./Camera/Camera.h"
#include "./Camera/FreeCamera.h"
#include "./Game/Tarma.h"
#include "./Game/Fiolina.h"
#include "./Game/BackgroundManager.h"
#include "./Game/Tile.h"
#include "./Game/CameraPlayerManager.h"
#include "./Game/TextureAddManager.h"
#include "./Game/MonsterManager.h"
#include "./Game/SmallCrab.h"
#include "./Game/Npc.h"
#include "./Game/MoveManager.h"
#include "./Game/IntersectManager.h"
#include "./Game/AttackManager.h"
#include "./Game/StateManager.h"
#include "./Game/Gun.h"
#include "./Game/IntroManager.h"
#include "GameMain.h"

GameMain::GameMain(HINSTANCE instance)
	:Window(instance)
{
	TextureManager::GetInstance();
}


GameMain::~GameMain()
{
	TextureManager::DeleteInstance();
}

void GameMain::Initialize()
{
	back = new BackgroundManager();
	TextureAddManager::GetInstance()->Initialize(); //모든 텍스쳐 저장
	camera = new Camera(Point(2 * 2, 170));
	//camera = new Camera(Point(2500, 170));
	//camera = new FreeCamera(Point(100, 150));
	character = new Fiolina(Rect(100, 220, 40, 80), 3);
	npc.push_back(new Npc(Point(2000, 370), L"HeavyWeapon"));
	npc.push_back(new Npc(Point(3650, 250), L"RocketLauncher"));
	
}

void GameMain::Destroy()
{
	SAFE_DELETE(back);
	SAFE_DELETE(character);
	FadeClass::GetInstance()->DeleteInstance();
	MonsterManager::GetInstance()->DeleteInstance();
	for (size_t i = 0; i < npc.size(); i++)
		SAFE_DELETE(npc[i]);
	MoveManager::GetInstance()->DeleteInstance();
	IntersectManager::GetInstance()->DeleteInstance();
	AttackManager::GetInstance()->DeleteInstance();
	DeadClass::DeleteInstance();
	StateManager::GetInstance()->DeleteInstance();
	SAFE_DELETE(camera);
	TextureManager::DeleteInstance();
	ImageCuttingManager::GetInstance()->DeleteInstance();
}

void GameMain::Update()
{
	if (IntroManager::GetInstance()->GetIntroState() == GameStartState)
	{
		if (StateManager::GetInstance()->GetVector().size() == 0)
		{
			StateManager::GetInstance()->PushBack(AttackManager::GetInstance());
			StateManager::GetInstance()->PushBack(IntersectManager::GetInstance());
			StateManager::GetInstance()->PushBack(MoveManager::GetInstance());
			StateManager::GetInstance()->PushBack(CameraPlayerManager::GetInstance());
		}
		AttackManager::GetInstance()->Update(character, MonsterManager::GetInstance());
		back->Update();
		IntersectManager::GetInstance()->Update(character, MonsterManager::GetInstance(), back, npc);
		MoveManager::GetInstance()->Update(character, MonsterManager::GetInstance(), back);
		for (size_t i = 0; i < npc.size(); i++)
			npc[i]->Update();
		MonsterManager::GetInstance()->Update(character, back);
		CameraPlayerManager::GetInstance()->Update(character, camera, back, MonsterManager::GetInstance());
		character->Update();
		DeadClass::GetInstance()->Update();
		StateManager::GetInstance()->Update(&character, camera);
	}
	FadeClass::GetInstance()->Update();
	IntroManager::GetInstance()->Update(&character);
	camera->Update();
}

void GameMain::Render()
{
	IntroManager::GetInstance()->Render();
	if (IntroManager::GetInstance()->GetIntroState() == GameStartState)
	{
		back->Render();
		MonsterManager::GetInstance()->Render();
		character->Render();
		for (size_t i = 0; i < npc.size(); i++)
			npc[i]->Render();
		for (size_t i = 0; i < back->GetTiles().size(); i++)
		{
			if (back->GetTiles()[i]->GetName() == L"TargetGate2" || back->GetTiles()[i]->GetName() == L"Beach4_BigShipSurface")
				back->GetTiles()[i]->Render();
		}
		DeadClass::GetInstance()->Render();
		StateManager::GetInstance()->Render();
	}
	FadeClass::GetInstance()->Render();
}