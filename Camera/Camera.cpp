#include "../stdafx.h"
#include "Camera.h"

Camera::Camera(Point start)
	:location(start)
{
	D3DXMatrixIdentity(&view);
	DEVICE()->SetRenderState(D3DRS_LIGHTING, FALSE); //cpu¿¡¼­ ¿¬»ê, ¼Óµµ ´À¸®°í Ä÷¸®Æ¼ ³·¾Æ ¾È¾¸
	
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
	); //zÃàÀÌ -100 ~ 100À» ¹þ¾î³ª¸é ·»´õ¸µ ¾ÈµÊ
	DEVICE()->SetTransform(D3DTS_PROJECTION, &projection);
}

void Camera::Update()
{
	Point temp = location * -1.f;
	D3DXMatrixTranslation(&view, temp.x, temp.y, 0.f);
	DEVICE()->SetTransform(D3DTS_VIEW, &view);
}