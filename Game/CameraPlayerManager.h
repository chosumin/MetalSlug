#pragma once
#include "IManager.h"
class Character;
class Camera;
class BackgroundManager;
class MonsterManager;
class CameraPlayerManager : public IManager//�÷��̾��� ��ġ�� ���� �������� ������
{
public:
	static CameraPlayerManager* GetInstance();
	void DeleteInstance();

	void Update(Character* character, Camera* camera, BackgroundManager* back, MonsterManager* monsters);
	
	bool GetIsHold() const { return isHold; }
	void SetIsHold(bool a) { isHold = a; }
private:
	void DefaultMove(Character* character, Camera* camera, BackgroundManager* back);
	void UpMove(Character* character, Camera* camera, BackgroundManager* back);
	void DownMove(Character* character, Camera* camera, BackgroundManager* back);
	void BossMove(Character* character, Camera* camera, BackgroundManager* back);
	void BulletDelete(Character* character, Camera* camera, MonsterManager* monsters);
	CameraPlayerManager();
	~CameraPlayerManager();
	static CameraPlayerManager* instance;

	bool isHold;
};