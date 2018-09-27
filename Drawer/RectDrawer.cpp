#include "../stdafx.h"
#include "RectDrawer.h"

RectDrawer::RectDrawer(Rect rect, float depth, DWORD color)
	: color(color), rect(rect)
{
	VertexPC* vertex = new VertexPC[6];
	vertex[0] = VertexPC(0, 0, color, depth);
	vertex[1] = VertexPC(rect.size.width, 0, color, depth);
	vertex[2] = VertexPC(0, rect.size.height, color, depth);
	vertex[3] = VertexPC(0, rect.size.height, color, depth);
	vertex[4] = VertexPC(rect.size.width, 0, color, depth);
	vertex[5] = VertexPC(rect.size.width, rect.size.height, color, depth);

	int dataSize = sizeof(VertexPC) * 6;
	SetData(vertex, dataSize, VertexPC::FVF);
}

RectDrawer::~RectDrawer()
{
}

void RectDrawer::Render()
{
	DEVICE()->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DEVICE()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DEVICE()->SetStreamSource(0, vertexBuffer->GetBuffer(), 0, sizeof(VertexPC));
	DEVICE()->SetFVF(VertexPC::FVF);
	DEVICE()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
}
