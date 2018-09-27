#pragma once

#define MAX_INPUT_KEY 255
#define MAX_INPUT_MOUSE 8

class Keyboard
{
public:
	static Keyboard* GetInstance(); //싱글턴 객체 반환
	static void DeleteInstance();

	void Update();

	bool KeyDown(DWORD key) { return keyMap[key] == KEY_INPUT_STATUS_DOWN; }
	bool KeyUp(DWORD key) { return keyMap[key] == KEY_INPUT_STATUS_UP; }
	bool KeyPress(DWORD key) { return keyMap[key] == KEY_INPUT_STATUS_PRESS; }

private:
	Keyboard();
	~Keyboard();

	static Keyboard* instance;//프로그램 내에서 하나의 객체만 존재

	byte keyState[MAX_INPUT_KEY]; //256가지의 키 배열
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