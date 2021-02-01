#pragma once
#include "Include.h"
#include "Bitmap.h"

class Bitmap;
class Scene
{
protected:
	Bitmap* m_pBackBuffer = (new Bitmap)->LoadBmp(L"../Resource/Image/Backbuffer.bmp");
	map<string, Bitmap*>* m_pImageList;
public:
	virtual void Initialize()PURE;
	virtual int Progress()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};

