#pragma once
#include "Scene.h"
#include "ObjectFactory.h"
#include "Player.h"
#include "Monster.h"

class Stage : public Scene
{
private:
	//stage 배경 움직이기 위한 x값 변수
	int iBG_fx;	

protected:
	Object* pPlayer = ObjectFactory<Player>::CreateObject(WINSIZEX / 4, WINSIZEY - PLAYER_RADIUS);
	Object* pMonster = ObjectFactory<Monster>::CreateObject((WINSIZEX * 3) / 4, WINSIZEY - PLAYER_RADIUS);
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;
public:
	Stage();
	virtual ~Stage();
};

