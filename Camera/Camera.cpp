#include "../stdafx.h"
#include "Camera.h"

Camera::Camera(Point start)
	:location(start)
{
	D3DXMatrixIdentity(&view);
	DEVICE()->SetRenderState(D3DRS_LIGHTING, FALSE); //cpu���� ����, �ӵ� ������ ����Ƽ ���� �Ⱦ�
	
	Projection();
}

Camera::~Camera()
{
}

void Camera::Projection()
{
	D3DXMatrixIdentity(&projection);
	D3DVIEWPORT9 viewport;
	DEVICE()->GetViewport(&viewport);
	D3DXMatrixOrthoOffCenterLH
	(
		&projection, 0, (float)viewport.Width, (float)viewport.Height, 0, -100.0f, 100.0f
	); //z���� -100 ~ 100�� ����� ������ �ȵ�
	DEVICE()->SetTransform(D3DTS_PROJECTION, &projection);
}

void Camera::Update()
{
	Point temp = location * -1.f;
	D3DXMatrixTranslation(&view, temp.x, temp.y, 0.f);
	DEVICE()->SetTransform(D3DTS_VIEW, &view);
}