#pragma once

class TextureAddManager
{
public:
	static TextureAddManager* GetInstance();
	void DeleteInstance();

	void Initialize();
private:
	TextureAddManager();
	~TextureAddManager();

	static TextureAddManager* instance;
};