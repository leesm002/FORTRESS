#pragma once
#include "Object.h"

class Player : public Object
{
private:
	//** �÷��̾� ���� �̾�����.
	Vector3 m_LinePoint;

	//** ���콺 Ŭ�� �̵�
	Vector3 m_Direction;
	Vector3 m_TargetPoint;
	POINT m_ptMouse;
	bool m_bMove;
	bool isLeft;	//���ʺ��������� true �����ʺ��������� false
	bool isCharging;
	bool isShoot;
	bool isExistGround;
	int iframe;

	//** ���� 
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

