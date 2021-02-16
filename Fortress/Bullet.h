#pragma once
#include "Object.h"
#include "Bridge.h"

#include "BitmapManager.h"
#include "ObjectManager.h"


class Bridge;
class Bullet : public Object
{
private:
	Bridge* m_pBridge;
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;
public:
	void SetBridge(Bridge* _pBridge) { m_pBridge = _pBridge; }
public:
	Bullet();
	virtual ~Bullet();
};

