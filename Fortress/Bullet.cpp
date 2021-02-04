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
	m_tTransPos.Scale = Vector3(24.f, 42.f);

	m_strKey = "Bullet";

	m_pImageList = BitmapManager::GetInstance()->GetImageList();

	m_pImageList->insert(make_pair("Bullet", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Bullet/Bullet.bmp")));

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
	
	TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
		m_tTransPos.Position.fX,	// ������ ���� ������ X
		m_tTransPos.Position.fY, 	// ������ ���� ������ Y
		m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
		m_tTransPos.Scale.fY, 	// ������ ���� ���κ� Y
		(*m_pImageList)["Bullet"]->GetMemDC(),	// ������ �̹��� (������)
		0,  // ������ ������ X
		0,	// ������ ������ Y
		48, 			// ����� �̹����� ũ�� ��ŭ X
		84,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������ ����

	if (m_pBridge)
		m_pBridge->Render(_hdc);
}

void Bullet::Release(void)
{
	delete m_pBridge;
	m_pBridge = NULL;
}

