#pragma once
#include "Include.h"

class Object;
class Bridge
{
protected:
	Object* m_pObject;

public:
	virtual void Initialize(Transform& _tTransPos)PURE;
	virtual bool Progress(Transform& _tTransPos, RECT* _rc)PURE;
	virtual void Render(HDC _hdc, Transform& _tTransPos)PURE;
	virtual void Release()PURE;

public:
	void SetObject(Object* _pObject) { m_pObject = _pObject; }
public:
	Bridge() {};
	virtual ~Bridge() {};
};