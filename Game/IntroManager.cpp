#include "../stdafx.h"
#include "Character.h"
#include "Tarma.h"
#include "Fiolina.h"
#include "IntroManager.h"

IntroManager* IntroManager::instance = NULL;

IntroManager * IntroManager::GetInstance()
{
	if (instance == NULL)
		instance = new IntroManager();

	return instance;
}

void IntroManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void IntroManager::Update(Character** character)
{
	switch (is)
	{
		case FirstState:
		{
			if (flash == false)
			{
				flash = true;
			}

			if (KEYBOARD()->KeyDown(VK_RETURN))
				FadeClass::GetInstance()->Add();

			if (FadeClass::GetInstance()->GetLast())
			{
				is = SelectCharacterState;
				FadeClass::GetInstance()->DeleteEffect();
			}
		}
		break;
		case SelectCharacterState:
		{
			if (KEYBOARD()->KeyDown(VK_RIGHT) || KEYBOARD()->KeyDown(VK_LEFT))
				select = select == true ? false : true;

			if (KEYBOARD()->KeyDown(VK_RETURN))
			{
				choice = true;
				TIMER()->AddTimer(this, 2500);
				SAFE_DELETE(*character);
				if (select == true) //fiolina pick
					*character = new Fiolina(Rect(100, 220, 40, 80), 3);
				else
					*character = new Tarma(Rect(100, 220, 40, 80), 3);
			}

			if (FadeClass::GetInstance()->GetLast())
			{
				is = GameStartState;
				FadeClass::GetInstance()->DeleteEffect();
			}
		}
		break;
	}
}

void IntroManager::Render()
{
	Point zeroPoint = Point(2 * 2, 170);
	Point potrait = zeroPoint;
	int gap = 135;
	switch (is)
	{
		case FirstState:
		{	
			Direct2D::SetWorldLocation(zeroPoint, 0);
			mainScreen->Render();
			Size s;
			insertCoin->GetSize(&s);
			if (p.y > 485 || p.y < 480)
				dst *= -1;
			p.y += dst;
			Direct2D::SetWorldLocation(p, 0);
			if (flash == true)
				insertCoin->Render();
			else
				blank->Render();
		}
		break;
		case SelectCharacterState:
		{
			potrait = potrait + Point(302, 127);
			if (choice == false)
			{
				if (select == false) //타르마 선택
				{
					Direct2D::SetWorldLocation(potrait, 0);
					tarmaLight->Render();
					potrait.x += gap;
					Direct2D::SetWorldLocation(potrait, 0);
					fiolinaBlack->Render();
				}
				else //피오리나 선택
				{
					Direct2D::SetWorldLocation(potrait, 0);
					tarmaBlack->Render();
					potrait.x += gap;
					Direct2D::SetWorldLocation(potrait, 0);
					fiolinaLight->Render();
				}
			}//choice
			else
			{
				if (select == false) //타르마 픽
				{
					Direct2D::SetWorldLocation(potrait, 0);
					tarmaPick->Render();
					potrait.x += gap;
					Direct2D::SetWorldLocation(potrait, 0);
					fiolinaBlack->Render();
					
					potrait.x -= gap;
					DownM3(potrait);

					if (idleAnim != NULL)
					{
						Direct2D::SetWorldLocation(Point(306 + 40, 297 + 125), -4);
						idleAnim->Render();
					}
				}
				else
				{
					Direct2D::SetWorldLocation(potrait, 0);
					tarmaBlack->Render();
					potrait.x += gap;
					Direct2D::SetWorldLocation(potrait, 0);
					fiolinaPick->Render();

					DownM3(potrait);

					if (idleAnim != NULL)
					{
						Direct2D::SetWorldLocation(Point(potrait.x + 40, potrait.y + 125), -4);
						idleAnim->Render();
					}
				}
			}//choice

			Direct2D::SetWorldLocation(zeroPoint, -2);
			selectMain->Render();
		}
		break;
	}
}

void IntroManager::Event()
{
	FadeClass::GetInstance()->Add();
}

IntroManager::IntroManager()
	:flash(false), is(FirstState), select(false), choice(false)
	, idleAnim(NULL), p(Point(260, 480)), dst(0.1f)
{
	AddImage();
}

IntroManager::~IntroManager()
{
	SAFE_DELETE(mainScreen);
	SAFE_DELETE(insertCoin);
	SAFE_DELETE(blank);

	SAFE_DELETE(selectMain);
	SAFE_DELETE(p1_Icon);
	SAFE_DELETE(m3);
	SAFE_DELETE(tarmaBlack);
	SAFE_DELETE(tarmaLight);
	SAFE_DELETE(tarmaPick);
	SAFE_DELETE(fiolinaBlack);
	SAFE_DELETE(fiolinaLight);
	SAFE_DELETE(fiolinaPick);
}

void IntroManager::AddImage()
{
	Size ratio = Size(2, 2);
	D3DVIEWPORT9 viewport;
	Direct2D::Device()->GetViewport(&viewport);

	windowSize = Size((float)viewport.Width, (float)viewport.Height);
	mainScreen = new TextureDrawer(windowSize, L"FirstScreen", 0);
	insertCoin = new TextureDrawer(Size(80, 30), L"InsertCoin", 0);
	blank = new TextureDrawer(Size(80, 30), L"blank", 0);

	selectMain = new TextureDrawer(windowSize, L"MainScreen", -1);
	p1_Icon = new TextureDrawer(Size(48, 32) * ratio, L"P1_Icon", -2);
	m3 = new TextureDrawer(Size(64, 134) * ratio, L"M3", 0);
	tarmaBlack = new TextureDrawer(Size(64, 120) * ratio, L"Tarma_Black", 0);
	tarmaLight = new TextureDrawer(Size(64, 120) * ratio, L"Tarma_Light", 0);
	tarmaPick = new TextureDrawer(Size(64, 120) * ratio, L"Tarma_Pick", 0);
	fiolinaBlack = new TextureDrawer(Size(64, 120) * ratio, L"Fiolina_Black", 0);
	fiolinaLight = new TextureDrawer(Size(64, 120) * ratio, L"Fiolina_Light", 0);
	fiolinaPick = new TextureDrawer(Size(64, 120) * ratio, L"Fiolina_Pick", 0);
}

void IntroManager::DownM3(Point p)
{
	static int dst = 0;
	p.y = (float)dst;

	Direct2D::SetWorldLocation(p, 0);
	m3->Render();

	if(dst < 290)
		dst += 6;
	else
	{
		if (select == false)
		{
			ImageCuttingManager::GetInstance()->CreateAnimation
			(
				false,
				&idleAnim,
				L"Tarma_attackOff_upper_pistol_idle1_",
				150,
				Size(2, 2),
				4,
				Size(31, 29),
				0, AniRepeatType_Loop, Point(16 - 7, 285 - 265)
			);
		}
		else
		{
			ImageCuttingManager::GetInstance()->CreateAnimation
			(
				false,
				&idleAnim,
				L"Fiolina_attackOff_upper_pistol_idle1_",
				100,
				Size(2, 2),
				5,
				Size(28, 26),
				0, AniRepeatType_Loop, Point(92 - 83, 22 - 4)
			);
		}
	}
}
