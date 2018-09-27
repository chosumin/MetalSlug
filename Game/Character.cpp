#include "../stdafx.h"
#include "Gun.h"
#include "Bullet.h"
#include "Character.h"

Character::Character(Rect rect, float speed)
	: rect(rect), speed(speed), jumpPoint(rect.location),
	jumpDst(0), jumpPower(25), jumpSpeed(0.5f), isJump(false),
	cs(IdleState), cd(RightCharacterState), ca(OffAttack), ci(ImotalOff)
	,upperLocation(Point()), isDead(false), timer(false), bombCount(10)
	,isCaptured(false), isBomb(false)
{
	intersectRect = rect;
	gun = new Gun(rect.location);
	gun->SetName(L"Pistol");
	intersectRect = Rect(rect.location.x, rect.location.y - 60, 60, 100);
	drawer = new RectDrawer(intersectRect, 0, 0xFF000000);
}

Character::~Character()
{
	SAFE_DELETE(gun);
	for (size_t i = 0; i < bombs.size(); i++)
		SAFE_DELETE(bombs[i]);
	SAFE_DELETE(drawer);
}

Animation * Character::GetUpperAnimation()
{
	if (cs == DeadState)
	{
		if (cd == LeftCharacterState)
			return dead_left;
		else
			return dead_right;
	}

	if (isBomb == true)
	{
		if (cd == LeftCharacterState)
			return left_bomb;
		else
			return right_bomb;
	}

	if (wcscmp(gun->GetName().c_str(), L"Pistol") == 0)
	{
		switch (cd)
		{
			case RightCharacterState:
			{
				switch (ca)
				{
					case OnAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOn_upper_right_pistol_idle_1;
							case UpHoldState:		return attackOn_upper_right_pistol_upHold;

							case MoveState:			return attackOn_upper_right_pistol_idle_1;
							case UpHoldMoveState:	return attackOn_upper_right_pistol_upHold;

							case JumpState:			return attackOn_upper_right_pistol_idle_1;
							case UpHoldJumpState:	return attackOn_upper_right_pistol_upHold;
							case DownState:			return attackOn_upper_right_pistol_down;
							case SitState:			return attackOn_right_pistol_sit;
						}
					} //OnAttack
					case OffAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOff_upper_right_pistol_idle_1;
							case UpHoldState:		return attackOff_upper_right_pistol_upHold;

							case MoveState:			return attackOff_upper_right_pistol_move;
							case UpHoldMoveState:	return attackOff_upper_right_pistol_upHold;

							case JumpState:			return attackOff_upper_right_pistol_jump;
							case UpHoldJumpState:	return attackOff_upper_right_pistol_upHold;
							case DownState:			return attackOff_upper_right_pistol_down;
							case SitState:			return attackOff_right_pistol_sit;
						}
					} //OffAttack
				}
			}//case RightCharacterState
			case LeftCharacterState:
			{
				switch (ca)
				{
					case OnAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOn_upper_left_pistol_idle_1;
							case UpHoldState:		return attackOn_upper_left_pistol_upHold;

							case MoveState:			return attackOn_upper_left_pistol_idle_1;
							case UpHoldMoveState:	return attackOn_upper_left_pistol_upHold;

							case JumpState:			return attackOn_upper_left_pistol_idle_1;
							case UpHoldJumpState:	return attackOn_upper_left_pistol_upHold;
							case DownState:			return attackOn_upper_left_pistol_down;
							case SitState:			return attackOn_left_pistol_sit;
						}
					}
					case OffAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOff_upper_left_pistol_idle_1;
							case UpHoldState:		return attackOff_upper_left_pistol_upHold;

							case MoveState:			return attackOff_upper_left_pistol_move;
							case UpHoldMoveState:	return attackOff_upper_left_pistol_upHold;

							case JumpState:			return attackOff_upper_left_pistol_jump;
							case UpHoldJumpState:	return attackOff_upper_left_pistol_upHold;
							case DownState:			return attackOff_upper_left_pistol_down;
							case SitState:			return attackOff_left_pistol_sit;
						}
					}
				}
			}//case LefttCharacterState
		}
	}
	else
	{
		switch (cd)
		{
			case RightCharacterState:
			{
				switch (ca)
				{
					case OnAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOn_upper_right_heavyWeapon_idle_1;
							case UpHoldState:		return attackOn_upper_right_heavyWeapon_upHold;

							case MoveState:			return attackOn_upper_right_heavyWeapon_idle_1;
							case UpHoldMoveState:	return attackOn_upper_right_heavyWeapon_upHold;

							case JumpState:			return attackOn_upper_right_heavyWeapon_idle_1;
							case UpHoldJumpState:	return attackOn_upper_right_heavyWeapon_upHold;
							case DownState:			return attackOn_upper_right_heavyWeapon_down;
							case SitState:			return attackOn_right_heavyWeapon_sit;
						}
					} //OnAttack
					case OffAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOff_upper_right_heavyWeapon_idle_1;
							case UpHoldState:		return attackOff_upper_right_heavyWeapon_upHold;

							case MoveState:			return attackOff_upper_right_heavyWeapon_move;
							case UpHoldMoveState:	return attackOff_upper_right_heavyWeapon_upHold;

							case JumpState:			return attackOff_upper_right_heavyWeapon_jump;
							case UpHoldJumpState:	return attackOff_upper_right_heavyWeapon_upHold;
							case DownState:			return attackOff_upper_right_heavyWeapon_down;
							case SitState:			return attackOff_right_heavyWeapon_sit;
						}
					} //OffAttack
				}
			}//case RightCharacterState
			case LeftCharacterState:
			{
				switch (ca)
				{
					case OnAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOn_upper_left_heavyWeapon_idle_1;
							case UpHoldState:		return attackOn_upper_left_heavyWeapon_upHold;

							case MoveState:			return attackOn_upper_left_heavyWeapon_idle_1;
							case UpHoldMoveState:	return attackOn_upper_left_heavyWeapon_upHold;

							case JumpState:			return attackOn_upper_left_heavyWeapon_idle_1;
							case UpHoldJumpState:	return attackOn_upper_left_heavyWeapon_upHold;
							case DownState:			return attackOn_upper_left_heavyWeapon_down;
							case SitState:			return attackOn_left_heavyWeapon_sit;
						}
					}
					case OffAttack:
					{
						switch (cs)
						{
							case IdleState:			return attackOff_upper_left_heavyWeapon_idle_1;
							case UpHoldState:		return attackOff_upper_left_heavyWeapon_upHold;

							case MoveState:			return attackOff_upper_left_heavyWeapon_move;
							case UpHoldMoveState:	return attackOff_upper_left_heavyWeapon_upHold;

							case JumpState:			return attackOff_upper_left_heavyWeapon_jump;
							case UpHoldJumpState:	return attackOff_upper_left_heavyWeapon_upHold;
							case DownState:			return attackOff_upper_left_heavyWeapon_down;
							case SitState:			return attackOff_left_heavyWeapon_sit;
						}
					}
				}
			}//case LefttCharacterState
		}
	}
	return attackOff_upper_right_pistol_idle_1;
}

