#pragma once

#define MAX_INPUT_MOUSE 8 //2진수로 표현하기 위해 8썼나?

class Mouse
{
public:
	void SetHandle(HWND handle)
	{
		this->handle = handle;
	}

	static Mouse* GetInstance();
	static void DeleteInstance();

	void Update();

	LRESULT InputProc(UINT message, WPARAM wParam, LPARAM lParam);

	Point GetPosition() { return position; }

	bool ButtonDown(DWORD button) 
	{ 
		return buttonMap[button] == BUTTON_INPUT_STATUS_DOWN;
	}
	
	bool ButtonUp(DWORD button)
	{ 
		return buttonMap[button] == BUTTON_INPUT_STATUS_UP;
	}

	bool ButtonPress(DWORD button)
	{
		return buttonMap[button] == BUTTON_INPUT_STATUS_PRESS;
	}

private:
	Mouse();
	~Mouse();

	static Mouse* instance;

	HWND handle;
	Point position; //마우스 위치

	byte buttonStatus[MAX_INPUT_MOUSE];
	byte buttonOldStatus[MAX_INPUT_MOUSE];
	byte buttonMap[MAX_INPUT_MOUSE];

	D3DXVECTOR3 wheelStatus; //왜 vector2 안쓰지? z값이 필요한가
	D3DXVECTOR3 wheelOldStatus;
	D3DXVECTOR3 wheelMoveValue;

	DWORD timeDblClk;
	DWORD startDblClk[MAX_INPUT_MOUSE];
	int buttonCount[MAX_INPUT_MOUSE];

	enum 
	{ 
		MOUSE_ROTATION_NONE = 0, 
		MOUSE_ROTATION_LEFT, 
		MOUSE_ROTATION_RIGHT 
	};

	enum 
	{ 
		BUTTON_INPUT_STATUS_NONE = 0,
		BUTTON_INPUT_STATUS_DOWN, 
		BUTTON_INPUT_STATUS_UP, 
		BUTTON_INPUT_STATUS_PRESS, 
		BUTTON_INPUT_STATUS_DBLCLK
	};
};

