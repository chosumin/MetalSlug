#include "../stdafx.h"
#include "Drawer.h"

Drawer::Drawer()
	: vertexData(NULL), vertexBuffer(NULL)
{
}

Drawer::~Drawer()
{
	SAFE_DELETE_ARRAY(vertexData);
	SAFE_DELETE(vertexBuffer);
}

void Drawer::SetData(Vertex * vertex, UINT dataSize, DWORD fvf)
{
	assert(dataSize > 0);

	this->dataSize = dataSize;
	this->vertexData = (Vertex*)new BYTE[dataSize];
	memcpy(this->vertexData, vertex, dataSize);

	this->fvf = fvf;

	if (vertexBuffer == NULL)
	{
		vertexBuffer = new VertexBuffer();
		vertexBuffer->Create(dataSize, fvf);
		vertexBuffer->CopyData(vertexData);
	}
	else
		vertexBuffer->CopyData(vertex);

}
