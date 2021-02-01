#include "Bitmap.h"

Bitmap::Bitmap()
{
}

Bitmap::~Bitmap()
{
	Release();
}


Bitmap * Bitmap::LoadBmp(LPCWSTR _FileName)
{
	m_hdc = GetDC(g_hWnd);
	m_MemDC = CreateCompatibleDC(m_hdc);

	m_bitmap = (HBITMAP)LoadImage(NULL, _FileName, IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_Oldbitmap = (HBITMAP)SelectObject(m_MemDC, m_bitmap);

	ReleaseDC(g_hWnd, m_hdc);

	return this;
}

void Bitmap::Release()
{
	SelectObject(m_MemDC, m_Oldbitmap);

	DeleteObject(&m_Oldbitmap);
	DeleteObject(m_bitmap);
	DeleteDC(m_MemDC);
}
