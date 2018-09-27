#include "../stdafx.h"
#include "Tile.h"
#include "../Camera/Camera.h"
#include "BackgroundManager.h"

BackgroundManager::BackgroundManager()
{
	Initialize();
	isMove = false;
	isStopTraffic = false;
}

BackgroundManager::~BackgroundManager()
{
	for (size_t i = 0; i < tiles.size(); i++)
		SAFE_DELETE(tiles[i]);
}

void BackgroundManager::Initialize()
{
	wstring fileName = L"./Textures/Mission1.png";
	DWORD colorKey = 0xfff800f8;

	TextureManager::GetInstance()->Add(fileName, L"Background", &Rect(0, 0, 2374, 278), colorKey);
	//Rect r = Rect(0, 0, 2374, 278);
	Tile* background = new Tile(false, Point(0, 0), 3, Rect(0, 0, 2374, 278), L"Background");
	ImageCuttingManager::GetInstance()->CreateTexture(background->GetDrawer(), background->GetName(), background->GetRect(), Size(2, 2), 3);
	
	tiles.push_back(background);
	
	ImageCuttingManager::GetInstance()->CreateAnimationVerticalInTextureMap
		(
		fileName, L"Sea_Up", 8, Point(2, 669), Size(563,24), 42, colorKey
		);
	Tile* seaUp = new Tile(true, Point(0, 450), 1, Rect(2, 669, 563, 24), L"Sea_Up");
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
			false,
			seaUp->GetAnimation(),
			seaUp->GetName(),
			150,
			Size(2, 2),
			8,
			Size(563, 24),
			1
		);

	tiles.push_back(seaUp);

	ImageCuttingManager::GetInstance()->CreateAnimationVerticalInTextureMap
		(
		fileName, L"Sea_Down", 8, Point(2, 694), Size(563, 40), 26, colorKey
		);
	Tile* seaDown = new Tile(true, Point(0, 498), -0.1f, Rect(2, 694, 563, 40), L"Sea_Down");
	ImageCuttingManager::GetInstance()->CreateAnimation
		(
		false,
		seaDown->GetAnimation(),
		seaDown->GetName(),
		150,
		Size(2, 2),
		8,
		Size(563, 40),
		-0.1f
		);

	tiles.push_back(seaDown);

	TextureManager::GetInstance()->Add(fileName, L"Beach_1", &Rect(322, 1197, 243, 156), colorKey);
	Tile* beach_1 = new Tile(false, Point(563 * 2 - 243 * 2, 450 - 156 * 2), 1, Rect(322, 1197, 243, 156), L"Beach_1");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		beach_1->GetDrawer(), beach_1->GetName(), beach_1->GetRect(), Size(2, 2), 1
		);

	tiles.push_back(beach_1);

	TextureManager::GetInstance()->Add(fileName, L"Beach_2", &Rect(565, 1197, 358, 220), colorKey);
	Tile* beach_2 = new Tile(false, Point(563 * 2, 138), 1, Rect(565, 1197, 358, 220), L"Beach_2");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		beach_2->GetDrawer(), beach_2->GetName(), beach_2->GetRect(), Size(2, 2), 1
		);

	tiles.push_back(beach_2);

	TextureManager::GetInstance()->Add(fileName, L"TargetGate", &Rect(3863, 1, 117, 138), colorKey);
	Tile* targetGate = new Tile(false, Point(563 * 2 + 358 * 2 - 117 * 2 + 14, 138 + 22), 1, Rect(3863, 1, 117, 138), L"TargetGate");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		targetGate->GetDrawer(), targetGate->GetName(), targetGate->GetRect(), Size(2, 2), 1
		);

	tiles.push_back(targetGate);

	//9-30 gate바깥쪽 이미지 붙이기 및 모든 맵 붙여넣기

	TextureManager::GetInstance()->Add(fileName, L"TargetGate2", &Rect(3983, 1, 109, 138), colorKey);
	Tile* targetGate2 = new Tile(false, Point(563 * 2 + 358 * 2 - 117 * 2 + 22, 138 + 22), -1, Rect(3983, 1, 109, 138), L"TargetGate2");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		targetGate2->GetDrawer(), targetGate2->GetName(), targetGate2->GetRect(), Size(2, 2), -1
		);

	tiles.push_back(targetGate2);

	TextureManager::GetInstance()->Add(fileName, L"Beach3_Ship", &Rect(1229, 685, 270, 105), colorKey);
	Tile* beach3_ship = new Tile(false, Point(beach_2->GetRight(), beach_2->GetBottom() - 105 * 2), 1
								 , Rect(1229, 685, 270, 105), L"Beach3_Ship");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		beach3_ship->GetDrawer(), beach3_ship->GetName(), beach3_ship->GetRect(), Size(2, 2), 1
		);

	tiles.push_back(beach3_ship);

	TextureManager::GetInstance()->Add(fileName, L"Beach_4", &Rect(1195, 1354, 211, 63), colorKey);
	Tile* beach_4 = new Tile(false, Point(beach3_ship->GetRight() - 1, beach3_ship->GetBottom() - 63 * 2), 1, 
							 Rect(1195, 1354, 211, 63), L"Beach_4");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		beach_4->GetDrawer(), beach_4->GetName(), beach_4->GetRect(), Size(2, 2), 1
		);

	tiles.push_back(beach_4);

	TextureManager::GetInstance()->Add(fileName, L"Forest", &Rect(1615, 845, 1456, 242), colorKey);
	Tile* forest = new Tile(false, Point(2743, 127),
							2, Rect(1615, 845, 1456, 242), L"Forest");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		forest->GetDrawer(), forest->GetName(), forest->GetRect(), Size(2, 2), 2
		);

	tiles.push_back(forest);

	TextureManager::GetInstance()->Add(fileName, L"Beach4_BigShip", &Rect(1389, 885, 203, 224), colorKey);
	Tile* beach4_BigShip = new Tile(false, Point(beach_4->GetRight(), beach_4->GetBottom() - 224 * 2), 
									1, Rect(1389, 885, 203, 224), L"Beach4_BigShip");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		beach4_BigShip->GetDrawer(), beach4_BigShip->GetName(), beach4_BigShip->GetRect(), Size(2, 2), 1
		);

	tiles.push_back(beach4_BigShip);

	ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
	(
		fileName, L"Beach4_BigShipGate", 6, Point(582, 799), Size(127, 74), 5, colorKey
	);
	Tile* beach4_BigShipGate = new Tile(true, Point(beach4_BigShip->GetRight() - 260, beach4_BigShip->GetBottom() - 74 * 2 - 100), 0.1f
										, Rect(582, 799, 127, 74), L"Beach4_BigShipGate");

	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, beach4_BigShipGate->GetAnimation(), beach4_BigShipGate->GetName(),
		100, Size(2, 2), 6, Size(127, 74), 1, AniRepeatType_End
	);

	tiles.push_back(beach4_BigShipGate);

	TextureManager::GetInstance()->Add(fileName, L"Beach4_BigShipSurface", &Rect(2291, 607, 279, 183), colorKey);
	Tile* beach4_BigShipSurface = new Tile(false, Point(beach4_BigShip->GetRight() - 279 * 2, beach4_BigShip->GetBottom() - 183 * 2),
										   -1, Rect(2291, 607, 279, 183), L"Beach4_BigShipSurface");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		beach4_BigShipSurface->GetDrawer(), beach4_BigShipSurface->GetName(), beach4_BigShipSurface->GetRect(), Size(2, 2), -1
		);

	tiles.push_back(beach4_BigShipSurface);

	TextureManager::GetInstance()->Add(fileName, L"Forest_Down", &Rect(1615, 1152, 1287, 131), colorKey);
	Tile* forest_Down = new Tile(false, Point(2745, 410), 1, Rect(1615, 1152, 1287, 131), L"Forest_Down");
	ImageCuttingManager::GetInstance()->CreateTexture
		(
		forest_Down->GetDrawer(), forest_Down->GetName(), forest_Down->GetRect(), Size(2, 2), 1
		);

	tiles.push_back(forest_Down);

	TextureManager::GetInstance()->Add(fileName, L"Swamp", &Rect(3072, 845, 1312, 242), colorKey);
	Tile* swamp = new Tile(false, Point(forest->GetRight(), forest->GetBottom() - 242 * 2), 1, Rect(3072, 845, 1312, 242), L"Swamp");
	ImageCuttingManager::GetInstance()->CreateTexture
	(
		swamp->GetDrawer(), swamp->GetName(), swamp->GetRect(), Size(2, 2), 1
	);

	tiles.push_back(swamp);

	TextureManager::GetInstance()->Add(fileName, L"PlayerShip", &Rect(710, 292, 211, 98), colorKey);
	Tile* playerShip = new Tile(false, Point(swamp->GetLocation().x + 50,swamp->GetBottom() - 98 * 2 - 10), 1, Rect(710, 292, 211, 98), L"PlayerShip");
	ImageCuttingManager::GetInstance()->CreateTexture
	(
		playerShip->GetDrawer(), playerShip->GetName(), playerShip->GetRect(), Size(2, 2), 1
	);
	
	tiles.push_back(playerShip);

	ImageCuttingManager::GetInstance()->CreateAnimationInTextureMap
	(
		fileName, L"PlayerShipWave", 8,
		Point(3286, 581), Size(224, 25), 1, 0xff00ff00
	);
	Tile* playerShipWave = new Tile(true, Point(playerShip->GetLocation().x - 15, playerShip->GetBottom() - 40), 1, Rect(3286, 581, 224, 25), L"PlayerShipWave");
	
	ImageCuttingManager::GetInstance()->CreateAnimation
	(
		false, playerShipWave->GetAnimation(), L"PlayerShipWave",
		100, Size(2,2), 8, Size(224, 25), 1
	);

	tiles.push_back(playerShipWave);

	TextureManager::GetInstance()->Add(fileName, L"TruckFloor", &Rect(2879, 1088, 205, 80), colorKey);
	Tile* truckFloor = new Tile(false, Point(5655 + 674 * 2, playerShip->GetBottom() - 130), 1, Rect(2879, 1088, 205, 80), L"TruckFloor");
	ImageCuttingManager::GetInstance()->CreateTexture
	(
		truckFloor->GetDrawer(), truckFloor->GetName(), truckFloor->GetRect(), Size(2, 2), 1
	);

	tiles.push_back(truckFloor);

	AddRects();
}

