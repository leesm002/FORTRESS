#pragma once
#include "Scene.h"
#include "ObjectFactory.h"
#include "Player.h"

class Stage : public Scene
{
private:
	//stage ��� �����̱� ���� x�� ����
	int iBG_fx;	

protected:
	Object* pPlayer = ObjectFactory<Player>::CreateObject(WINSIZEX / 2, WINSIZEY - PLAYER_RADIUS);
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;
public:
	Stage();
	virtual ~Stage();
};

