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
	TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
		_tTransPos.Position.fX,	// ������ ���� ������ X
		_tTransPos.Position.fY, 	// ������ ���� ������ Y
		_tTransPos.Scale.fX,	// ������ ���� ���κ� X
		_tTransPos.Scale.fY, 	// ������ ���� ���κ� Y
		(*BitmapManager::GetInstance()->GetImageList())["NormalBullet"]->GetMemDC(),	// ������ �̹��� (������)
		0,  // ������ ������ X
		0,	// ������ ������ Y
		BULLET_SCALE_X, 			// ����� �̹����� ũ�� ��ŭ X
		BULLET_SCALE_Y,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������ ����
}

void NormalBullet::Release(void)
{
	
}