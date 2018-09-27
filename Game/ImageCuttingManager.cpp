#include "../stdafx.h"
#include "ImageCuttingManager.h"

ImageCuttingManager* ImageCuttingManager::instance = NULL;

ImageCuttingManager * ImageCuttingManager::GetInstance()
{
	if (instance == NULL)
		instance = new ImageCuttingManager();

	return instance;
}

void ImageCuttingManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

//애니메이션 객체에 넣는 메소드
void ImageCuttingManager::CreateAnimation(bool reverse, Animation** target, wstring name, int speed, Size ratio, int repeatTime, Size srcSize, float depth, AniRepeatType type, Point center, Point gunPoint)
{
	vector<AnimationClip> datas;
	for (int i = 0; i < repeatTime; i++)
	{
		AnimationClip data;
		data.keyName = name + to_wstring(i);
		data.time = speed;
		data.size = srcSize * ratio;
		datas.push_back(data);
	}

	gunPoint = gunPoint * ratio;
	center = center * ratio;
	*target = new Animation(&datas, reverse, depth, type, center, gunPoint);
}

//텍스쳐 맵에 추가하는 메소드
void ImageCuttingManager::CreateAnimationInTextureMap(wstring fileName, wstring name, int repeatTime, Point srcLocation, Size srcSize, int interval, DWORD colorKey)
{
	for (int i = 0; i < repeatTime; i++)
	{
		wstring inputName = name + to_wstring(i);
		Rect rect =
			Rect
			(
			srcLocation.x + (interval + srcSize.width) * i,
			srcLocation.y,
			srcSize.width,
			srcSize.height
			);
		TEXTURE()->Add(fileName, inputName, &rect, colorKey);
	}
}

void ImageCuttingManager::CreateAnimationVerticalInTextureMap(wstring fileName, wstring name, int repeatTime, Point srcLocation, Size srcSize, int interval, DWORD colorKey)
{
	for (int i = 0; i < repeatTime; i++)
	{
		wstring inputName = name + to_wstring(i);
		Rect rect =
			Rect
			(
			srcLocation.x,
			srcLocation.y + (interval + srcSize.height) * i,
			srcSize.width,
			srcSize.height
			);
		TEXTURE()->Add(fileName, inputName, &rect, colorKey);
	}
}

void ImageCuttingManager::CreateTexture(TextureDrawer ** target, wstring name, Rect rect, Size ratio, float depth)
{
	rect.size = rect.size * ratio;
	*target = new TextureDrawer(rect.size, name, depth);
}

ImageCuttingManager::ImageCuttingManager()
{
}

ImageCuttingManager::~ImageCuttingManager()
{
}
