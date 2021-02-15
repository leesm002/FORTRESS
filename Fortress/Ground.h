#pragma once
#include "Object.h"
#include "ObjectManager.h"

class Ground : public Object
{

public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;

public:
	void GetPixel(HDC _hdc, int _x, int _y);

public:
	Ground();
	virtual ~Ground();
};

