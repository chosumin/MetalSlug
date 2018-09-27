#include "../stdafx.h"
#include "Vertex1.h"

DWORD VertexPC::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
DWORD VertexPT::FVF = D3DFVF_XYZ | D3DFVF_TEX1; //텍스쳐 한개 사용