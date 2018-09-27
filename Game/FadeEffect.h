#pragma once

class FadeEffect
{
public:
	FadeEffect();
	~FadeEffect();

	void SetFirst();
	bool GetLast();
	void Render();
private:
	
	vector<RectDrawer*> rects;
	int i;
	D3DXCOLOR color;
};

class FadeClass
{
public:
	static FadeClass* GetInstance();
	void DeleteInstance();

	void Add();
	bool GetLast();
	void DeleteEffect();
	void Update();
	void Render();
private:
	FadeClass();
	~FadeClass();

	static FadeClass* instance;

	FadeEffect* effects;
};