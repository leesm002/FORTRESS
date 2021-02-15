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
	TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
		m_tTransPos.Position.fX,	// 복사할 영역 시작점 X
		m_tTransPos.Position.fY, 	// 복사할 영역 시작점 Y
		m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		m_tTransPos.Scale.fY, 	// 복사할 영역 끝부분 Y
		(*m_pImageList)["NormalBullet"]->GetMemDC(),	// 복사할 이미지 (복사대상)
		0,  // 복사할 시작점 X
		0,	// 복사할 시작점 Y
		BULLET_SCALE_X, 			// 출력할 이미지의 크기 만큼 X
		BULLET_SCALE_Y,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));		// 해당 색상을 제외
	*/

	if (m_pBridge)
		m_pBridge->Render(_hdc, m_tTransPos);
}

void Bullet::Release(void)
{
	delete m_pBridge;
	m_pBridge = NULL;
}

