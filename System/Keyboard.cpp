#include "../stdafx.h"
#include "Keyboard.h"

Keyboard* Keyboard::instance = NULL;

Keyboard * Keyboard::GetInstance()
{
	if (instance == NULL)
		instance = new Keyboard();

	return instance;
}

void Keyboard::DeleteInstance()
{
	//SAFE_DELETE(instance);

	if (instance != NULL)
		delete instance;
}

void Keyboard::Update() //메세지 처리하는 곳에서 호출
{
	memcpy(keyOldState, keyState, sizeof(keyOldState));
	//이전 키 상태 복사
	ZeroMemory(keyState, sizeof(keyState));
	//현재 상태 0으로 초기화
	ZeroMemory(keyMap, sizeof(keyMap));
	//키맵 0으로 초기화
	
	GetKeyboardState(keyState); //키 값을 keystate에 저장
	//return bool형
	for (DWORD i = 0; i < MAX_INPUT_KEY; i++)
	{
		byte key = keyState[i] & 0x80;
		keyState[i] = key ? 1 : 0; //현재 키가 true면 1, false 0

		int oldState = keyOldState[i];
		int state = keyState[i];

		if (oldState == 0 && state == 1) //키 누름
			keyMap[i] = KEY_INPUT_STATUS_DOWN; //이전 0, 현재 1 - KeyDown
		else if (oldState == 1 && state == 0) //키를 뗐다
			keyMap[i] = KEY_INPUT_STATUS_UP; //이전 1, 현재 0 - KeyUp
		else if (oldState == 1 && state == 1) //계속 누르고 있음
			keyMap[i] = KEY_INPUT_STATUS_PRESS; //이전 1, 현재 1 - KeyPress
		else //아무것도 아님
			keyMap[i] = KEY_INPUT_STATUS_NONE;
	}
}

Keyboard::Keyboard() //키보드 상태 초기화
{
	ZeroMemory(keyState, sizeof(keyState));
	ZeroMemory(keyOldState, sizeof(keyOldState));
	ZeroMemory(keyMap, sizeof(keyMap)); //이거 초기화는 key_input_status_none이어야 더 정확할듯
}

Keyboard::~Keyboard()
{
	
}
