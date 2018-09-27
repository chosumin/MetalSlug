#pragma once

struct UiTexture
{
	UiTexture()
	{
		wstring fileName = L"./Textures/hud.png";
		DWORD colorKey = 0x0000FF00;
		TextureManager::GetInstance()->Load(fileName, colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Tarma_selectIcon", &Rect(31, 472, 25, 26), colorKey);
		TextureManager::GetInstance()->Add(fileName, L"Tarma_choiceIcon", &Rect(3, 472, 25, 26), colorKey);

		TextureManager::GetInstance()->Add(fileName, L"Fiolina_selectIcon", &Rect(31, 501, 25, 26), colorKey);
		TextureManager::GetInstance()->Add(fileName, L"Fiolina_choiceIcon", &Rect(3, 501, 25, 26), colorKey);
	
		TextureManager::GetInstance()->Add(fileName, L"ArmsIcon", &Rect(4, 272, 31, 8), colorKey);
		TextureManager::GetInstance()->Add(fileName, L"BombsIcon", &Rect(125, 272, 31, 8), colorKey);
	
		for (int i = 0; i < 10; i++)
		{
			TextureManager::GetInstance()->Add(fileName, to_wstring(i), &Rect(4 + (float)i * 16, 247, 16, 16), colorKey);
		}
	}
};