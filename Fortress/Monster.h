#pragma once
#include "Object.h"
#include "BitmapManager.h"

class Monster : public Object
{
private:
	bool isLeft;	//왼쪽보고있을때 true 오른쪽보고있을때 false
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

