#pragma once

class ImageCuttingManager
{
public:
	static ImageCuttingManager* GetInstance();
	static void DeleteInstance();

	void CreateAnimation(bool reverse, Animation** target, wstring name, int speed, Size ratio, int repeatTime, Size srcSize, float depth = 0, AniRepeatType type = AniRepeatType_Loop, Point center = Point(), Point gunPoint = Point());
	void CreateAnimationInTextureMap(wstring fileName, wstring name, int repeatTime, Point srcLocation, Size srcSize, int interval, DWORD colorKey);
	void CreateAnimationVerticalInTextureMap(wstring fileName, wstring name, int repeatTime, Point srcLocation, Size srcSize, int interval, DWORD colorKey);
	void CreateTexture(TextureDrawer** target, wstring name, Rect rect, Size ratio, float depth = 0);

private:
	ImageCuttingManager();
	~ImageCuttingManager();

	static ImageCuttingManager* instance;
};