Animation * Character::GetLowerAnimation()
{
	switch (cd)
	{
		case RightCharacterState:
		{
			switch (cs)
			{
				case IdleState:			return lower_right_idle;
				case UpHoldState:		return lower_right_idle;

				case MoveState:			return lower_right_move;
				case UpHoldMoveState:	return lower_right_move;

				case JumpState:			return lower_right_jump;
				case UpHoldJumpState:	return lower_right_jump;
				case DownState:			return lower_right_jump;
			}
		}//RightCharacterState
		case LeftCharacterState:
		{
			switch (cs)
			{
				case IdleState:			return lower_left_idle;
				case UpHoldState:		return lower_left_idle;

				case MoveState:			return lower_left_move;
				case UpHoldMoveState:	return lower_left_move;

				case JumpState:			return lower_left_jump;
				case UpHoldJumpState:	return lower_left_jump;
				case DownState:			return lower_left_jump;
			}
		}
	}
	return lower_right_idle;
}

void Character::SetState(CharacterState cs)
{
	this->cs = cs;
}

void Character::SetDirection(CharacterDirection cd)
{
	this->cd = cd;
}

void Character::SetAttack(CharacterAttack ca)
{
	this->ca = ca;
}

void Character::SetGunAngle()
{
	switch (cd)
	{
		case LeftCharacterState:
		{
			switch (cs)
			{
				case UpHoldState:
				case UpHoldJumpState:
				case UpHoldMoveState:
					gun->SetAngle(270);
					break;
				case DownState:
					gun->SetAngle(90);
					break;
				default:
					gun->SetAngle(180);
					break;
			}
		}
		break;
		case RightCharacterState:
		{
			switch (cs)
			{
				case UpHoldState:
				case UpHoldJumpState:
				case UpHoldMoveState:
					gun->SetAngle(270);
					break;
				case DownState:
					gun->SetAngle(90);
					break;
				default:
					gun->SetAngle(0);
					break;
			}
		}
		break;
	}
}

