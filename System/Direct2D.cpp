#include "../stdafx.h"
#include "Direct2D.h"

LPDIRECT3D9 Direct2D::d3d = NULL;
LPDIRECT3DDEVICE9 Direct2D::device = NULL;

void Direct2D::Create(HWND winHandle)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	assert(d3d != NULL); //true라면 패스
	
	D3DCAPS9 caps; //하드웨어 정보를 받아올 변수, 정보 체크 용도
	d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	//D3DADAPTER_DEFAULT 주 모니터를 사용
	//D3DDEVTYPE_HAL GPU연산을 사용하게 함
	//주모니터에서 하드웨어 가속을 받을수 있는지를 cap에 넘겨줌

	//디바이스 설정 정보
	D3DPRESENT_PARAMETERS d3dParam = { 0, };
	d3dParam.Windowed = WIN_IS_WINDOW; //true면 윈도우 모드
	d3dParam.SwapEffect = D3DSWAPEFFECT_DISCARD; //더블버퍼, 버퍼를 교환할때 어떤 효과를 줄것인지
	//discard - 효과없음
	d3dParam.AutoDepthStencilFormat = D3DFMT_D16;
	d3dParam.EnableAutoDepthStencil = TRUE;

	HRESULT hr = d3d->CreateDevice //hal이면서 vertextprocessing이어야 gpu를 사용할수있음
	(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, winHandle, D3DCREATE_HARDWARE_VERTEXPROCESSING //쉐이더를 사용할것이냐
		, &d3dParam, &device
	);

	assert(SUCCEEDED(hr));
	//SUCCEEDED - >= 0 이면 반환
	//정상적으로 수행됐는지 여부를 hresult에 저장
	//-1이하면 실패 반대는 성공
}

void Direct2D::Delete() //d3d, d2d 객체는 release로 지워야함
{
	SAFE_RELEASE(device);
	SAFE_RELEASE(d3d);
}

void Direct2D::BeginScene() //0xFF6495ED - 지울 색상
{
	device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xFF6495ED, 1.0f, 0);
	device->BeginScene();
}

void Direct2D::EndScene()
{
	device->EndScene();
	device->Present(NULL, NULL, NULL, NULL); //전면으로 보내라
}

void Direct2D::SetWorldLocation(Point & location, float depth, Size size, float angle)
{
	D3DXMATRIX world;
	D3DXMatrixIdentity(&world);

	D3DXMatrixTranslation(&world, location.x, location.y, depth);
	DEVICE()->SetTransform(D3DTS_WORLD, &world);
}

void Direct2D::SetWorldRotationLocation(Point& location, float depth, Size size, float angle)
{
	D3DXMATRIX world;
	D3DXMatrixIdentity(&world);

	Point center = Point(size.width / 2, size.height / 2);
	Point point = location - center;
	float radian = Math::DegreeToRadian(angle);

	D3DXMatrixTransformation2D
		(
			&world,
			NULL,
			0,
			NULL,
			&center.ToVector2(),
			radian,
			&point.ToVector2()
		);
	DEVICE()->SetTransform(D3DTS_WORLD, &world);
}