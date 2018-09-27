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
		, CW_USEDEFAULT //ũ�⸦ ������ �⺻������ ����Ѵ�
		, NULL
		, NULL
		, instance
		, NULL
	);
	assert(winHandle != NULL);

	RECT rect = { 0,0,WIN_WIDTH, WIN_HEIGHT };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE); //false �޴��� �������� �ʴ´�.
	//rect�� ������ ũ�⸦ ���Ѵ�.
	MoveWindow
	(
		winHandle, WIN_X, 0, rect.right - rect.left, rect.bottom - rect.top
		, TRUE //true ������ �� �ٽ� �׸���.
	);

	ShowWindow(winHandle, SW_SHOWNORMAL);
	ShowCursor(WIN_SHOW_CURSOR);
}

WPARAM Window::Run() //������۸��� dx���� �˾Ƽ� ����
{
	MSG msg = { 0, };

	Direct2D::Create(winHandle); //������ �ڵ��� �Ű������� ��
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
			Render(); //window�� ��ӹ��� gamemain���� d3d��ü �����ؼ� ����� ���� render
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