void Character::PushBackBomb(Bullet * bomb)
{
	bombs.push_back(bomb);
}

void Character::SetGun(wstring name)
{
	gun->SetName(name);
}

void Character::Update()
{
	Jump();
	GetLowerAnimation()->Update();
	GetUpperAnimation()->Update();
	//gun->SetLocation(rect.location);
	gun->Update();

	if (isDead == false && cs == DeadState)
	{
		if (GetUpperAnimation()->GetCurCount() >= (UINT)GetUpperAnimation()->GetClipCount() - 1)
		{
			if (timer == false)
			{
				DeadClass::GetInstance()->Push
				(
					new DeadEffect1(intersectRect, Size(2,2), L"Blood",5, Size(41, 34))
				);
				TIMER()->AddTimer(this, 700);
				timer = true;
				isCaptured = false;
			}
		}
	}
	intersectRect = Rect(rect.location.x, rect.location.y - 70, 60, 100);

	if (ci == ImortalOn)
	{
		if (timeGetTime() - imortalTime > 2000)
			ci = ImotalOff;
	}

	DeleteBombs();
}

void Character::Render()
{
	if (isDead == true) return;
	gun->Render();
	upperLocation = rect.location;
	upperLocation.y -= 35;
	Size size = GetLowerAnimation()->GetSize();
	Size upSize = GetUpperAnimation()->GetSize();

	if (cs != SitState && cs != DeadState)
	{
		Direct2D::SetWorldLocation(upperLocation, 0, size);
		GetLowerAnimation()->Render();
		Point center = GetUpperAnimation()->GetCenter();
		if (cd == LeftCharacterState)
			center.x = upSize.width - center.x;
		upperLocation.y -= center.y;
		upperLocation.x = upperLocation.x + size.width * 0.5f - center.x;
	}
	else
		upperLocation.y += 35 - upSize.height;
	Direct2D::SetWorldLocation(upperLocation, 0, size);
	GetUpperAnimation()->Render();

	for (size_t i = 0; i < bombs.size(); i++)
		bombs[i]->Render();
	//Direct2D::SetWorldLocation(intersectRect.location, 0, size);
	//drawer->Render();
}

void Character::Event()
{
	isDead = true;
}

void Character::Jump()
{
	if (isJump == false) return;
	float height = jumpDst * jumpDst - jumpPower * jumpDst;

	rect.location.y = jumpPoint.y + height;
	jumpDst += jumpSpeed;

	if (jumpPower < jumpDst) //Á¡ÇÁ ³¡
	{
		isJump = false;
		jumpDst = 0;
		rect.location.y = jumpPoint.y;

		switch (cs)
		{
			case JumpState: cs = IdleState; break;
			case DownState: cs = IdleState; break;
			case UpHoldJumpState: cs = UpHoldState; break;
		}
	}
}

void Character::DeleteBombs()
{
	vector<Bullet*>::iterator iter = bombs.begin();

	for (; iter != bombs.end();)
	{
		if ((*iter)->GetIsIntersect() == true)
		{
			DeadClass::GetInstance()->Push
			(
				new DeadEffect1((*iter)->GetRect(), Size(2, 2), L"RocketDestroy", 4, Size(71, 80))
			);
			SAFE_DELETE(*iter);
			iter = bombs.erase(iter);
		}
		else
			iter++;
	}
}
