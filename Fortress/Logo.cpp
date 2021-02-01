#include "Logo.h"
#include "Button.h"
#include "LogoObject.h"
#include "BackGround.h"
#include"InputManager.h"
#include "SceneManager.h"

#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "BitmapManager.h"
#include "SoundManager.h"


Logo::Logo()
{

}

Logo::~Logo()
{

}


void Logo::Initialize(void)
{
	Object* pBackGround = ObjectFactory<BackGround>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pBackGround->GetKey(), pBackGround);


	/*********************************
	   **  Logo image is insert. **
	**********************************/

	//** �̹��� ����Ʈ �޾ƿ�
	m_pImageList = BitmapManager::GetInstance()->GetImageList();

	//** ���� �̹��� ����. (�̹����� �ѹ��� ����ϱ� ���� �׸��� �뵵)
	m_pImageList->insert(make_pair("BackBuffer", m_pBackBuffer));

	//** Background ��׶��� �̹��� ����
	
	m_pImageList->insert(make_pair("BackGround_Logo", (new Bitmap)->LoadBmp(L"../Resource/Image/WhiteBG.bmp")));
	
	//** PressAnyKey �̹��� ����
	m_pImageList->insert(make_pair("PressAnyKey", (new Bitmap)->LoadBmp(L"../Resource/Image/Logo/PressAnyKey.bmp")));

	//** Logo �̹��� ����
	m_pImageList->insert(make_pair("Logo", (new Bitmap)->LoadBmp(L"../Resource/Image/Logo/logo.bmp")));
	
	//** ��ư �̹��� ����
	m_pImageList->insert(make_pair("StartButton", (new Bitmap)->LoadBmp(L"../Resource/Image/Menu/btn_purchase_n-horz.bmp")));

	//** ����Ʈ�� �־�� �̹������� ������Ʈ Ŭ������ ����.
	Object::SetImageList(m_pImageList);


	//** ���� ��� �� ä�� ����.
	SoundManager::GetInstance()->OnPlaySound("Logo", SOUND_CHANNEL_ID_LOGO);
}

int Logo::Progress(void)
{
	ObjectManager::GetInstance()->Progress();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN || dwKey & KEY_ESCAPE)
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
		return 0;
}

void Logo::Render(HDC _hdc)
{

	ObjectManager::GetInstance()->Render(m_pBackBuffer->GetMemDC());

	BitBlt(_hdc,	//** �׸��� �׷� ������
		0,	//** �̹����� ��µ� ������ X
		0,	//** �̹����� ��µ� ������ Y
		WINSIZEX, WINSIZEY,				//** ������ �̹����� ũ�⸸ŭ ����
		(*m_pImageList)["Logo"]->GetMemDC(),	//** ������ �̹���
		0, 0,	// ��� ������ ��ǥ
		SRCCOPY);	// ��� ����


	BitBlt(_hdc,	//** �׸��� �׷� ������
		0,	//** �̹����� ��µ� ������ X
		0,	//** �̹����� ��µ� ������ Y
		WINSIZEX, WINSIZEY,				//** ������ �̹����� ũ�⸸ŭ ����
		(*m_pImageList)["PressAnyKey"]->GetMemDC(),	//** ������ �̹���
		0, 0,	// ��� ������ ��ǥ
		SRCCOPY);	// ��� ����

}

void Logo::Release(void)
{
}

