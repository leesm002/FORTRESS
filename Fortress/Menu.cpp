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

	BitBlt(_hdc,	//** �׸��� �׷� ������
		0,	//** �̹����� ��µ� ������ X
		0,	//** �̹����� ��µ� ������ Y
		WINSIZEX, WINSIZEY,				//** ������ �̹����� ũ�⸸ŭ ����
		(*pBitmapList)["BackBuffer"]->GetMemDC(),	//** ������ �̹���
		0, 0,	// ��� ������ ��ǥ
		SRCCOPY);	// ��� ����
}

void Menu::Release(void)
{
}

