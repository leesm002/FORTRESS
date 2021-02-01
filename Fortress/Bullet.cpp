#include "Bullet.h"
#include "Bridge.h"

Bullet::Bullet() : m_pBridge(NULL)
{

}

Bullet::~Bullet()
{

}


void Bullet::Initialize(void)
{
	m_tTransPos.Position = Vector3(0.f, 0.f);
	m_tTransPos.Rotation = Vector3(0.f, 0.f, 0.f);
	m_tTransPos.Scale = Vector3(30.f, 30.f);

	m_strKey = "Bullet";

	if (m_pBridge)
		m_pBridge->Initialize();
}

int Bullet::Progress(void)
{
	if (m_pBridge)
		m_pBridge->Progress(m_tTransPos);


	return 0;
}

void Bullet::Render(HDC _hdc)
{
	if (m_pBridge)
		m_pBridge->Render(_hdc);
}

void Bullet::Release(void)
{
	delete m_pBridge;
	m_pBridge = NULL;
}

