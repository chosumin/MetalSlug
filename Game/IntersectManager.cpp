#include "../stdafx.h"
#include "Monster.h"
#include "MonsterManager.h"
#include "Character.h"
#include "Bullet.h"
#include "Bomb.h"
#include "Gun.h"
#include "Npc.h"
#include "BackgroundManager.h"
#include "Tile.h"
#include "IntersectManager.h"
//TODO 몬스터 총알 충돌 처리
IntersectManager* IntersectManager::instance = NULL;

IntersectManager* IntersectManager::GetInstance()
{
	if (instance == NULL)
		instance = new IntersectManager();

	return instance;
}

void IntersectManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void IntersectManager::Update(Character* character, MonsterManager* monsters, BackgroundManager* background, vector<Npc*> npc)
{
	CheckAttackRange(character, monsters);
	if (isOperate == true)
	{
		BulletCharacterIntersect(character, monsters);
		CharacterNpcIntersect(character, npc);
	}
	CharacterMapIntersect(character, background);
	MonsterMapIntersect(monsters, background);
	BulletMonsterIntersect(character, monsters);
	BulletTileIntersect(character, background);
	BombIntersect(character, background, monsters);
	BackgroundEvent(character, background);
}

IntersectManager::IntersectManager()
{
}

IntersectManager::~IntersectManager()
{

}

void IntersectManager::CheckAttackRange(Character* character, MonsterManager* monsters)
{
	if (character->GetCharacterImortal() != ImortalOn)
	{
		vector<Monster*> monster = monsters->GetMonsters();
		for (size_t i = 0; i < monster.size(); i++)
		{
			if (monster[i]->GetMonsterState() != initialState && monster[i]->GetMonsterState() != deadState)
			{
				Rect rect1 = character->GetIntersectRect();
				Rect rect2 = monster[i]->GetAttackCheckRect();

				if (Rect::Intersect(rect1, rect2) && monster[i]->GetIsAttack() == true)
				{
					//딜레이 후 공격 가능 일때
					monster[i]->GetIMonster()->Attack(character);
				}
				else
					monster[i]->GetIMonster()->Idle();
			}
		}
	}
}

void IntersectManager::CharacterMapIntersect(Character * character, BackgroundManager * back)
{
	if (character->GetIsCaptured() != true)
	{
		bool isIntersect = false;
		vector<Tile*> tiles = back->GetTiles();
		Point location = Point(character->GetLocation().x + 30, character->GetLocation().y);
		for (size_t i = 0; i < tiles.size(); i++)
		{
			if (location.x >= tiles[i]->GetLocation().x
				&& location.x < tiles[i]->GetRight()) //범위 안에 들어올때 충돌 검사
			{
				vector<RectDrawer*> rects = tiles[i]->GetRectDrawer();
				for (size_t j = 0; j < rects.size(); j++)
				{
					Rect rect1 = character->GetIntersectRect();
					if (character->GetDireciton() == RightCharacterState)
						rect1.location.x = location.x;
					else
						rect1.location.x = location.x - 20;
					Rect rect2 = rects[j]->GetRect();
					if (Rect::Intersect(rect1, rect2))
					{
						location.y = rect2.GetTop();
						character->SetLocation
						(
							Point(character->GetLocation().x,
							location.y));
						isIntersect = true;
						if (character->GetCharacterState() == JumpState || character->GetCharacterState() == UpHoldJumpState)
							character->SetState(IdleState);
						//break;
					}
				}
			}
		}

		if (isIntersect == false)
		{
			CharacterState cs = character->GetCharacterState();
			character->SetLocation
			(
				Point(character->GetLocation().x, location.y + 7)
			);
			if (cs == UpHoldState)
				character->SetState(UpHoldJumpState);
			else if (cs == DownState)
				character->SetState(DownState);
			else if (cs == DeadState)
			{
			}//donothing
			else
				character->SetState(JumpState);
		}
	}
}

