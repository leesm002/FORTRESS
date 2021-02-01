#pragma once
#include "Include.h"

class Object;
class Bridge
{
protected:
	Object* m_pObject;

public:
	virtual void Initialize()PURE;
	virtual void Progress(Transform& _tTransPos)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

public:
	void SetObject(Object* _pObject) { m_pObject = _pObject; }
public:
	Bridge() {};
	virtual ~Bridge() {};
};