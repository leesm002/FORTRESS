#include "Player.h"
#include "Bullet.h"

#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bitmap.h"
#include "NormalBullet.h"
#include "BitmapManager.h"
#include "SoundManager.h"


Player::Player()
{

}

Player::~Player()
{
	Release();
}


void Player::Initialize(void)
{
	isLeft = true;
	isShoot = false;
	isCharging = false;

	iframe = 22;
	chargingCount = 0;

	m_ptMouse = { 0, 0 };
	m_tTransPos.Position = Vector3(WINSIZEX / 2, WINSIZEY - PLAYER_RADIUS);
	m_tTransPos.Rotation = Vector3(0.f, 0.f, 0.f);
	m_tTransPos.Scale = Vector3(PLAYER_SCALE, PLAYER_SCALE);

	m_tFrame = Frame(0, 0, iframe, 0, 150);

	/*
	Frame(int _StartFrame, 출력을 시작할 이미지 시작점.
	int _Count,				시작점부터 끝지점까지 순차적으로 출력지점을 이동시켜줌
	int _LastFrame,			출력할 이미지의 마지막 지점
	int _SceneFrame,		점프, 이동, 공경 등의 장면을 변경 시킴
	DWORD _FrameTime)		
	
	DWORD _FrameTime = 	장면마다 출력해야할 이미지 개수가 다르다.
		수량에 비례하여 출력되기 때문에
		애니매이션이 끝나는 지점을 맞춰주기 위함.

		몬스터의 공격프 이미지가 5장이고 
		플레이어의 공격 이미지가 10 장이라 한다면 
		우리가 출력하는 이미지는 매 프레임마다 1장의 이미지가 출력되기 때문에 
		몬스터가 2번의 공격을 할때 플레이어는 한번의 공격을 하게된다. 

		이런 문제를 해결하기위해 이미지 전체가 출력되는 시간을 정해놓고 출력해야 한다. (초당 공격력으로 환산된다.)
	*/
	
	m_TargetPoint = Vector3(0.f, 0.f, 0.f);
	m_Direction = Vector3(0.f, 0.f, 0.f);

	m_fAngle = 0.f;
	m_fSpeed = 10.f;
	m_strKey = "Player";
	m_bMove = false;
	

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

int Player::Progress(void)
{
	
	CheckKey();

	m_LinePoint.fX = m_tTransPos.Position.fX + cosf(m_fAngle * PI / 180) * 100;
	m_LinePoint.fY = m_tTransPos.Position.fY + -sinf(m_fAngle * PI / 180) * 100;

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

void Player::Render(HDC _hdc)
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
	
	ObjectManager::GetInstance()->Render(_hdc);
}

void Player::Release(void)
{

}

void Player::CheckKey()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (KEY_UP & dwKey)
	{

		//** 해당하는 각도에 의해 전진
		/*
		m_tTransPos.Position.fX +=cosf(m_fAngle *  PI / 180) * m_fSpeed;
		m_tTransPos.Position.fY +=-sinf(m_fAngle *  PI / 180) * m_fSpeed;
		*/
	}

	if (KEY_DOWN & dwKey)
	{
		// m_tTransPos.Position.fY += m_fSpeed;


		//** 해당하는 각도에 의해 후진
		/*
		m_tTransPos.Position.fX -= cosf(m_fAngle *  PI / 180) * m_fSpeed;
		m_tTransPos.Position.fY -= -sinf(m_fAngle *  PI / 180) * m_fSpeed;
		*/
	}

	if (KEY_LEFT & dwKey)
	{
		m_tTransPos.Position.fX -= m_fSpeed;
		isLeft = true;
	}
	if (KEY_RIGHT & dwKey)
	{
		m_tTransPos.Position.fX += m_fSpeed;
		isLeft = false;
	}

	if (KEY_SPACE & dwKey)
	{
		isCharging = true;
		m_fAngle++;
	}
	else
	{
		if (isCharging)
		{
			Object* pObj = CreateBullet<NormalBullet>();
			pObj->SetAngle(m_fAngle);

			ObjectManager::GetInstance()->AddObject(pObj->GetKey(), pObj);

			isShoot = true;
			isCharging = false;
			m_fAngle = 0;

		}
	}

	if (KEY_RBUTTON & dwKey)
	{
		//** 마우스 우클릭 이벤트가 발생하면 플레이어를 움직이게 하기 위함.
		m_bMove = true;

		//** 마우스 좌표를 받아옴.
		GetCursorPos(&m_ptMouse);
		ScreenToClient(g_hWnd, &m_ptMouse);

		//** 마우스 위치에서 플레이어의 위치를 빼 삼각함수의 폭과 높이를 구함.
		m_Direction.fX = m_ptMouse.x - m_tTransPos.Position.fX;
		m_Direction.fY = m_ptMouse.y - m_tTransPos.Position.fY;

		m_TargetPoint = Vector3((float)m_ptMouse.x, (float)m_ptMouse.y);
	}

	//** 마우스 좌클릭 이벤트가 발생하면 폭발하는 이벤트 제작 예정.
	if (KEY_LBUTTON & dwKey)
	{
		//SoundManager::GetInstance()->OnPlaySound("bleeps", SOUND_CHANNEL_ID_EFFECT);

		//** 마우스 좌표를 받아옴.
		GetCursorPos(&m_ptMouse);
		ScreenToClient(g_hWnd, &m_ptMouse);
	}
}


template <typename T>
Object* Player::CreateBullet()
{
	Bridge* Bridge = new T;

	((Bullet_Bridge*)Bridge)->SetAngle(m_fAngle);

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(m_LinePoint.fX, m_LinePoint.fY, Bridge);

	return pBullet;
}
