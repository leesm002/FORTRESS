#pragma once
#include "Object.h"

class Button : public Object
{
private:
	int m_iScene;
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;
public:
	Button();
	virtual ~Button();
};

