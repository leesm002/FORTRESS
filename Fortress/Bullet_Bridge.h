#pragma once
#include "Bridge.h"

class Bullet_Bridge : public Bridge
{
protected:
	float m_fSpeed;
	float m_fAngle;
public:
	virtual void Initialize(Transform& _tTransPos)PURE;
	virtual void Progress(Transform& _tTransPos)PURE;
	virtual void Render(HDC _hdc, Transform& _tTransPos)PURE;
	virtual void Release(void)PURE;

public:
	void SetAngle(float _Angle) { m_fAngle = _Angle; }
public:
	Bullet_Bridge() {};
	virtual ~Bullet_Bridge() {};
};

