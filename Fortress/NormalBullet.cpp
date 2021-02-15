#include "NormalBullet.h"
#include "Object.h"

NormalBullet::NormalBullet()
{

}

NormalBullet::~NormalBullet()
{
	Release();
}


void NormalBullet::Initialize(Transform& _tTransPos)
{
	_tTransPos.Scale = Vector3(24.f, 42.f);
	
	BitmapManager::GetInstance()->GetImageList()->insert(make_pair("NormalBullet", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Bullet/NormalBullet.bmp")));

	if (m_fAngle <= 90.0f)
	{
		m_fSpeed = m_fAngle * 0.2f;
	}
	if (m_fAngle > 90.0f)
	{
		m_fSpeed = (180.0f - m_fAngle) * 0.2f;
	}
	ftime = 0.05f;
}

void NormalBullet::Progress(Transform & _tTransPos)
{
	_tTransPos.Position.fX += cosf(m_fAngle * PI / 180) * m_fSpeed;
	_tTransPos.Position.fY += -(sinf(m_fAngle * PI / 180) * m_fSpeed) + (9.8f * ftime);
	
	ftime += 0.005f;
}

void NormalBullet::Render(HDC _hdc, Transform& _tTransPos)
{
	TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
		_tTransPos.Position.fX,	// 복사할 영역 시작점 X
		_tTransPos.Position.fY, 	// 복사할 영역 시작점 Y
		_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		_tTransPos.Scale.fY, 	// 복사할 영역 끝부분 Y
		(*BitmapManager::GetInstance()->GetImageList())["NormalBullet"]->GetMemDC(),	// 복사할 이미지 (복사대상)
		0,  // 복사할 시작점 X
		0,	// 복사할 시작점 Y
		BULLET_SCALE_X, 			// 출력할 이미지의 크기 만큼 X
		BULLET_SCALE_Y,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));		// 해당 색상을 제외
}

void NormalBullet::Release(void)
{
	
}