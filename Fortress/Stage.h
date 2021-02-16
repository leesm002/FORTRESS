#pragma once
#include "Scene.h"
#include "ObjectFactory.h"
#include "Player.h"
#include "Monster.h"
#include "Ground.h"

class Stage : public Scene
{
private:
	//stage ��� �����̱� ���� x�� ����
	int iBG_fx;	

protected:
	Object* pPlayer = ObjectFactory<Player>::CreateObject();
	Object* pMonster = ObjectFactory<Monster>::CreateObject();
	Object* pGround = ObjectFactory<Ground>::CreateObject();

public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;

	void standingObject();
public:
	Stage();
	virtual ~Stage();
};

