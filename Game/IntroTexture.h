#pragma once

struct IntroTexture
{
	IntroTexture()
	{
		wstring fileName = L"./Textures/SelectScreen.png";
		DWORD colorKey = 0xFFFF00FF;
		TextureManager::GetInstance()->Load(fileName, colorKey);

		TextureManager::GetInstance()->Add(fileName, L"MainScreen", &Rect(4, 109, 304, 224), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"P1_Icon", &Rect(157, 38, 48, 32), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"M3", &Rect(70, 336, 64, 134), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Tarma_Black", &Rect(444, 3, 64, 120), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Fiolina_Black", &Rect(511, 3, 64, 120), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Tarma_Light", &Rect(444, 126, 64, 120), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Fiolina_Light", &Rect(511, 126, 64, 120), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Tarma_Pick", &Rect(444, 249, 64, 120), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Fiolina_Pick", &Rect(511, 249, 64, 120), colorKey);

		fileName = L"./Textures/Main.png";
		TextureManager::GetInstance()->Load(fileName, colorKey);
		TextureManager::GetInstance()->Add(fileName, L"FirstScreen", NULL, colorKey);

		fileName = L"./Textures/InsertCoin.png";
		TextureManager::GetInstance()->Load(fileName, colorKey);
		TextureManager::GetInstance()->Add(fileName, L"InsertCoin", NULL, colorKey);

		fileName = L"./Textures/blank.png";
		TextureManager::GetInstance()->Load(fileName, colorKey);
		TextureManager::GetInstance()->Add(fileName, L"blank", NULL, colorKey);
	}
};