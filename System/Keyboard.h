#pragma once

#define MAX_INPUT_KEY 255
#define MAX_INPUT_MOUSE 8

class Keyboard
{
public:
	static Keyboard* GetInstance(); //�̱��� ��ü ��ȯ
	static void DeleteInstance();

	void Update();

	bool KeyDown(DWORD key) { return keyMap[key] == KEY_INPUT_STATUS_DOWN; }
	bool KeyUp(DWORD key) { return keyMap[key] == KEY_INPUT_STATUS_UP; }
	bool KeyPress(DWORD key) { return keyMap[key] == KEY_INPUT_STATUS_PRESS; }

private:
	Keyboard();
	~Keyboard();

	static Keyboard* instance;//���α׷� ������ �ϳ��� ��ü�� ����

	byte keyState[MAX_INPUT_KEY]; //256������ Ű �迭
	byte keyOldState[MAX_INPUT_KEY];
	byte keyMap[MAX_INPUT_KEY];

	enum 
	{ 
		KEY_INPUT_STATUS_NONE = 0, 
		KEY_INPUT_STATUS_DOWN, 
		KEY_INPUT_STATUS_UP, 
		KEY_INPUT_STATUS_PRESS,
	};
};