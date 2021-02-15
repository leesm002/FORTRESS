#include "Ground.h"

void Ground::Initialize(void)
{

    m_pImageList->insert(make_pair("Ground", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Ground/Ground.bmp")));
}

int Ground::Progress(void)
{
    return 0;
}

void Ground::Render(HDC _hdc)
{
	TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
		0,	// ������ ���� ������ X
		0, 	// ������ ���� ������ Y
		WINSIZEX,	// ������ ���� ���κ� X
		WINSIZEY, 	// ������ ���� ���κ� Y
		(*m_pImageList)["Ground"]->GetMemDC(),	// ������ �̹��� (������)
		0,  // ������ ������ X
		0,	// ������ ������ Y
		GROUND_WIDTH, 			// ����� �̹����� ũ�� ��ŭ X
		GROUND_HEIGHT,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 255, 255));		// �ش� ������ ����
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
