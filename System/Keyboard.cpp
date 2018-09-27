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

void Keyboard::Update() //�޼��� ó���ϴ� ������ ȣ��
{
	memcpy(keyOldState, keyState, sizeof(keyOldState));
	//���� Ű ���� ����
	ZeroMemory(keyState, sizeof(keyState));
	//���� ���� 0���� �ʱ�ȭ
	ZeroMemory(keyMap, sizeof(keyMap));
	//Ű�� 0���� �ʱ�ȭ
	
	GetKeyboardState(keyState); //Ű ���� keystate�� ����
	//return bool��
	for (DWORD i = 0; i < MAX_INPUT_KEY; i++)
	{
		byte key = keyState[i] & 0x80;
		keyState[i] = key ? 1 : 0; //���� Ű�� true�� 1, false 0

		int oldState = keyOldState[i];
		int state = keyState[i];

		if (oldState == 0 && state == 1) //Ű ����
			keyMap[i] = KEY_INPUT_STATUS_DOWN; //���� 0, ���� 1 - KeyDown
		else if (oldState == 1 && state == 0) //Ű�� �ô�
			keyMap[i] = KEY_INPUT_STATUS_UP; //���� 1, ���� 0 - KeyUp
		else if (oldState == 1 && state == 1) //��� ������ ����
			keyMap[i] = KEY_INPUT_STATUS_PRESS; //���� 1, ���� 1 - KeyPress
		else //�ƹ��͵� �ƴ�
			keyMap[i] = KEY_INPUT_STATUS_NONE;
	}
}

Keyboard::Keyboard() //Ű���� ���� �ʱ�ȭ
{
	ZeroMemory(keyState, sizeof(keyState));
	ZeroMemory(keyOldState, sizeof(keyOldState));
	ZeroMemory(keyMap, sizeof(keyMap)); //�̰� �ʱ�ȭ�� key_input_status_none�̾�� �� ��Ȯ�ҵ�
}

Keyboard::~Keyboard()
{
	
}
