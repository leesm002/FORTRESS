#pragma once
#include "Object.h"
#include "BitmapManager.h"

class Monster : public Object
{
private:
	bool isLeft;	//���ʺ��������� true �����ʺ��������� false
	bool isCharging;
	bool isShoot;
	int iframe;
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;

public:
	Monster();
	virtual ~Monster();
};

