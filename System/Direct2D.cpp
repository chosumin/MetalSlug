#include "../stdafx.h"
#include "Direct2D.h"

LPDIRECT3D9 Direct2D::d3d = NULL;
LPDIRECT3DDEVICE9 Direct2D::device = NULL;

void Direct2D::Create(HWND winHandle)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	assert(d3d != NULL); //true��� �н�
	
	D3DCAPS9 caps; //�ϵ���� ������ �޾ƿ� ����, ���� üũ �뵵
	d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	//D3DADAPTER_DEFAULT �� ����͸� ���
	//D3DDEVTYPE_HAL GPU������ ����ϰ� ��
	//�ָ���Ϳ��� �ϵ���� ������ ������ �ִ����� cap�� �Ѱ���

	//����̽� ���� ����
	D3DPRESENT_PARAMETERS d3dParam = { 0, };
	d3dParam.Windowed = WIN_IS_WINDOW; //true�� ������ ���
	d3dParam.SwapEffect = D3DSWAPEFFECT_DISCARD; //�������, ���۸� ��ȯ�Ҷ� � ȿ���� �ٰ�����
	//discard - ȿ������
	d3dParam.AutoDepthStencilFormat = D3DFMT_D16;
	d3dParam.EnableAutoDepthStencil = TRUE;

	HRESULT hr = d3d->CreateDevice //hal�̸鼭 vertextprocessing�̾�� gpu�� ����Ҽ�����
	(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, winHandle, D3DCREATE_HARDWARE_VERTEXPROCESSING //���̴��� ����Ұ��̳�
		, &d3dParam, &device
	);

	assert(SUCCEEDED(hr));
	//SUCCEEDED - >= 0 �̸� ��ȯ
	//���������� ����ƴ��� ���θ� hresult�� ����
	//-1���ϸ� ���� �ݴ�� ����
}

void Direct2D::Delete() //d3d, d2d ��ü�� release�� ��������
{
	SAFE_RELEASE(device);
	SAFE_RELEASE(d3d);
}

void Direct2D::BeginScene() //0xFF6495ED - ���� ����
{
	device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xFF6495ED, 1.0f, 0);
	device->BeginScene();
}

void Direct2D::EndScene()
{
	device->EndScene();
	device->Present(NULL, NULL, NULL, NULL); //�������� ������
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