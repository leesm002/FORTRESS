#include "LogoObject.h"


LogoObject::LogoObject()
{

}

LogoObject::~LogoObject()
{

}


void LogoObject::Initialize(void)
{
	m_tTransPos.Position = Vector3(0, 0);
	m_tTransPos.Rotation = Vector3(0.f, 0.f, 0.f);
	m_tTransPos.Scale = Vector3(1920, 1080);
}

int LogoObject::Progress(void)
{

	return 0;
}

void LogoObject::Render(HDC _hdc)
{
	//** Menu ��׶��� �̹����� ���ۿ� �����.
	TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
		0,	// ������ ���� ������ X
		0, 	// ������ ���� ������ Y
		(int)m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
		(int)m_tTransPos.Scale.fY, 	// ������ ���� ���κ� Y
		(*m_pImageList)[m_strKey]->GetMemDC(),	// ������ �̹��� (������)
		0,		// ������ ������ X
		0,		// ������ ������ Y
		(int)m_tTransPos.Scale.fX, 		// ����� �̹����� ũ�� ��ŭ X
		(int)m_tTransPos.Scale.fY,		// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 255, 255));		// �ش� ������ ����
}

void LogoObject::Release(void)
{

}
