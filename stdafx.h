#pragma once
#include <Windows.h>
#include <assert.h>
#include <time.h>

#include <string> //wstring »ç¿ë
#include <string.h>
#include <vector>
#include <map>
using namespace std;

#include <d3d9.h>
#include <d3dx9.h>

#define SAFE_RELEASE(p) { if (p) { (p)->Release(); (p)=NULL; } }
#define SAFE_DELETE(p) { if (p) { delete (p); (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p); (p)=NULL; } }

#include "./Math/Size.h"
#include "./Math/Point.h"
#include "./Math/Math.h"
#include "./Polygon/Rect.h"

#include "./System/Direct2D.h"
#include "./System/Keyboard.h"
#include "./System/Mouse.h"
#include "./System/Buffers.h"
#include "./System/Text.h"
#include "./System/Timer.h"

#include "./Managers/TextureManager.h"

#include "./Drawer/Vertex1.h"
#include "./Drawer/RectDrawer.h"
#include "./Drawer/TextureDrawer.h"
#include "./Drawer/Animation.h"

#include "./Game/ImageCuttingManager.h"
#include "./Game/DeadAnimation.h"
#include "./Game/FadeEffect.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")
#define WIN_X 100
#define WIN_Y 100
#define WIN_WIDTH 600
#define WIN_HEIGHT 400
#define WIN_TITLE L"2D GAME"
#define WIN_IS_WINDOW TRUE
#define WIN_SHOW_CURSOR TRUE

#define DEVICE() Direct2D::Device()
#define KEYBOARD() Keyboard::GetInstance()
#define MOUSE() Mouse::GetInstance()
#define TEXTURE() TextureManager::GetInstance()
#define TIMER() Timer::GetInstance()
//ÀüÃ³¸®±â°¡ ¹Ù²ãÁÜ