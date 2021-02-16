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

	m_tTransPos.Position = Vector3((WINSIZEX * 3) / 4, WINSIZEY - PLAYER_RADIUS);
	m_tTransPos.Rotation = Vector3(0.f, 0.f, 0.f);
	m_tTransPos.Scale = Vector3(PLAYER_SCALE, PLAYER_SCALE);

	m_fAngle = 0.f;
	m_strKey = "Monster";

	isLeft = true;
	isShoot = false;
	isCharging = false;

	iframe = 22;


	//** ��� �������� ������ �ð�.
	m_dwFrameTime = GetTickCount64();

	m_pImageList = BitmapManager::GetInstance()->GetImageList();

	m_pImageList->insert(make_pair("PlayerStandL", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/StandL.bmp")));
	m_pImageList->insert(make_pair("PlayerStandR", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/StandR.bmp")));

	m_pImageList->insert(make_pair("PlayerChargingL", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/ChargingL.bmp")));
	m_pImageList->insert(make_pair("PlayerChargingR", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/ChargingR.bmp")));

	m_pImageList->insert(make_pair("PlayerDamagedL", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/DamagedL.bmp")));
	m_pImageList->insert(make_pair("PlayerDamagedR", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/DamagedR.bmp")));

	m_pImageList->insert(make_pair("PlayerLaunchedL", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/LaunchedL.bmp")));
	m_pImageList->insert(make_pair("PlayerLaunchedR", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/LaunchedR.bmp")));

	m_pImageList->insert(make_pair("PlayerVictoryL", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/VictoryL.bmp")));
	m_pImageList->insert(make_pair("PlayerVictoryR", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player/VictoryR.bmp")));
}

int Monster::Progress(void)
{
	m_rc = { (long)m_tTransPos.Position.fX - 20,
			(long)m_tTransPos.Position.fY - 2,
			(long)m_tTransPos.Position.fX + 20,
			(long)m_tTransPos.Position.fY + 2 };

	if (isLeft && !isCharging && !isShoot)
		iframe = 22;
	else if (!isLeft && !isCharging && !isShoot)
		iframe = 22;
	else if (isLeft && isCharging && !isShoot)
		iframe = 3;
	else if (!isLeft && isCharging && !isShoot)
		iframe = 3;
	else if (isLeft && isShoot)
		iframe = 6;
	else if (!isLeft && isShoot)
		iframe = 6;

	if (isShoot)
	{
		if (m_tFrame.Count >= iframe)
		{
			isShoot = false;

			return 0;
		}

	}

	//** ��� �������� ������ �ð��� �����Ӱ� ������ ������ �ð��� ���Ѱ����� ���� �ð��� �� ũ�ٸ�
	if (m_dwFrameTime + m_tFrame.FrameTime < GetTickCount64())
	{
		m_dwFrameTime = GetTickCount64();

		//** ���� ������ ī��Ʈ�� ������ �̹��� �����Ӻ��� ū�� Ȯ���Ѵ�.
		if (m_tFrame.Count >= iframe)
		{
			//** ũ�ٸ� �ٽ� �ʱ� �̹��� ������ �ǵ��� ����ϰ� �Ѵ�.
			m_tFrame.Count = m_tFrame.StartFrame;
		}
		else
			m_tFrame.Count++;	//** ���� ���ٸ���� �̹����� ����ϰ� �Ѵ�.
	}

	return 0;
}

void Monster::Render(HDC _hdc)
{
	if (isLeft && !isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// ������ ���� ������ X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// ������ ���� ������ Y
			PLAYER_SCALE,	// ������ ���� ���κ� X
			PLAYER_SCALE, 	// ������ ���� ���κ� Y
			(*m_pImageList)["PlayerStandL"]->GetMemDC(),	// ������ �̹��� (������)
			PLAYER_SCALE * m_tFrame.Count,  // ������ ������ X
			0,	// ������ ������ Y
			PLAYER_SCALE, 			// ����� �̹����� ũ�� ��ŭ X
			PLAYER_SCALE,			// ����� �̹����� ũ�� ��ŭ Y
			RGB(255, 0, 255));		// �ش� ������ ����
	}
	else if (!isLeft && !isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// ������ ���� ������ X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// ������ ���� ������ Y
			PLAYER_SCALE,	// ������ ���� ���κ� X
			PLAYER_SCALE, 	// ������ ���� ���κ� Y
			(*m_pImageList)["PlayerStandR"]->GetMemDC(),	// ������ �̹��� (������)
			PLAYER_SCALE * m_tFrame.Count,  // ������ ������ X
			0,	// ������ ������ Y
			PLAYER_SCALE, 			// ����� �̹����� ũ�� ��ŭ X
			PLAYER_SCALE,			// ����� �̹����� ũ�� ��ŭ Y
			RGB(255, 0, 255));		// �ش� ������ ����
	}
	else if (isLeft && isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// ������ ���� ������ X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// ������ ���� ������ Y
			PLAYER_SCALE,	// ������ ���� ���κ� X
			PLAYER_SCALE, 	// ������ ���� ���κ� Y
			(*m_pImageList)["PlayerChargingL"]->GetMemDC(),	// ������ �̹��� (������)
			PLAYER_SCALE * m_tFrame.Count,  // ������ ������ X
			0,	// ������ ������ Y
			PLAYER_SCALE, 			// ����� �̹����� ũ�� ��ŭ X
			PLAYER_SCALE,			// ����� �̹����� ũ�� ��ŭ Y
			RGB(255, 0, 255));		// �ش� ������ ����
	}
	else if (!isLeft && isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// ������ ���� ������ X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// ������ ���� ������ Y
			PLAYER_SCALE,	// ������ ���� ���κ� X
			PLAYER_SCALE, 	// ������ ���� ���κ� Y
			(*m_pImageList)["PlayerChargingR"]->GetMemDC(),	// ������ �̹��� (������)
			PLAYER_SCALE * m_tFrame.Count,  // ������ ������ X
			0,	// ������ ������ Y
			PLAYER_SCALE, 			// ����� �̹����� ũ�� ��ŭ X
			PLAYER_SCALE,			// ����� �̹����� ũ�� ��ŭ Y
			RGB(255, 0, 255));		// �ش� ������ ����
	}
	else if (isLeft && isShoot)
	{
		TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// ������ ���� ������ X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// ������ ���� ������ Y
			PLAYER_SCALE,	// ������ ���� ���κ� X
			PLAYER_SCALE, 	// ������ ���� ���κ� Y
			(*m_pImageList)["PlayerLaunchedL"]->GetMemDC(),	// ������ �̹��� (������)
			PLAYER_SCALE * m_tFrame.Count,  // ������ ������ X
			0,	// ������ ������ Y
			PLAYER_SCALE, 			// ����� �̹����� ũ�� ��ŭ X
			PLAYER_SCALE,			// ����� �̹����� ũ�� ��ŭ Y
			RGB(255, 0, 255));		// �ش� ������ ����


	}
	else if (!isLeft && isShoot)
	{
		TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// ������ ���� ������ X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// ������ ���� ������ Y
			PLAYER_SCALE,	// ������ ���� ���κ� X
			PLAYER_SCALE, 	// ������ ���� ���κ� Y
			(*m_pImageList)["PlayerLaunchedR"]->GetMemDC(),	// ������ �̹��� (������)
			PLAYER_SCALE * m_tFrame.Count,  // ������ ������ X
			0,	// ������ ������ Y
			PLAYER_SCALE, 			// ����� �̹����� ũ�� ��ŭ X
			PLAYER_SCALE,			// ����� �̹����� ũ�� ��ŭ Y
			RGB(255, 0, 255));		// �ش� ������ ����
	}
}

void Monster::Release(void)
{

}

