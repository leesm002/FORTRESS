#pragma once
#include "Scene.h"

class Object;
class Logo : public Scene
{
private:
	vector<Object*> m_pButtonList;
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;
public:
	Logo();
	virtual ~Logo();
};

