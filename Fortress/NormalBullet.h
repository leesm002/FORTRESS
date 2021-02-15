#pragma once
#include "Bullet_Bridge.h"
#include "BitmapManager.h"

class NormalBullet 
	: public Bullet_Bridge
{

private:
	float ftime;
public:
	virtual void Initialize(Transform& _tTransPos);
	virtual void Progress(Transform& _tTransPos);
	virtual void Render(HDC _hdc, Transform& _tTransPos);
	virtual void Release(void);

public:
	NormalBullet();
	virtual ~NormalBullet();
};