vector<Tile*> BackgroundManager::GetTiles() const
{
	return tiles;
}

Tile * BackgroundManager::GetTile(wstring name) const
{
	for (size_t i = 0; i < tiles.size(); i++)
	{
		if (wcscmp(tiles[i]->GetName().c_str(), name.c_str()) == 0)
			return tiles[i];
	}

	return NULL;
}

void BackgroundManager::DeleteTiles(Camera* camera)
{
	iter = tiles.begin();
	float cameraX = camera->GetLocation().x;
	for (; iter != tiles.end();)
	{
		if ((*iter)->GetRight() < cameraX || (*iter)->GetIsOver() == true)
		{
			SAFE_DELETE(*iter);
			iter = tiles.erase(iter);
		}
		else
			iter++;
	}
}

void BackgroundManager::DeleteTiles(wstring name)
{
	iter = tiles.begin();
	for (; iter != tiles.end(); iter++)
	{
		if ((*iter)->GetName() == name)
		{
			SAFE_DELETE(*iter);
			iter = tiles.erase(iter);
			break;
		}
	}
}

void BackgroundManager::Update()
{
	for (size_t i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Update();	

		if (tiles[i]->GetIsIntersect() == true)
			isMove = true;

		if (isMove)
		{
			if (wcscmp(tiles[i]->GetName().c_str(), L"Swamp") == 0 || wcscmp(tiles[i]->GetName().c_str(), L"TruckFloor") == 0)
			{
				if (isStopTraffic == false) //트럭 왔을시, 보스 도달시 멈춤
				{
					Point p = tiles[i]->GetLocation();
					tiles[i]->SetLocation(Point(p.x - 2, p.y));
				}
			}
		}
	}
}

