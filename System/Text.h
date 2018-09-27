#pragma once

struct TextInfo
{
	wstring text;
	Rect* rect; //할당이 되어있다는 전제
	DWORD color;

	TextInfo()
	{
		rect = new Rect();
	}

	~TextInfo()
	{
		SAFE_DELETE(rect);
	}

	TextInfo(const TextInfo& temp)
	{
		*rect = *temp.rect;
		text = temp.text;
		color = temp.color;
	}

	TextInfo& operator =(const TextInfo& temp)
	{
		if (this == &temp)
			return *this;

		text = temp.text;
		color = temp.color;
		*rect = *temp.rect;
		return *this;
	}
};

class Text
{
public:
	static Text* GetInstance();
	static void DeleteInstance();

	void Add(wstring text, Rect* rect, DWORD color = 0xff000000);
	void Remove(int index);
	void Get(int index, TextInfo* textinfo) const;
	void Set(int index, const TextInfo* textInfo);

	void Render();

private:
	Text();
	~Text();

	static Text* instance;

	LPD3DXFONT font;
	vector<TextInfo *> texts;
};