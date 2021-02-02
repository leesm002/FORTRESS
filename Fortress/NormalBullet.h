#pragma once
#include "Bullet_Bridge.h"

class NormalBullet 
	: public Bullet_Bridge
{

private:
	float ftime;
public:
	virtual void Initialize(void);
	virtual void Progress(Transform& _tTransPos);
	virtual void Render(HDC _hdc);
	virtual void Release(void);
public:
	NormalBullet();
	virtual ~NormalBullet();
};

