#pragma once
#include "Bullet_Bridge.h"
#include "BitmapManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "Ground.h"
#include "ObjectFactory.h"

class NormalBullet 
	: public Bullet_Bridge
{

private:
	float ftime;
	Object* pGround = ObjectFactory<Ground>::CreateObject();
public:
	virtual void Initialize(Transform& _tTransPos);
	virtual bool Progress(Transform& _tTransPos, RECT* _rc);
	virtual void Render(HDC _hdc, Transform& _tTransPos);
	virtual void Release(void);

public:
	NormalBullet();
	virtual ~NormalBullet();
};

