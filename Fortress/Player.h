#pragma once
#include "Object.h"

class Player : public Object
{
private:
	//** 플레이어 포신 이었던것.
	Vector3 m_LinePoint;

	//** 마우스 클릭 이동
	Vector3 m_Direction;
	Vector3 m_TargetPoint;
	POINT m_ptMouse;
	bool m_bMove;
	bool isLeft;	//왼쪽보고있을때 true 오른쪽보고있을때 false
	bool isCharging;
	bool isShoot;
	bool isExistGround;
	int iframe;

	//** 점프 
	float chargingCount = 0;
public:
	virtual void Initialize(void)override;
	virtual int Progress(void)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release(void)override;
public:
	template <typename T>
	Object* CreateBullet(void);

public:
	void CheckKey();
	void SetMoveFalse() { m_bMove = false; }
public:
	Player();
	virtual ~Player();
};

