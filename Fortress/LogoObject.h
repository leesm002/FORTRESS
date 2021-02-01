#pragma once
#include "Object.h"

class LogoObject : public Object
{
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;
public:
	LogoObject();
	virtual ~LogoObject();
};

