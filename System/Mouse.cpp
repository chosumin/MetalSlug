#include "../stdafx.h"
#include "Mouse.h"

Mouse* Mouse::instance = NULL;

Mouse* Mouse::GetInstance() //싱글턴 객체 생성
{
	if ( instance == NULL )
		instance = new Mouse();

	return instance;
}

void Mouse::DeleteInstance()
{
	SAFE_DELETE(instance);
}

Mouse::Mouse()
{
	position = {0, 0};

	wheelStatus = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	wheelOldStatus = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	wheelMoveValue = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	ZeroMemory(buttonStatus, sizeof(byte) * MAX_INPUT_MOUSE);
	ZeroMemory(buttonOldStatus, sizeof(byte) * MAX_INPUT_MOUSE);
	ZeroMemory(buttonMap, sizeof(byte) * MAX_INPUT_MOUSE);

	ZeroMemory(startDblClk, sizeof(DWORD) * MAX_INPUT_MOUSE);
	ZeroMemory(buttonCount, sizeof(int) * MAX_INPUT_MOUSE);

	timeDblClk = GetDoubleClickTime();
	startDblClk[0] = GetTickCount(); //부팅시부터의 시간 체크

	for ( int i = 1; i < MAX_INPUT_MOUSE; i++ )
		startDblClk[i] = startDblClk[0]; //더블클릭 시간 초기화

	DWORD tLine = 0;
	SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &tLine, 0);
}

Mouse::~Mouse()
{
}

void Mouse::Update()
{
	memcpy(buttonOldStatus, buttonStatus, sizeof(buttonOldStatus));
	//현재 상태와 비교하기 위해 복사

	ZeroMemory(buttonStatus, sizeof(buttonStatus));
	ZeroMemory(buttonMap, sizeof(buttonMap));
	//현재 상태 0으로 초기화

	buttonStatus[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? 1 : 0;
	buttonStatus[1] = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? 1 : 0;
	buttonStatus[2] = GetAsyncKeyState(VK_MBUTTON) & 0x8000 ? 1 : 0;
	//왼쪽, 오른쪽, 휠버튼 상태 체크

	for ( DWORD i = 0; i < MAX_INPUT_MOUSE; i++ )
	{
		int tOldStatus = buttonOldStatus[i];
		int tStatus = buttonStatus[i];

		if ( tOldStatus == 0 && tStatus == 1 ) 
			buttonMap[i] = BUTTON_INPUT_STATUS_DOWN;
		else if ( tOldStatus == 1 && tStatus == 0 ) 
			buttonMap[i] = BUTTON_INPUT_STATUS_UP;
		else if ( tOldStatus == 1 && tStatus == 1 )
			buttonMap[i] = BUTTON_INPUT_STATUS_PRESS;
		else 
			buttonMap[i] = BUTTON_INPUT_STATUS_NONE;
	} //마우스 입력 상태 갱신

	POINT point;
	GetCursorPos(&point);
	ScreenToClient(handle, &point); //마우스 좌표 받아옴

	wheelOldStatus.x = wheelStatus.x;
	wheelOldStatus.y = wheelStatus.y;
	//상태 비교 위해 예전값 저장

	wheelStatus.x = float(point.x);
	wheelStatus.y = float(point.y);
	//현재 좌표값 저장

	wheelMoveValue = wheelStatus - wheelOldStatus;
	wheelOldStatus.z = wheelStatus.z;
	//변위 저장

	DWORD tButtonStatus = GetTickCount(); //현재 시간 할당
	for ( DWORD i = 0; i < MAX_INPUT_MOUSE; i++ )
	{
		if ( buttonMap[i] == BUTTON_INPUT_STATUS_DOWN )
		{ //어떠한 값 상태가 down일때
			if ( buttonCount[i] == 1 )
			{
				if ( (tButtonStatus - startDblClk[i]) >= timeDblClk )
					buttonCount[i] = 0; //더블클릭 시간 초과시 0
			}
			buttonCount[i]++;

			if ( buttonCount[i] == 1 )
				startDblClk[i] = tButtonStatus; //더블클릭 시간 초기화
		}

		if ( buttonMap[i] == BUTTON_INPUT_STATUS_UP )
		{
			if ( buttonCount[i] == 1 )
			{
				if ( (tButtonStatus - startDblClk[i]) >= timeDblClk )
					buttonCount[i] = 0; //더블클릭 x
			}
			else if ( buttonCount[i] == 2 )
			{
				if ( (tButtonStatus - startDblClk[i]) <= timeDblClk )
					buttonMap[i] = BUTTON_INPUT_STATUS_DBLCLK; //더블클릭 했다.

				buttonCount[i] = 0;
			}
		}//if
	}//for(i)
}

LRESULT Mouse::InputProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if ( message == WM_LBUTTONDOWN || message == WM_MOUSEMOVE )
	{
		position.x = LOWORD(lParam);
		position.y = HIWORD(lParam);
	}

	if ( message == WM_MOUSEWHEEL )
	{
		short tWheelValue = (short) HIWORD(wParam);

		wheelOldStatus.z = wheelStatus.z;
		wheelStatus.z += (float) tWheelValue;
	}

	return TRUE;
}
