#include "../stdafx.h"
#include "Character.h"
#include "Monster.h"
#include "MonsterManager.h"
#include "BackgroundManager.h"
#include "Tile.h"
#include "CameraPlayerManager.h"
#include "MoveManager.h"

MoveManager* MoveManager::instance = NULL;

MoveManager* MoveManager::GetInstance()
{
	if (instance == NULL)
		instance = new MoveManager();

	return instance;
}

void MoveManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void MoveManager::Update(Character* character, MonsterManager* monsters, BackgroundManager* back)
{
	if (isOperate == true)
	{
		if(character->GetIsCaptured() == false)
			PlayerMove(character);
	}
	DeleteTexture(monsters, character, back);
	EventMove(monsters, back, character);
}
	
MoveManager::MoveManager()
{
	monsterRange = 400;
}
	
MoveManager::~MoveManager()
{

}

void MoveManager::PlayerMove(Character* character)
{
	CharacterState cs = character->GetCharacterState();
	CharacterDirection cd = character->GetDireciton();
	Rect rect = character->GetRect();
	Rect intRect = character->GetIntersectRect();
	float speed = character->GetSpeed();

	if (KEYBOARD()->KeyPress(VK_UP))
	{
		switch (cs)
		{
			case IdleState: cs = UpHoldState;
				break;
			case MoveState: cs = UpHoldMoveState;
				break;
			case JumpState: cs = UpHoldJumpState;
				break;
		}
	}

	if (KEYBOARD()->KeyDown('A')) //Á¡ÇÁ
	{
		bool jump = character->GetIsJump();
		if (jump == false)
		{
			if (cs != SitState)
			{
				character->SetIsJump(true);
				character->SetJumpPoint(character->GetLocation());

				if (cs == IdleState || cs == MoveState)
					cs = JumpState;
				else if (cs == UpHoldState)
					cs = UpHoldJumpState;
			}
		}
	}

	if (KEYBOARD()->KeyPress(VK_RIGHT)) //¿À¸¥ÂÊ
	{
		if (cs != SitState)
		{
			rect.location.x += speed;
			cd = RightCharacterState;

			if (cs == IdleState)
				cs = MoveState;
			else if (cs == UpHoldState)
				cs = UpHoldMoveState;
		}
	}
	else if (KEYBOARD()->KeyPress(VK_LEFT)) //¿ÞÂÊ
	{
		if (cs != SitState)
		{
			rect.location.x -= speed;
			cd = LeftCharacterState;

			if (cs == IdleState)
				cs = MoveState;
			else if (cs == UpHoldState)
				cs = UpHoldMoveState;
		}
	}

	if (KEYBOARD()->KeyPress(VK_DOWN)) //¾Æ·¡ Å°
	{
		if (cs == IdleState || cs == MoveState)
			cs = SitState;
		else if (cs == JumpState || cs == UpHoldJumpState || cs == DownState)
			cs = DownState;
	}

	if (KEYBOARD()->KeyUp(VK_LEFT) || KEYBOARD()->KeyUp(VK_RIGHT)) //ÁÂ¿ì ¹æÇâÅ° ¶À
	{
		switch (cs)
		{
			case MoveState:			cs = IdleState; break;
			case UpHoldMoveState:	cs = UpHoldState; break;
		}
	}

	if (KEYBOARD()->KeyUp(VK_UP))
	{
		switch (cs)
		{
			case UpHoldState: cs = IdleState; break;
			case UpHoldMoveState: cs = MoveState; break;
			case UpHoldJumpState: cs = JumpState; break;
		}
	}

	if (KEYBOARD()->KeyUp(VK_DOWN))
	{
		cs = IdleState;
	}

	character->SetState(cs);
	character->SetDirection(cd);
	character->SetRect(rect);
	character->SetIntersectRect(intRect);
}

void MoveManager::DeleteTexture(MonsterManager* monsters, Character* character, BackgroundManager* back)
{
	if (character->GetLocation().x > 2600 && monsters->GetMonsters().size() <= 0)
	{
		static bool isStart = false;

		if (isStart == false)
		{
			Tile* tile = back->GetTile(L"Beach4_BigShip");
			float right = tile->GetIntersectRect().GetRight();
			float top = tile->GetIntersectRect().GetTop();
			Rect r = Rect(Point(right - 300, top + 100), tile->GetRect().size);
			DeadClass::GetInstance()->Push
			(
				new DeadEffect1
				(
				r, Size(4, 4), L"ExplosionBig", 5, Size(114, 118)
				)
			);
			DeadClass::GetInstance()->Push
			(
				new DeadEffect2
				(
				r, Size(7, 7), L"Dust", 9, Size(46, 39)
			)
			);
			back->DeleteTiles(L"Beach4_BigShip");
			back->DeleteTiles(L"Beach4_BigShipGate");
			back->DeleteTiles(L"Beach4_BigShipSurface");

			isStart = true;

			CameraPlayerManager::GetInstance()->SetIsHold(false);
		}
	}
}

void MoveManager::EventMove(MonsterManager * monsters, BackgroundManager * back, Character* character)
{
	vector<Monster*> monster = monsters->GetMonsters();
	for (size_t i = 0; i < monster.size(); i++)
	{
		if (monster[i]->GetIsStopTraffic() == true) //º¸½º µµ´Þ½Ã ¸ØÃã
			back->SetIsStopTraffic(true);
	}

	if (character->GetIntersectRect().location.x >= 2600)
	{
		Tile* tile = back->GetTile(L"Beach4_BigShipGate");
		if(tile != NULL)
			tile->SetIsGen(true);
	}

	if (character->GetIntersectRect().location.x >= 2650)
	{
		static bool flag = false;

		if (flag == false)
		{
			CameraPlayerManager::GetInstance()->SetIsHold(true);
			flag = true;
		}
	}
}