void BackgroundManager::Render()
{
	for (size_t i = 0; i < tiles.size(); i++)
	{
		if (tiles[i]->GetName() != L"TargetGate2" && tiles[i]->GetName() != L"Beach4_BigShipSurface")
			tiles[i]->Render();
	}
}

void BackgroundManager::AddRects()
{
	vector<RectDrawer*> seaDownRects;
	float left = 0, right = 0, width = 0, height = 0;
	float top = 0, bottom = 0;
	width = 375.3f;
	height = 26.6f;
	{
		Rect rect(0, 528, width, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);
		seaDownRects.push_back(rect1);

		rect = Rect(375.3f, 515, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);
		seaDownRects.push_back(rect1);
	}
	{
		left = 750.6f;
		top = 501.3f;
		Rect rect(left, top, width, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);

		seaDownRects.push_back(rect1);
	}
	tiles[2]->InsertVector(seaDownRects);
	vector<RectDrawer*> beach2Rects;
	float top1 = 0;
	float a = width + left;
	width = 375.3f;
	for (int i = 0; i < 10; i++)
	{
		left = a + width * i;
		width = tiles[4]->GetWidth() / 16;
		height = tiles[4]->GetHeight() / 40;
		top1 = top - height * i;
		Rect rect(left, top1, width, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);

		beach2Rects.push_back(rect1);
	}
	left = 1573.39f, top1 = 397.3f, width = 179, height = 110;
	Rect rect(left, top1, width, height);
	RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);
	beach2Rects.push_back(rect1);

	left = 1752.39f, top1 = 427 + 70;
	width = tiles[4]->GetRight() - left;
	rect = Rect(left, 477, width, height);
	rect1 = new RectDrawer(rect, -1, 0xFF000000);
	beach2Rects.push_back(rect1);
	tiles[4]->InsertVector(beach2Rects);

	vector<RectDrawer*> beach3ShipRects;
	{
		left = tiles[7]->GetLocation().x;
		width = tiles[7]->GetWidth() / 5;
		height = tiles[7]->GetHeight() / 10;
		Rect rect(left, top1, 150, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);

		beach3ShipRects.push_back(rect1);

		left += width;
		width = tiles[7]->GetWidth() / 2;
		height = tiles[7]->GetHeight() / 2;
		top1 = 448;
		rect = Rect(2010, top1, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);

		beach3ShipRects.push_back(rect1);

		left += width;
		width = tiles[7]->GetRight() - left;
		height += 0;
		top1 += height - 50;
		rect = Rect(left, top1, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);

		beach3ShipRects.push_back(rect1);
	}
	tiles[7]->InsertVector(beach3ShipRects);

	vector<RectDrawer*> beach4Rects;
	{
		left = tiles[8]->GetLocation().x;
		width = tiles[8]->GetWidth();
		height = tiles[8]->GetHeight() / 2;
		top1 = tiles[8]->GetBottom() - height;
		Rect rect(left, top1, width, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);

		beach4Rects.push_back(rect1);
	}
	tiles[8]->InsertVector(beach4Rects);

	top = top1;
	vector<RectDrawer*> forestRects;
	{
		left = 2803, top = 515, width = 40.6f, height = 11.3f;
		Rect rect(2803, 515, 40.6f * 2, 11.3f);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);
		forestRects.push_back(rect1);
	}
	//길이 334 높이 67
	width = 334 / 6;
	height = 67 / 6;
	for (int i = 0; i < 6; i++)
	{
		left = 2894 + width * i;
		top = 515 - height * i;
		Rect rect(left, top, width, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);

		forestRects.push_back(rect1);
	}
	{	
		/*left = 3046;
		width = 81;
		height = 22.4f;
		top = 447.8f;
		Rect rect(left, top, width, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);
		forestRects.push_back(rect1);*/
	}
	vector<RectDrawer*> beach4BigShipRects;
	{
		left = 3046 + 81;
		width = 81;
		height = 22.4f;
		top = 447.8f;
		Rect rect(left, top, width, height);
		RectDrawer* rect1 = new RectDrawer(rect, -1, 0xFF000000);
		beach4BigShipRects.push_back(rect1);
	}
	{//3046 162 22.4 447.8
		width *= 1.3f;
		left = tiles[10]->GetRight() - width;
		height = tiles[10]->GetHeight() / 20;
		top = tiles[10]->GetTop() + 140;
		rect = Rect(left, top, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);

		beach4BigShipRects.push_back(rect1);
	}
	tiles[10]->InsertVector(beach4BigShipRects);

	 //2743, 127
	//1615, 845, 2771, 242
	left = 2770 + 198 * 2, top = 100 + 148 * 2;
	width = 43 * 2, height = 50 * 2;
	rect = Rect(left, top, width, height);
	rect1 = new RectDrawer(rect, -1, 0xFF000000);
	forestRects.push_back(rect1);

	left = 3166 + 86, top = 396 - 70; //3166, 396
	width = 43 * 2, height = 50 * 2;
	rect = Rect(left, top, width, height);
	rect1 = new RectDrawer(rect, -1, 0xFF000000);
	forestRects.push_back(rect1);

	tiles[9]->InsertVector(forestRects);

	AddForest(forestRects);

	//15타일
	vector<RectDrawer*> playerShipRect;
	{
		left = tiles[15]->GetLocation().x, top = tiles[15]->GetBottom() - 50;
		width = tiles[15]->GetWidth(), height = 50;
		rect = Rect(left, top, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);
		playerShipRect.push_back(rect1);

		left = tiles[15]->GetRight() - 50, top = tiles[15]->GetBottom() - 65;
		width = 50, height = 50;
		rect = Rect(left, top, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);
		playerShipRect.push_back(rect1);
	}
	tiles[15]->InsertVector(playerShipRect);
}