void IntersectManager::MonsterMapIntersect(MonsterManager * monsters, BackgroundManager * back)
{
	vector<Tile*> tiles = back->GetTiles();
	vector<Monster*> monster = monsters->GetMonsters();
	for (size_t i = 0; i < tiles.size(); i++) //타일 - i
	{
		for (size_t j = 0; j < monster.size(); j++) //몬스터 - j
		{
			if (monster[j]->GetIsFly() == true) continue;
			Point location = monster[j]->GetLocation();
			location.x += 30;
			if (location.x >= tiles[i]->GetLocation().x
				&& location.x < tiles[i]->GetRight())
			{
				Rect rect1 = monster[j]->GetRect();
				if (tiles[i]->IsIntersect(monster[j]) == false)
				{
					monster[j]->SetLocation
					(
						monster[j]->GetLocation().x, location.y + 7
					);
					monster[j]->SetMonsterState(jumpState);
				}
			}
		}
	}
}

void IntersectManager::BulletMonsterIntersect(Character* character, MonsterManager* monsters)
{
	vector<Bullet*> bullets = character->GetGun()->GetBullet();
	vector<Monster*> monster = monsters->GetMonsters();

	if (character->GetIsCaptured() == true) return;
	for (size_t i = 0; i < bullets.size(); i++)
	{
		Bullet* bullet = bullets[i];
		for (size_t j = 0; j < monster.size(); j++)
		{
			Monster* mob = monster[j];
			if (mob->GetMonsterState() != deadState)
			{
				if (Rect::Intersect(bullet->GetRect(), mob->GetIntersectRect()))
				{
					if (bullet->GetIsIntersect() == false)
					{
						bullet->SetIsIntersect(true);
						mob->SetHp(bullet->GetAttackPower());
						
					}
				}
			}

			if (mob->GetHp() <= 0)
				mob->GetIMonster()->Dead();
		}
	}
}

void IntersectManager::BulletCharacterIntersect(Character * character, MonsterManager * monsters)
{
	if (character->GetCharacterImortal() != ImortalOn)
	{
		Rect cRect = character->GetIntersectRect();

		for (size_t i = 0; i < monsters->GetMonsters().size(); i++)
		{
			Monster* monster = monsters->GetMonsters()[i];
			for (size_t j = 0; j < monster->GetBullet().size(); j++)
			{
				Bullet* bullet = monster->GetBullet()[j];
				if (Rect::Intersect(cRect, bullet->GetRect()))
				{
					bullet->SetIsIntersect(true);
					character->SetState(DeadState);
				}
			}
		}
	}
}

void IntersectManager::BulletTileIntersect(Character* character, BackgroundManager* back)
{
	vector<Bullet*> bullets = character->GetGun()->GetBullet();
	vector<Tile*> tiles = back->GetTiles();

	for (size_t i = 0; i < bullets.size(); i++)
	{
		Bullet* bullet = bullets[i];
		for (size_t j = 0; j < tiles.size(); j++)
		{
			if (tiles[j]->IsIntersect(bullet))
			{
				bullet->SetIsIntersect(true);
			}
		}
	}
}

