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

	m_tTransPos.Position = Vector3(WINSIZEX / 2, WINSIZEY - PLAYER_RADIUS);
	m_tTransPos.Rotation = Vector3(0.f, 0.f, 0.f);
	m_tTransPos.Scale = Vector3(PLAYER_SCALE, PLAYER_SCALE);

	m_tFrame = Frame(0, 0, iframe, 0, 150);

	m_TargetPoint = Vector3(0.f, 0.f, 0.f);
	m_Direction = Vector3(0.f, 0.f, 0.f);

	m_fAngle = 0.f;
	m_fSpeed = 5.f;
	m_strKey = "Player";
	

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

int Player::Progress(void)
{

	m_rc = {(long)m_tTransPos.Position.fX - 20,
			(long)m_tTransPos.Position.fY - 2,
			(long)m_tTransPos.Position.fX + 20,
			(long)m_tTransPos.Position.fY + 2};

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

void Player::Render(HDC _hdc)
{
	if (isDebugMode)
		Rectangle(_hdc, m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);

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
	
	ObjectManager::GetInstance()->Render(_hdc);
}

void Player::Release(void)
{

}

void Player::CheckKey()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (KEY_TAB & dwKey)
		isDebugMode = true;
	else
		isDebugMode = false;

	if (KEY_UP & dwKey)
	{

		//** �ش��ϴ� ������ ���� ����
		/*
		m_tTransPos.Position.fX +=cosf(m_fAngle *  PI / 180) * m_fSpeed;
		m_tTransPos.Position.fY +=-sinf(m_fAngle *  PI / 180) * m_fSpeed;
		*/
	}

	if (KEY_DOWN & dwKey)
	{
		// m_tTransPos.Position.fY += m_fSpeed;


		//** �ش��ϴ� ������ ���� ����
		/*
		m_tTransPos.Position.fX -= cosf(m_fAngle *  PI / 180) * m_fSpeed;
		m_tTransPos.Position.fY -= -sinf(m_fAngle *  PI / 180) * m_fSpeed;
		*/
	}

	if (KEY_LEFT & dwKey)
	{
		m_tTransPos.Position.fX -= m_fSpeed;
		isLeft = true;
		m_fAngle = 180.0f;
	}
	if (KEY_RIGHT & dwKey)
	{
		m_tTransPos.Position.fX += m_fSpeed;
		isLeft = false;
		m_fAngle = 0.0f;
	}

	if (KEY_SPACE & dwKey)
	{
		isCharging = true;
		
		if (isLeft)
		{
			if (m_fAngle > 90.0f)
			{
				m_fAngle -= 0.5f;
			}
		}

		if (!isLeft)
		{
			if (m_fAngle < 90.0f)
			{
				m_fAngle += 0.5f;
			}
		}
		
	}
	else
	{
		if (isCharging)
		{
			Object* pObj = CreateBullet<NormalBullet>();

			ObjectManager::GetInstance()->AddObject(pObj->GetKey(), pObj);

			isShoot = true;
			isCharging = false;

			if (isLeft)
			{
				m_fAngle = 180.0f;
			}
			if (!isLeft)
			{
				m_fAngle = 0;
			}

		}
	}

	/*
	if (KEY_RBUTTON & dwKey)
	{
		//** ���콺 ��Ŭ�� �̺�Ʈ�� �߻��ϸ� �÷��̾ �����̰� �ϱ� ����.
		m_bMove = true;

		//** ���콺 ��ǥ�� �޾ƿ�.
		GetCursorPos(&m_ptMouse);
		ScreenToClient(g_hWnd, &m_ptMouse);

		//** ���콺 ��ġ���� �÷��̾��� ��ġ�� �� �ﰢ�Լ��� ���� ���̸� ����.
		m_Direction.fX = m_ptMouse.x - m_tTransPos.Position.fX;
		m_Direction.fY = m_ptMouse.y - m_tTransPos.Position.fY;

		m_TargetPoint = Vector3((float)m_ptMouse.x, (float)m_ptMouse.y);
	}

	//** ���콺 ��Ŭ�� �̺�Ʈ�� �߻��ϸ� �����ϴ� �̺�Ʈ ���� ����.
	if (KEY_LBUTTON & dwKey)
	{
		//SoundManager::GetInstance()->OnPlaySound("bleeps", SOUND_CHANNEL_ID_EFFECT);

		//** ���콺 ��ǥ�� �޾ƿ�.
		GetCursorPos(&m_ptMouse);
		ScreenToClient(g_hWnd, &m_ptMouse);
	}
	*/
}

template <typename T>
Object* Player::CreateBullet()
{
	Bridge* Bridge = new T;

	((Bullet_Bridge*)Bridge)->SetAngle(m_fAngle);

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(m_tTransPos.Position.fX, m_tTransPos.Position.fY - BULLET_SCALE_Y, Bridge);

	return pBullet;
}
