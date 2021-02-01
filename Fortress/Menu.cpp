#include "Menu.h"
#include "Button.h"
#include "Bitmap.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "BitmapManager.h"
#include "SceneManager.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Initialize(void)
{
	m_pButtonList.push_back(ObjectFactory<Button>::CreateObject(200, (WINSIZEY/2 - 500), "StartButton"));
	//m_pButtonList.push_back(ObjectFactory<Button>::CreateObject(200, (WINSIZEY/2 - 500), "Option"));
	//m_pButtonList.push_back(ObjectFactory<Button>::CreateObject(200, (WINSIZEY/2 - 700), "Exit"));
}

int Menu::Progress(void)
{
	ObjectManager::GetInstance()->Progress();

	for (int i = 0; i < m_pButtonList.size(); i++)
	{
		int iResult = m_pButtonList[i]->Progress();

		if (iResult == 1)
		{
			SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
			return 0;
		}
		else if (iResult == 2)
		{
			return 0;
		}
		else if (iResult == 3)
		{
			DestroyWindow(g_hWnd);
			return 0;
		}
	}

	return 0;
}

void Menu::Render(HDC _hdc)
{
	map<string, Bitmap*>* pBitmapList = BitmapManager::GetInstance()->GetImageList();

	ObjectManager::GetInstance()->Render((*pBitmapList)["BackBuffer"]->GetMemDC());

	/*
	*/
	for (int i = 0; i < m_pButtonList.size() ; i++)
	{
		m_pButtonList[i]->Render((*pBitmapList)["BackBuffer"]->GetMemDC());
	}

	BitBlt(_hdc,	//** 그림을 그려 넣을곳
		0,	//** 이미지가 출력될 시작점 X
		0,	//** 이미지가 출력될 시작점 Y
		WINSIZEX, WINSIZEY,				//** 복사할 이미지의 크기만큼 복사
		(*pBitmapList)["BackBuffer"]->GetMemDC(),	//** 복사할 이미지
		0, 0,	// 출력 시작점 좌표
		SRCCOPY);	// 고속 복사
}

void Menu::Release(void)
{
}

