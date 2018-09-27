#include "../stdafx.h"
#include "Character.h"
#include "IManager.h"
#include "Tarma.h"
#include "Fiolina.h"
#include "Gun.h"
#include "../Camera/Camera.h"
#include "StateManager.h"

StateManager* StateManager::instance = NULL;

StateManager * StateManager::GetInstance()
{
	if (instance == NULL)
		instance = new StateManager();

	return instance;
}

void StateManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void StateManager::Update(Character** character, Camera* camera)
{
	this->camera = camera;
	this->character = character;
	switch (gs)
	{
		case CharacterOn:
		{
			if ((*this->character)->GetCharacterState() == DeadState)
				gs = CharacterDead;
		}
		break;
		case CharacterDead:
		{
			for (size_t i = 0; i < managers.size(); i++)
				managers[i]->SetIsOperate(false);

			SelectPhase();
		}
		break;
		case CharacterSelect:
		{
			for (size_t i = 0; i < managers.size(); i++)
				managers[i]->SetIsOperate(true);
			gs = CharacterOn;
		}
		break;
	}

	Time();

	
}

void StateManager::Render()
{
	if (character != NULL && camera != NULL)
	{
		Point location = camera->GetLocation();
		Direct2D::SetWorldLocation(location, -5);
		arms->Render();

		location.x += 100;
		Direct2D::SetWorldLocation(location, -5);
		bombs->Render();

		Size size;
		numbers[0]->GetSize(&size);
		Point timePoint = camera->GetLocation();
		timePoint.x += WIN_WIDTH * 0.5f - size.width;
		Direct2D::SetWorldLocation(timePoint, -5);
		numbers[i / 10]->Render();
		timePoint.x += size.width;
		Direct2D::SetWorldLocation(timePoint, -5);
		numbers1[i % 10]->Render();

		if (gs == CharacterDead)
		{
			Point point = camera->GetLocation();
			point.x += WIN_WIDTH - 150;
			point.y += 10;

			if (player == 0)
			{
				Direct2D::SetWorldLocation(point, -5);
				tarmaChoice->Render();
				point.x += 50;
				Direct2D::SetWorldLocation(point, -5);
				fiolinaSelect->Render();
			}
			else
			{
				Direct2D::SetWorldLocation(point, -5);
				tarmaSelect->Render();
				point.x += 50;
				Direct2D::SetWorldLocation(point, -5);
				fiolinaChoice->Render();
			}
		}
		TextInfo info;
		Text::GetInstance()->Get(0, &info);
		info.text = to_wstring((*character)->GetGun()->GetBulletCount());
		Text::GetInstance()->Set(0, &info);
		Text::GetInstance()->Get(1, &info);
		info.text = to_wstring((*character)->GetBombCount());
		Text::GetInstance()->Set(1, &info);
	}
}

void StateManager::Event()
{
	i -= 1;
	if (i < 0)
		i = 60;
	isTime = true;
}

StateManager::StateManager()
	: gs(CharacterOn), camera(NULL), character(NULL), i(60), isTime(true), player(0)
{
	AddImage();
}

StateManager::~StateManager()
{
	SAFE_DELETE(arms);
	SAFE_DELETE(bombs);
	SAFE_DELETE(tarmaSelect);
	SAFE_DELETE(tarmaChoice);
	SAFE_DELETE(fiolinaChoice);
	SAFE_DELETE(fiolinaSelect);
}

void StateManager::AddImage()
{
	ImageCuttingManager::GetInstance()->CreateTexture
	(
		&arms, L"ArmsIcon", Rect(4, 272, 31, 8), Size(2, 2), -5
	);

	ImageCuttingManager::GetInstance()->CreateTexture
	(
		&bombs, L"BombsIcon", Rect(125, 272, 31, 8), Size(2, 2), -5
	);

	ImageCuttingManager::GetInstance()->CreateTexture
	(
		&tarmaSelect, L"Tarma_selectIcon", Rect(31, 472, 25, 26), Size(2, 2), -5
	);

	ImageCuttingManager::GetInstance()->CreateTexture
	(
		&tarmaChoice, L"Tarma_choiceIcon", Rect(3, 472, 25, 26), Size(2, 2), -5
	);

	ImageCuttingManager::GetInstance()->CreateTexture
	(
		&fiolinaSelect, L"Fiolina_selectIcon", Rect(31, 501, 25, 26), Size(2, 2), -5
	);

	ImageCuttingManager::GetInstance()->CreateTexture
	(
		&fiolinaChoice, L"Fiolina_choiceIcon", Rect(3, 501, 25, 26), Size(2, 2), -5
	);

	for (int i = 0; i < 10; i++)
	{
		TextureDrawer* texture = new TextureDrawer(Size(16 * 3, 16 * 3), to_wstring(i), -5);
		numbers.push_back(texture);
		numbers1.push_back(texture);
	}
	Text::GetInstance()->Add(L"", &Rect(75, 0, 100, 20), 0xffffffff);
	Text::GetInstance()->Add(L"", &Rect(160, 0, 100, 20), 0xffffffff);
}

void StateManager::Time()
{
	if (isTime == true)
	{
		TIMER()->AddTimer(this, 2000);
		isTime = false;
	}
}

void StateManager::SelectPhase()
{	
	if (KEYBOARD()->KeyDown(VK_RIGHT) || KEYBOARD()->KeyDown(VK_LEFT))
		player = (++player) % 2;

	if (KEYBOARD()->KeyDown(VK_RETURN))
	{
		Point point = (*character)->GetLocation();
		SAFE_DELETE(*character);
		if (player == 0)
			*character = new Tarma(Rect(point.x, 120, 0, 80));
		else
			*character = new Fiolina(Rect(point.x, 120, 0, 80));

		gs = CharacterSelect;
		(*character)->SetCharacterImortal(ImortalOn);
		(*character)->SetImortalTime(timeGetTime());
	}
	
}