void BackgroundManager::AddForest(vector<RectDrawer*> vector)
{
	float left, top, width, height;
	RectDrawer* rect1;
	//3252, 326, 70, 12
	for (int i = 0; i < 10; i++)
	{
		left = 3340 + 140 * (float)i, top = 280;
		switch (i)
		{
			case 0:
				top += 0 * 24;
				break;
			case 1:
				top = 280 + 24;
				break;
			case 2:
				top += 24 * 2;
				break;
			case 3:
				top += 24 * 2;
				break;
			case 4:
				top += 24 * 3;
				break;
			case 5:
				top += 24 * 4;
				break;
			case 6:
				top += 24 * 5;
				break;
			case 7:
				top += 24 * 5;
				break;
			case 8:
				top += 24 * 6;
				break;
			case 9:
				top += 24 * 7;
				break;
		}
		width = 140, height = 24;
		Rect rect(left, top, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);
		vector.push_back(rect1);
	}
	
	left += 140, top = top, width = 750, height = 24;
	Rect rect(left, top, width, height);
	rect1 = new RectDrawer(rect, -1, 0xFF000000);
	vector.push_back(rect1);

	//4740, 448, 730, 24
	left += 750, top -= 23;
	rect = Rect(left, top, 50, 18);
	rect1 = new RectDrawer(rect, -1, 0xFF000000);
	vector.push_back(rect1);
	for (int i = 1; i < 3; i++)
	{
		left += 40, top -= 5;
		width = 50, height = 18;
		Rect rect(left, top, width, height);
		rect1 = new RectDrawer(rect, -1, 0xFF000000);
		vector.push_back(rect1);
	}

	tiles[9]->InsertVector(vector);
}
