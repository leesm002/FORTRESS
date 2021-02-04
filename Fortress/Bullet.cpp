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
	
	TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
		m_tTransPos.Position.fX,	// 복사할 영역 시작점 X
		m_tTransPos.Position.fY, 	// 복사할 영역 시작점 Y
		m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		m_tTransPos.Scale.fY, 	// 복사할 영역 끝부분 Y
		(*m_pImageList)["Bullet"]->GetMemDC(),	// 복사할 이미지 (복사대상)
		0,  // 복사할 시작점 X
		0,	// 복사할 시작점 Y
		48, 			// 출력할 이미지의 크기 만큼 X
		84,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));		// 해당 색상을 제외

	if (m_pBridge)
		m_pBridge->Render(_hdc);
}

void Bullet::Release(void)
{
	delete m_pBridge;
	m_pBridge = NULL;
}

