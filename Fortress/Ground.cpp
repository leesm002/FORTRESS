#include "Ground.h"

void Ground::Initialize(void)
{
	m_rc = {(long)m_tTransPos.Position.fX - 50,
			(long)m_tTransPos.Position.fY - 50,
			(long)m_tTransPos.Position.fX + 50,
			(long)m_tTransPos.Position.fY + 50};

    m_pImageList->insert(make_pair("Ground", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Ground/Ground.bmp")));
}

int Ground::Progress(void)
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (KEY_TAB & dwKey)
		isDebugMode = true;
	else
		isDebugMode = false;
    return 0;
}

void Ground::Render(HDC _hdc)
{
	if (isDebugMode)
		Rectangle(_hdc, m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);

	TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
		0,	// 복사할 영역 시작점 X
		0, 	// 복사할 영역 시작점 Y
		WINSIZEX,	// 복사할 영역 끝부분 X
		WINSIZEY, 	// 복사할 영역 끝부분 Y
		(*m_pImageList)["Ground"]->GetMemDC(),	// 복사할 이미지 (복사대상)
		0,  // 복사할 시작점 X
		0,	// 복사할 시작점 Y
		GROUND_WIDTH, 			// 출력할 이미지의 크기 만큼 X
		GROUND_HEIGHT,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 255, 255));		// 해당 색상을 제외
}

void Ground::Release(void)
{
}

Ground::Ground()
{
}

Ground::~Ground()
{
}
