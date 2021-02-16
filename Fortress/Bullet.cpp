#include "Bullet.h"

Bullet::Bullet() : m_pBridge(NULL)
{

}

Bullet::~Bullet()
{
	Release();
}


void Bullet::Initialize(void)
{
	m_strKey = "Bullet";

	if (m_pBridge)
		m_pBridge->Initialize(m_tTransPos);
}

int Bullet::Progress(void)
{

	m_rc = { (long)(m_tTransPos.Position.fX - (BULLET_SCALE_X / 2)),
			(long)(m_tTransPos.Position.fY - (BULLET_SCALE_Y / 2)),
			(long)(m_tTransPos.Position.fX),
			(long)(m_tTransPos.Position.fY) };

	DebugMode();

	if (m_pBridge)
		bCheckBoom = m_pBridge->Progress(m_tTransPos, &m_rc);

	return 0;
}

void Bullet::Render(HDC _hdc)
{
	if (isDebugMode && !bCheckBoom)
		Rectangle(_hdc, m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);

	if (m_pBridge)
		m_pBridge->Render(_hdc, m_tTransPos);

	if (bCheckBoom)
		Release();
}

void Bullet::Release(void)
{
	delete m_pBridge;
	m_pBridge = NULL;
}

