#pragma once

#include "Drawer.h"
class TextureDrawer : public Drawer
{
public:
	TextureDrawer(Size size, wstring keyName, float depth = 0.0f);
	~TextureDrawer();

	void GetSize(Size* size) const
	{
		*size = this->size;
	}
	void SetSize(const Size& size);

	void SetKeyName(const wstring& keyName)
	{
		this->keyName = keyName;
	}

	void Render();

private:
	float depth;
	UINT dataSize;
	Size size;

	wstring keyName;
};