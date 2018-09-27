#include "../stdafx.h"
#include "Window.h"
#include "../GameMain.h"

Window::Window(HINSTANCE instance)
	:instance(instance), winHandle(NULL)
{
}

Window::~Window()
{
	DestroyWindow(winHandle);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg,
	WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	Mouse::GetInstance()->InputProc(uMsg, wParam, lParam);
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void Window::Create()
{
	WNDCLASS wndClass;
	wndClass.cbClsExtra = NULL;
	wndClass.cbWndExtra = NULL;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = instance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = WIN_TITLE;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	WORD hr = RegisterClass(&wndClass);
	assert(hr != 0);

	winHandle = CreateWindow
	(
		WIN_TITLE
		, WIN_TITLE
		, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, CW_USEDEFAULT //크기를 윈도우 기본값으로 사용한다
		, NULL
		, NULL
		, instance
		, NULL
	);
	assert(winHandle != NULL);

	RECT rect = { 0,0,WIN_WIDTH, WIN_HEIGHT };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE); //false 메뉴를 포함하지 않는다.
	//rect에 윈도우 크기를 더한다.
	MoveWindow
	(
		winHandle, WIN_X, 0, rect.right - rect.left, rect.bottom - rect.top
		, TRUE //true 움직인 후 다시 그린다.
	);

	ShowWindow(winHandle, SW_SHOWNORMAL);
	ShowCursor(WIN_SHOW_CURSOR);
}

WPARAM Window::Run() //더블버퍼링은 dx에서 알아서 해줌
{
	MSG msg = { 0, };

	Direct2D::Create(winHandle); //윈도우 핸들을 매개변수로 줌
	MOUSE()->SetHandle(winHandle);
	Initialize();

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			KEYBOARD()->Update();	
			MOUSE()->Update();
			TIMER()->Update();
			Update();
			Direct2D::BeginScene();
			Render(); //window를 상속받은 gamemain에서 d3d객체 생성해서 사용한 것을 render
			Text::GetInstance()->Render();
			Direct2D::EndScene();
		}
	}

	Destroy();
	Text::DeleteInstance();
	Keyboard::DeleteInstance();
	Mouse::DeleteInstance();
	Timer::DeleteInstance();
	Direct2D::Delete();

	UnregisterClass(WIN_TITLE, instance);
	return msg.wParam;
}

int WINAPI WinMain(HINSTANCE hInstance
	, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam
	, int nCmdShow)
{
	srand((unsigned int)time(NULL));

	GameMain* gameMain = new GameMain(hInstance);
	gameMain->Create();

	WPARAM wParam = gameMain->Run();
	delete gameMain;

	return wParam;
}