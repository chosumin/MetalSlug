#include "../stdafx.h"
#include "Character.h"
#include "../Camera/Camera.h"
#include "BackgroundManager.h"
#include "Tile.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "Gun.h"
#include "Bullet.h"
#include "CameraPlayerManager.h"

CameraPlayerManager* CameraPlayerManager::instance = NULL;

CameraPlayerManager* CameraPlayerManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new CameraPlayerManager();
		Text::GetInstance()->Add(L"", &Rect(0, 0, 100, 20), 0xffffffff);
	}
	return instance;
}

void CameraPlayerManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void CameraPlayerManager::Update(Character* character, Camera* camera, BackgroundManager* back, MonsterManager* monsters)
{
	BulletDelete(character, camera, monsters);
	Point cameraLocation = camera->GetLocation();
	Point characteLocation = character->GetLocation();
	if (characteLocation.x < cameraLocation.x)
		character->SetLocation(cameraLocation.x, characteLocation.y);

	if (characteLocation.x > cameraLocation.x + WIN_WIDTH)
		character->SetLocation(cameraLocation.x + WIN_WIDTH, characteLocation.y);
	if (isHold == true) return;

	if (isOperate == true)
	{
		DefaultMove(character, camera, back);
		UpMove(character, camera, back);
		DownMove(character, camera, back);
		BossMove(character, camera, back);
		back->DeleteTiles(camera);
	}
}

void CameraPlayerManager::DefaultMove(Character* character, Camera* camera, BackgroundManager* back)
{
	Point cameraLocation = camera->GetLocation();
	Point characteLocation = character->GetLocation();
	TextInfo info;
	Text::GetInstance()->Get(1, &info);

	if (character->GetLocation().x > 5800) return;
	float speed = 0;
	if (characteLocation.x - cameraLocation.x > 250)
		speed = character->GetSpeed() + 1;
	if (characteLocation.x - cameraLocation.x > 190)
		speed = character->GetSpeed() + 0.5f;
	else if (characteLocation.x - cameraLocation.x > 130)
		speed = character->GetSpeed() - 1;
	camera->SetLocation(cameraLocation.x + speed, cameraLocation.y);

	Tile* tile = back->GetTile(L"Background");
	tile->SetLocation(Point(tile->GetLocation().x + speed * 0.4f, tile->GetLocation().y));

	wstring coord = L"";
	coord += to_wstring((int)characteLocation.x);
	coord += L", ";
	coord += to_wstring((int)characteLocation.y);
	info.text = coord;
	Text::GetInstance()->Set(1, &info);
}

void CameraPlayerManager::UpMove(Character * character, Camera * camera, BackgroundManager * back)
{
	Point cameraLocation = camera->GetLocation();
	Point characteLocation = character->GetLocation();

	if (characteLocation.x < 2700) return;
	if (cameraLocation.y < 50) return;

	float speed = 0;
	if (cameraLocation.y + WIN_WIDTH - characteLocation.y > 600)
		speed = character->GetSpeed() + 1;
	else if (cameraLocation.y + WIN_WIDTH - characteLocation.y > 500)
		speed = character->GetSpeed() + 0.5f;
	else if (cameraLocation.y + WIN_WIDTH - characteLocation.y > 350)
		speed = character->GetSpeed() - 1;

	camera->SetLocation(cameraLocation.x, cameraLocation.y - speed);
}

void CameraPlayerManager::DownMove(Character * character, Camera * camera, BackgroundManager * back)
{
	Point cameraLocation = camera->GetLocation();
	Point characteLocation = character->GetLocation();

	if (characteLocation.x < 3500) return;

	float speed = 0;
	if(characteLocation.y + 50 > cameraLocation.y + WIN_HEIGHT)
		speed = character->GetSpeed() - 1;

	camera->SetLocation(cameraLocation.x, cameraLocation.y + speed);
}

void CameraPlayerManager::BossMove(Character * character, Camera * camera, BackgroundManager * back)
{
	Point cameraLocation = camera->GetLocation();
	Point characteLocation = character->GetLocation();
	if (characteLocation.x < 5790) return;
	static int i = 0;
	float speed = character->GetSpeed();
	
	if (i < 50)
	{
		i++;
		camera->SetLocation(cameraLocation.x + speed, cameraLocation.y);
	}
	else
		isHold = true;
}

void CameraPlayerManager::BulletDelete(Character * character, Camera * camera, MonsterManager * monsters)
{
	Point cameraLocation = camera->GetLocation();
	for (size_t i = 0; i < character->GetGun()->GetBullet().size(); i++)
	{
		Bullet* bullet = character->GetGun()->GetBullet()[i];
		if (bullet->GetRect().location.x - 40 < cameraLocation.x || bullet->GetRect().location.x > cameraLocation.x + WIN_WIDTH)
			bullet->SetIsIntersect(true);
	}

	for (size_t i = 0; i < monsters->GetMonsters().size(); i++)
	{
		Monster* monster = monsters->GetMonsters()[i];
		for (size_t j = 0; j < monster->GetBullet().size(); j++)
		{
			Bullet* bullet = monster->GetBullet()[j];
			if (bullet->GetRect().location.x - 40 < cameraLocation.x || bullet->GetRect().location.x > cameraLocation.x + WIN_WIDTH)
				bullet->SetIsIntersect(true);
		}
	}
}

CameraPlayerManager::CameraPlayerManager()
{}

CameraPlayerManager::~CameraPlayerManager()
{}