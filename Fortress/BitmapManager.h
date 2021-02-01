#pragma once
#include "Include.h"

class Bitmap;
class BitmapManager
{
private:
	static BitmapManager* m_pInstance;
public:
	static BitmapManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new BitmapManager;
		return m_pInstance;
	}

private:
	map<string, Bitmap*> m_mapImageList;
	//map<string, vector<Bitmap*>*> m_BackGroundList;
public:
	map<string, Bitmap*>* GetImageList() { return &m_mapImageList; }
	//map<string, vector<Bitmap*>*>* GetBackGroundList() { return &m_BackGroundList; }
private:
	BitmapManager();
public:
	~BitmapManager();
};

