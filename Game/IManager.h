#pragma once

class IManager //State ������ ��� �Ŵ����� �θ�
{
public:
	IManager();
	virtual ~IManager();

	bool GetIsOperate() const { return isOperate; }
	void SetIsOperate(bool a) { isOperate = a; }
protected:
	bool isOperate;
};