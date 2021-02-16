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

	_tTransPos.Scale = Vector3(BULLET_SCALE_X, BULLET_SCALE_Y);

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

	if (!isBoom)
	{
		_tTransPos.Position.fX += cosf(m_fAngle * PI / 180) * m_fSpeed;
		_tTransPos.Position.fY += -(sinf(m_fAngle * PI / 180) * m_fSpeed) + (9.8f * ftime);

		ftime += 0.005f;

	}
	else
	{

	}
	

}

void NormalBullet::Render(HDC _hdc, Transform& _tTransPos)
{
	BitmapManager::GetInstance()->GetImageList();

	if (!isBoom)
	{
		TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
			_tTransPos.Position.fX - (BULLET_SCALE_X / 2),	// ������ ���� ������ X
			_tTransPos.Position.fY - (BULLET_SCALE_Y / 2), 	// ������ ���� ������ Y
			BULLET_SCALE_X / 2,	// ������ ���� ���κ� X
			BULLET_SCALE_Y / 2, 	// ������ ���� ���κ� Y
			(*BitmapManager::GetInstance()->GetImageList())["NormalBullet"]->GetMemDC(),	// ������ �̹��� (������)
			0,  // ������ ������ X
			0,	// ������ ������ Y
			BULLET_SCALE_X, 			// ����� �̹����� ũ�� ��ŭ X
			BULLET_SCALE_Y,			// ����� �̹����� ũ�� ��ŭ Y
			RGB(255, 0, 255));		// �ش� ������ ����
	}
	else
	{
		
		Ellipse(
			(*BitmapManager::GetInstance()->GetImageList())["Ground"]->GetMemDC(),
			_tTransPos.Position.fX - 50,
			_tTransPos.Position.fY - 50,
			_tTransPos.Position.fX + 50,
			_tTransPos.Position.fY + 50);
		
	}

}

void NormalBullet::Release(void)
{
	
}