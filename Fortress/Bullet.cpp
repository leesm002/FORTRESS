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
	m_strKey = "Bullet";

	if (m_pBridge)
		m_pBridge->Initialize(m_tTransPos);
}

int Bullet::Progress(void)
{
	if (m_pBridge)
		m_pBridge->Progress(m_tTransPos);


	return 0;
}

void Bullet::Render(HDC _hdc)
{
	/*
	TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
		m_tTransPos.Position.fX,	// ������ ���� ������ X
		m_tTransPos.Position.fY, 	// ������ ���� ������ Y
		m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
		m_tTransPos.Scale.fY, 	// ������ ���� ���κ� Y
		(*m_pImageList)["NormalBullet"]->GetMemDC(),	// ������ �̹��� (������)
		0,  // ������ ������ X
		0,	// ������ ������ Y
		BULLET_SCALE_X, 			// ����� �̹����� ũ�� ��ŭ X
		BULLET_SCALE_Y,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������ ����
	*/

	if (m_pBridge)
		m_pBridge->Render(_hdc, m_tTransPos);
}

void Bullet::Release(void)
{
	delete m_pBridge;
	m_pBridge = NULL;
}

