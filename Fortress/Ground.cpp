#include "Ground.h"

void Ground::Initialize(void)
{
	m_strKey = "Ground";

	m_rc = { 0,
			WINSIZEY - 80,
			WINSIZEX,
			WINSIZEY };

    m_pImageList->insert(make_pair(m_strKey, (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Ground/Ground.bmp")));
}

int Ground::Progress(void)
{

	DebugMode();

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
		(*m_pImageList)[m_strKey]->GetMemDC(),	// 복사할 이미지 (복사대상)
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
