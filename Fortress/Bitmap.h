#pragma once
#include "Include.h"

class Bitmap
{
private:
	HDC			m_hdc, m_MemDC;
	HBITMAP		m_bitmap, m_Oldbitmap;
public:
	Bitmap* LoadBmp(LPCWSTR _FileName);
	void Release();

public:
	HDC GetMemDC() { return m_MemDC; }
public:
	Bitmap();
	~Bitmap();
};

