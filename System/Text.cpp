#include "../stdafx.h"
#include "Text.h"

Text* Text::instance = NULL;
Text * Text::GetInstance()
{
	if (instance == NULL)
		instance = new Text();

	return instance;
}

void Text::DeleteInstance()
{
	SAFE_DELETE(instance);
}

void Text::Add(wstring text, Rect * rect, DWORD color)
{
	TextInfo* info = new TextInfo();
	info->text = text;
	info->color = color;
	memcpy(info->rect, rect, sizeof(Rect));

	texts.push_back(info);
}

void Text::Remove(int index)
{
	if (texts.size() < 1) return;

	SAFE_DELETE(texts[index]);
	texts.erase(texts.begin() + index);
}

void Text::Get(int index, TextInfo * textinfo) const
{
	*textinfo = *texts[index];
}

void Text::Set(int index, const TextInfo * textInfo)
{
	*texts[index] = *textInfo; //대입 연산자
	//대입 연산자도 복사 생성자
}

void Text::Render()
{
	for (size_t i = 0; i < texts.size(); i++)
	{
		RECT rect;
		texts[i]->rect->GetRECT(&rect);

		font->DrawTextW
		(
			NULL,
			texts[i]->text.c_str(),
			-1,
			&rect,
			NULL,
			texts[i]->color
		);
	}
}

Text::Text()
{
	font = NULL;
	HRESULT hr;

	hr = D3DXCreateFont(
		DEVICE(),
		0,
		0,
		FW_NORMAL,
		1,
		FALSE,
		HANGUL_CHARSET,
		OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		FF_DONTCARE,
		L"돋움체",
		&font
	);
	assert(SUCCEEDED(hr));
}

Text::~Text()
{
	for (size_t i = 0; i < texts.size(); i++)
		SAFE_DELETE(texts[i]);

	SAFE_RELEASE(font);
}
