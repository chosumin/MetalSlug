#pragma once

class IManager //State 제외한 모든 매니저의 부모
{
public:
	IManager();
	virtual ~IManager();

	bool GetIsOperate() const { return isOperate; }
	void SetIsOperate(bool a) { isOperate = a; }
protected:
	bool isOperate;
};