#pragma once

enum AniRepeatType
{
	AniRepeatType_End = 0,
	AniRepeatType_Loop,
	AniRepeatType_Reverse,
};

struct AnimationClip
{
	wstring keyName;
	DWORD time;
	Size size;
};

class Animation
{
public:
	Animation(vector<AnimationClip>* srcClips, bool reverse = false, float depth = 0.0f, AniRepeatType type = AniRepeatType_End, Point center = Point(), Point gunPoint = Point());
	~Animation();

	Size GetSize() const { return clips[curClipNumber].size; }
	int GetClipCount() const { return clips.size(); }
	UINT GetCurCount() const { return curClipNumber; }
	void SetCurCount(UINT a) { curClipNumber = 0; }

	Point GetCenter() const { return center; }
	void SetCenter(const Point a) { center = a; }

	Point GetGunPoint() const { return gunPoint; }
	void SetGunPoint(const Point a) { gunPoint = a; }

	void Play();
	void Stop();

	void Update();
	void Render();

private:
	VertexPT* vertexData;
	VertexBuffer* vertexBuffer;

	vector<AnimationClip> clips;

	AniRepeatType repeatType;
	bool isReverseRight;

	bool isPlay;
	DWORD playTime;

	UINT curClipNumber;

	Point center; //붙어야할곳
	Point gunPoint; //총알 발사 위치
};