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
	TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
		(int)m_tTransPos.Position.fX,	// ������ ���� ������ X
		(int)m_tTransPos.Position.fY, // ������ ���� ������ Y
		(int)m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
		(int)m_tTransPos.Scale.fY, 	// ������ ���� ���κ� Y
		(*m_pImageList)[m_strKey]->GetMemDC(),		// ������ �̹��� (������)
		int(m_tFrame.Count * m_tTransPos.Scale.fX),  // ������ ������ X
		int(m_tFrame.Scene * m_tTransPos.Scale.fY),	// ������ ������ Y
		(int)m_tTransPos.Scale.fX, 	// ����� �̹����� ũ�� ��ŭ X
		(int)m_tTransPos.Scale.fY,	// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));			// �ش� ������ ����
}

void Monster::Release(void)
{

}

