#include "NormalBullet.h"
#include "Object.h"

NormalBullet::NormalBullet()
{

}

NormalBullet::~NormalBullet()
{
	Release();
}


void NormalBullet::Initialize(void)
{
	m_fSpeed = m_fAngle * 0.2f;
	ftime = 0.05f;
}

void NormalBullet::Progress(Transform & _tTransPos)
{
	
	_tTransPos.Position.fX += cosf(m_fAngle *  PI / 180) * m_fSpeed;
	_tTransPos.Position.fY += -(sinf(m_fAngle * PI / 180) * m_fSpeed) + (9.8f * ftime);

	ftime += 0.005f;
}

void NormalBullet::Render(HDC _hdc)
{
	/*
	Ellipse(_hdc,
		int(m_pObject->GetPosition().fX - (m_pObject->GetScale().fX / 2)),
		int(m_pObject->GetPosition().fY - (m_pObject->GetScale().fY / 2)),
		int(m_pObject->GetPosition().fX + (m_pObject->GetScale().fX / 2)),
		int(m_pObject->GetPosition().fY + (m_pObject->GetScale().fY / 2)));
	*/
}

void NormalBullet::Release(void)
{
	
}