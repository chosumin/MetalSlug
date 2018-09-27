#include "../stdafx.h"
#include "TextureManager.h"

TextureManager* TextureManager::instance = NULL;

TextureManager * TextureManager::GetInstance()
{
	if (instance == NULL)
		instance = new TextureManager();

	return instance;
}

void TextureManager::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void TextureManager::Load(wstring fileName, DWORD colorKey)
{
	if (srcMap.count(fileName) > 0)
		return;

	LPDIRECT3DTEXTURE9 texture;
	HRESULT hr = D3DXCreateTextureFromFileEx
		(
		DEVICE()
		, fileName.c_str()
		, D3DX_DEFAULT_NONPOW2 //width
		, D3DX_DEFAULT_NONPOW2 //height
		, 1
		, NULL
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, D3DX_FILTER_NONE
		, D3DX_FILTER_NONE
		, colorKey
		, NULL
		, NULL
		, &texture
		);
	assert(SUCCEEDED(hr));

	srcMap[fileName] = texture;
}

LPDIRECT3DTEXTURE9 TextureManager::Add(wstring fileName, wstring keyName, const Rect * srcRect, DWORD colorKey)
{
	bool isCheck = destMap.count(keyName) < 1;
	assert(isCheck);

	Load(fileName, colorKey);

	if (srcRect == NULL)
	{
		destMap[keyName] = srcMap[fileName];

		return destMap[keyName];
	}


	LPDIRECT3DTEXTURE9 texture = srcMap[fileName];

	D3DSURFACE_DESC desc;
	texture->GetLevelDesc(0, &desc);

	Rect area = *srcRect;


	LPDIRECT3DTEXTURE9 destTexture;
	HRESULT hr = D3DXCreateTexture
		(
		DEVICE(), (UINT)area.size.width, (UINT)area.size.height,
		1, 0, desc.Format, D3DPOOL_MANAGED, &destTexture
		);
	assert(SUCCEEDED(hr));


	D3DSURFACE_DESC desc2;
	destTexture->GetLevelDesc(0, &desc2);

	D3DLOCKED_RECT rect;
	D3DLOCKED_RECT rect2;

	RECT tempArea;
	area.GetRECT(&tempArea);

	texture->LockRect(0, &rect, &tempArea, D3DLOCK_DISCARD);
	destTexture->LockRect(0, &rect2, NULL, D3DLOCK_DISCARD);

	DWORD* color = (DWORD *)rect.pBits;
	DWORD* color2 = (DWORD *)rect2.pBits;
	for (UINT y = 0; y < area.size.height; y++)
	{
		for (UINT x = 0; x < area.size.width; x++)
		{
			UINT index = y * rect.Pitch / 4 + x;
			UINT index2 = y * rect2.Pitch / 4 + x;

			color2[index2] = color[index];
		}
	}
	texture->UnlockRect(0);
	destTexture->UnlockRect(0);

	destMap[keyName] = destTexture;

	return destTexture;
}

LPDIRECT3DTEXTURE9 TextureManager::Get(wstring keyName)
{
	if (destMap.find(keyName) != destMap.end())
		return destMap[keyName];

	return NULL;
}

Size TextureManager::GetSize(wstring keyName)
{
	LPDIRECT3DTEXTURE9 texture = Get(keyName);
	assert(texture != NULL);

	D3DSURFACE_DESC desc;
	texture->GetLevelDesc(0, &desc);

	return Size((float)desc.Width, (float)desc.Height);
}

bool TextureManager::IsSrcExist(wstring fileName)
{
	return srcMap.count(fileName) > 0;
}

bool TextureManager::IsDestExist(wstring keyName)
{
	return destMap.count(keyName) > 0;
}

void TextureManager::DeleteSrcTexture(wstring fileName)
{
	if (IsSrcExist(fileName) == true)
	{
		LPDIRECT3DTEXTURE9 texture = srcMap[fileName];
		SAFE_RELEASE(texture);

		srcMap.erase(fileName);
	}
}

void TextureManager::DeleteDestTexture(wstring keyName)
{
	if (IsDestExist(keyName) == true)
	{
		LPDIRECT3DTEXTURE9 texture = destMap[keyName];
		SAFE_RELEASE(texture);

		destMap.erase(keyName);
	}
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	map<wstring, LPDIRECT3DTEXTURE9>::iterator itor;

	for (itor = destMap.begin(); itor != destMap.end(); itor++)
		SAFE_RELEASE(itor->second);
}
