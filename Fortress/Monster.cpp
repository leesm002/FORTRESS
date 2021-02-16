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


	//** 출력 프레임을 제어할 시간.
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

	//** 출력 프레임을 제어할 시간에 프레임과 프레임 간격의 시간을 더한값보다 현재 시가니 더 크다면
	if (m_dwFrameTime + m_tFrame.FrameTime < GetTickCount64())
	{
		m_dwFrameTime = GetTickCount64();

		//** 현재 프레임 카운트가 마지막 이미지 프레임보다 큰지 확인한다.
		if (m_tFrame.Count >= iframe)
		{
			//** 크다면 다시 초기 이미지 값으로 되돌려 출력하게 한다.
			m_tFrame.Count = m_tFrame.StartFrame;
		}
		else
			m_tFrame.Count++;	//** 별일 없다면다음 이미지를 출력하게 한다.
	}

	return 0;
}

void Monster::Render(HDC _hdc)
{
	if (isLeft && !isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// 복사할 영역 시작점 X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// 복사할 영역 시작점 Y
			PLAYER_SCALE,	// 복사할 영역 끝부분 X
			PLAYER_SCALE, 	// 복사할 영역 끝부분 Y
			(*m_pImageList)["PlayerStandL"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			PLAYER_SCALE * m_tFrame.Count,  // 복사할 시작점 X
			0,	// 복사할 시작점 Y
			PLAYER_SCALE, 			// 출력할 이미지의 크기 만큼 X
			PLAYER_SCALE,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외
	}
	else if (!isLeft && !isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// 복사할 영역 시작점 X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// 복사할 영역 시작점 Y
			PLAYER_SCALE,	// 복사할 영역 끝부분 X
			PLAYER_SCALE, 	// 복사할 영역 끝부분 Y
			(*m_pImageList)["PlayerStandR"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			PLAYER_SCALE * m_tFrame.Count,  // 복사할 시작점 X
			0,	// 복사할 시작점 Y
			PLAYER_SCALE, 			// 출력할 이미지의 크기 만큼 X
			PLAYER_SCALE,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외
	}
	else if (isLeft && isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// 복사할 영역 시작점 X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// 복사할 영역 시작점 Y
			PLAYER_SCALE,	// 복사할 영역 끝부분 X
			PLAYER_SCALE, 	// 복사할 영역 끝부분 Y
			(*m_pImageList)["PlayerChargingL"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			PLAYER_SCALE * m_tFrame.Count,  // 복사할 시작점 X
			0,	// 복사할 시작점 Y
			PLAYER_SCALE, 			// 출력할 이미지의 크기 만큼 X
			PLAYER_SCALE,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외
	}
	else if (!isLeft && isCharging && !isShoot)
	{
		TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// 복사할 영역 시작점 X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// 복사할 영역 시작점 Y
			PLAYER_SCALE,	// 복사할 영역 끝부분 X
			PLAYER_SCALE, 	// 복사할 영역 끝부분 Y
			(*m_pImageList)["PlayerChargingR"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			PLAYER_SCALE * m_tFrame.Count,  // 복사할 시작점 X
			0,	// 복사할 시작점 Y
			PLAYER_SCALE, 			// 출력할 이미지의 크기 만큼 X
			PLAYER_SCALE,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외
	}
	else if (isLeft && isShoot)
	{
		TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// 복사할 영역 시작점 X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// 복사할 영역 시작점 Y
			PLAYER_SCALE,	// 복사할 영역 끝부분 X
			PLAYER_SCALE, 	// 복사할 영역 끝부분 Y
			(*m_pImageList)["PlayerLaunchedL"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			PLAYER_SCALE * m_tFrame.Count,  // 복사할 시작점 X
			0,	// 복사할 시작점 Y
			PLAYER_SCALE, 			// 출력할 이미지의 크기 만큼 X
			PLAYER_SCALE,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외


	}
	else if (!isLeft && isShoot)
	{
		TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
			m_tTransPos.Position.fX - PLAYER_RADIUS,	// 복사할 영역 시작점 X
			m_tTransPos.Position.fY - PLAYER_RADIUS, 	// 복사할 영역 시작점 Y
			PLAYER_SCALE,	// 복사할 영역 끝부분 X
			PLAYER_SCALE, 	// 복사할 영역 끝부분 Y
			(*m_pImageList)["PlayerLaunchedR"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			PLAYER_SCALE * m_tFrame.Count,  // 복사할 시작점 X
			0,	// 복사할 시작점 Y
			PLAYER_SCALE, 			// 출력할 이미지의 크기 만큼 X
			PLAYER_SCALE,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외
	}
}

void Monster::Release(void)
{

}