void IntersectManager::BombIntersect(Character * character, BackgroundManager * back, MonsterManager * monsters)
{
	for (size_t i = 0; i < character->GetBombs().size(); i++)
	{
		Bullet* bomb = character->GetBombs()[i];
		bomb->Update(); //폭탄 위치 이동 후 이벤트 처리
		for (size_t j = 0; j < back->GetTiles().size(); j++)
		{
			Tile* tile = back->GetTiles()[j];
			Rect rect; //폭탄과 부딫힌 타일 렉트
			Rect::Direction dir = tile->IsIntersectDirection(bomb, rect);
			if (dir != Rect::Direction::None)
			{
				bomb->SetTime(0);
				bomb->SetSpeed((float)rect.frictionalForce);
				switch (dir)
				{
					case Rect::Direction::Right: //폭탄 오른편에서 부딫힘
					{	
						bomb->SetStartX(rect.GetLeft() - bomb->GetRect().size.width - 0.1f);
						bomb->SetStartY(bomb->GetLocation().y);
					}
					break;
					case Rect::Direction::Left:
					{		
						bomb->SetStartX(rect.GetRight() + 0.1f);
						bomb->SetStartY(bomb->GetLocation().y);
					}
					break;
					case Rect::Direction::Top: //위에서 부딫힘
					{	
						bomb->SetStartY(rect.GetBottom() + 0.1f);
						bomb->SetStartX(bomb->GetLocation().x);
					}
					break;
					case Rect::Direction::Bottom:
					{	
						bomb->SetStartY(rect.GetTop() - bomb->GetRect().size.height - 0.1f);
						bomb->SetStartX(bomb->GetLocation().x);
					}
					break;
				}
				if (dir == Rect::Direction::Right || dir == Rect::Direction::Left)
					bomb->SetIsRight(bomb->GetIsRight() == true ? false : true);
				else if (dir == Rect::Direction::Top || dir == Rect::Direction::Bottom)
					bomb->SetIsTop(bomb->GetIsTop() == true ? false : true);
			}
		}

		for (size_t j = 0; j < monsters->GetMonsters().size(); j++)
		{
			if (bomb->GetIsIntersect() == false)
			{
				Monster* mon = monsters->GetMonsters()[j];
				if (Rect::Intersect(mon->GetIntersectRect(), bomb->GetRect()))
				{
					bomb->SetIsIntersect(true);
					break;
				}
			}
		}

		for (size_t j = 0; j < monsters->GetMonsters().size(); j++)
		{
			if (bomb->GetIsIntersect() == true) //터지면 광역 공격
			{
				Monster* mon = monsters->GetMonsters()[j];
				if (Rect::Intersect(mon->GetIntersectRect(), bomb->GetIntersectRect()))
					mon->SetHp(2); //폭탄 공격에 데미지 받음
			
				if (mon->GetHp() <= 0)
					mon->GetIMonster()->Dead();
			}
		}
		if (timeGetTime() - bomb->GetPrevTime() > 1500)
			bomb->SetIsIntersect(true);
	}
}

void IntersectManager::CharacterNpcIntersect(Character* character, vector<Npc*> npc)
{
	vector<Bullet*> bullets = character->GetGun()->GetBullet();

	for (size_t i = 0; i < npc.size(); i++)
	{
		switch (npc[i]->GetNpcState())
		{
			case IdleStateNpc:
			{
				for (size_t j = 0; j < bullets.size(); j++)
				{
					if (Rect::Intersect(npc[i]->GetRect(), bullets[j]->GetRect()))
					{
						bullets[j]->SetIsIntersect(true);
						npc[i]->SetNpcState(IntersectNpc);
					}
				}
			}
			break;
			case ItemNpc:
			{
				if (Rect::Intersect(character->GetIntersectRect(), npc[i]->GetRect()))
				{
					npc[i]->SetNpcState(EndNpc);
					character->SetGun(npc[i]->GetName());
					character->GetGun()->SetBulletCount(npc[i]->GetName());
				}
			}
			break;
		}
	}
}

void IntersectManager::BackgroundEvent(Character * character, BackgroundManager * back)
{
	//크랩 케이브 파괴, 배 탔을때 이벤트 처리
	vector<Bullet*> bullets = character->GetGun()->GetBullet();
	Rect rect = character->GetIntersectRect();

	Tile* gate = back->GetTile(L"TargetGate");
	Tile* gate1 = back->GetTile(L"TargetGate2");
	Tile* ship = back->GetTile(L"PlayerShip");

	if (gate != NULL && gate1 != NULL)
	{
		for (size_t i = 0; i < bullets.size(); i++)
		{
			if (Rect::Intersect(gate->GetIntersectRect(), bullets[i]->GetRect()))
			{
				bullets[i]->SetIsIntersect(true);
				gate->SetHp(bullets[i]->GetAttackPower());
				gate1->SetHp(bullets[i]->GetAttackPower());
			}
		}
	}
	if (ship->IsIntersect(character) == true)
		ship->SetIsIntersect(true);

	Tile* sea = back->GetTile(L"Sea_Down");
	if (character->GetLocation().x < 650 && character->GetLocation().y > 500)
	{
		DeadClass::GetInstance()->Push
		(
			new DeadEffect1(Rect(character->GetLocation().x, sea->GetLocation().y - 20, 60,30),Size(1,1),L"WaterExplosion",3, Size(53, 16))
		);
	}
}
