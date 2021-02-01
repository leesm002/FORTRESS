#include "Monster.h"

Monster::Monster()
{

}

Monster::~Monster()
{
	
}


void Monster::Initialize(void)
{
	m_tFrame = Frame(0, 0, 1, 0, 150);

	m_tTransPos.Position = Vector3(0, 0);
	m_tTransPos.Rotation = Vector3(0.f, 0.f, 0.f);
	m_tTransPos.Scale = Vector3(160.f, 160.f);

	m_fAngle = 0.f;
	m_strKey = "Monster";
}

int Monster::Progress(void)
{
	return 0;
}

void Monster::Render(HDC _hdc)
{
	TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
		(int)m_tTransPos.Position.fX,	// 복사할 영역 시작점 X
		(int)m_tTransPos.Position.fY, // 복사할 영역 시작점 Y
		(int)m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		(int)m_tTransPos.Scale.fY, 	// 복사할 영역 끝부분 Y
		(*m_pImageList)[m_strKey]->GetMemDC(),		// 복사할 이미지 (복사대상)
		int(m_tFrame.Count * m_tTransPos.Scale.fX),  // 복사할 시작점 X
		int(m_tFrame.Scene * m_tTransPos.Scale.fY),	// 복사할 시작점 Y
		(int)m_tTransPos.Scale.fX, 	// 출력할 이미지의 크기 만큼 X
		(int)m_tTransPos.Scale.fY,	// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));			// 해당 색상을 제외
}

void Monster::Release(void)
{

}

