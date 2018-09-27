#include "../stdafx.h"
#include "Animation.h"

Animation::Animation(vector<AnimationClip>* srcClips, bool reverse, float depth, AniRepeatType type, Point center, Point gunPoint)
	: isPlay(false), playTime(0)
	, curClipNumber(0)
	, repeatType(type), isReverseRight(true), center(center), gunPoint(gunPoint)
{
	int count = 0;

	vertexData = new VertexPT[srcClips->size() * 6];
	for (size_t i = 0; i < srcClips->size(); i++)
	{
		AnimationClip clip = srcClips->at(i);
		Size size = TEXTURE()->GetSize(clip.keyName);

		if (clip.size.width == 0.0f)
			clip.size.width = size.width;

		if (clip.size.height == 0.0f)
			clip.size.height = size.height;

		if (reverse)
		{
			vertexData[count++] = VertexPT(0, 0, 1, 0, depth); //0
			vertexData[count++] = VertexPT(clip.size.width, 0, 0, 0, depth); //1
			vertexData[count++] = VertexPT(0, clip.size.height, 1, 1, depth); //2
			vertexData[count++] = VertexPT(0, clip.size.height, 1, 1, depth); //2
			vertexData[count++] = VertexPT(clip.size.width, 0, 0, 0, depth); //1
			vertexData[count++] = VertexPT(clip.size.width, clip.size.height, 0, 1, depth); //3
		}
		else
		{
			vertexData[count++] = VertexPT(0, 0, 0, 0, depth); //0
			vertexData[count++] = VertexPT(clip.size.width, 0, 1, 0, depth); //1
			vertexData[count++] = VertexPT(0, clip.size.height, 0, 1, depth); //2
			vertexData[count++] = VertexPT(0, clip.size.height, 0, 1, depth); //2
			vertexData[count++] = VertexPT(clip.size.width, 0, 1, 0, depth); //1
			vertexData[count++] = VertexPT(clip.size.width, clip.size.height, 1, 1, depth); //3
		}

		clips.push_back(clip);
	}


	UINT dataSize = sizeof(VertexPT) * clips.size() * 6;
	vertexBuffer = new VertexBuffer();
	vertexBuffer->Create(dataSize, VertexPT::FVF);
	vertexBuffer->CopyData(vertexData);

	Play();
}

Animation::~Animation()
{
	SAFE_DELETE_ARRAY(vertexData);
	SAFE_DELETE(vertexBuffer);
}

void Animation::Play()
{
	isPlay = true;

	playTime = timeGetTime();
}

void Animation::Stop()
{
	isPlay = false;
}

void Animation::Update()
{
	AnimationClip clip = clips[curClipNumber];

	if (timeGetTime() - playTime > clip.time)
	{
		switch (repeatType)
		{
			case AniRepeatType_End:
			{
				curClipNumber++;

				if (curClipNumber >= clips.size() - 1)
					curClipNumber = clips.size() - 1;
			}
			break;

			case AniRepeatType_Loop:
			{
				curClipNumber++;
				curClipNumber %= clips.size();
			}
			break;

			case AniRepeatType_Reverse:
			{
				if (isReverseRight == true)
				{
					curClipNumber++;

					if (curClipNumber >= clips.size() - 1)
						isReverseRight = false;
				}
				else
				{
					curClipNumber--;

					if (curClipNumber <= 0)
						isReverseRight = true;
				}
			}
			break;
		}

		playTime = timeGetTime();
	}
}

void Animation::Render()
{
	DEVICE()->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DEVICE()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DEVICE()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	DEVICE()->SetStreamSource(0, vertexBuffer->GetBuffer(), 0, sizeof(VertexPT));
	DEVICE()->SetFVF(VertexPT::FVF);

	wstring clipKeyName = clips[curClipNumber].keyName;
	LPDIRECT3DTEXTURE9 texture = TEXTURE()->Get(clipKeyName);
	DEVICE()->SetTexture(0, texture);

	DEVICE()->DrawPrimitive(D3DPT_TRIANGLELIST, curClipNumber * 6, 2);

	DEVICE()->SetTexture(0, NULL);
	DEVICE()->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}