#pragma once

class TextureManager
{
public:
	static TextureManager* GetInstance();
	static void DeleteInstance();

	void Load(wstring fileName, DWORD colorKey = 0);

	LPDIRECT3DTEXTURE9 Add
		(
		wstring fileName, wstring keyName
		, const Rect* srcRect = NULL
		, DWORD colorKey = 0x00000000
		);

	LPDIRECT3DTEXTURE9 Get(wstring keyName);
	Size GetSize(wstring keyName);

	bool IsSrcExist(wstring fileName);
	bool IsDestExist(wstring keyName);

	void DeleteSrcTexture(wstring fileName);
	void DeleteDestTexture(wstring keyName);

private:
	static TextureManager* instance;

	TextureManager();
	~TextureManager();

	map<wstring, LPDIRECT3DTEXTURE9> srcMap;
	map<wstring, LPDIRECT3DTEXTURE9> destMap;
};