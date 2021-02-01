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

	//** 이미지 리스트 받아옴
	m_pImageList = BitmapManager::GetInstance()->GetImageList();

	//** 버퍼 이미지 삽입. (이미지를 한번에 출력하기 위한 그림판 용도)
	m_pImageList->insert(make_pair("BackBuffer", m_pBackBuffer));

	//** Background 백그라운드 이미지 삽입
	
	m_pImageList->insert(make_pair("BackGround_Logo", (new Bitmap)->LoadBmp(L"../Resource/Image/WhiteBG.bmp")));
	
	//** PressAnyKey 이미지 삽입
	m_pImageList->insert(make_pair("PressAnyKey", (new Bitmap)->LoadBmp(L"../Resource/Image/Logo/PressAnyKey.bmp")));

	//** Logo 이미지 삽입
	m_pImageList->insert(make_pair("Logo", (new Bitmap)->LoadBmp(L"../Resource/Image/Logo/logo.bmp")));
	
	//** 버튼 이미지 삽입
	m_pImageList->insert(make_pair("StartButton", (new Bitmap)->LoadBmp(L"../Resource/Image/Menu/btn_purchase_n-horz.bmp")));

	//** 리스트에 넣어둔 이미지들을 오브젝트 클레스에 보관.
	Object::SetImageList(m_pImageList);


	//** 사운드 재생 및 채널 설정.
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

	BitBlt(_hdc,	//** 그림을 그려 넣을곳
		0,	//** 이미지가 출력될 시작점 X
		0,	//** 이미지가 출력될 시작점 Y
		WINSIZEX, WINSIZEY,				//** 복사할 이미지의 크기만큼 복사
		(*m_pImageList)["Logo"]->GetMemDC(),	//** 복사할 이미지
		0, 0,	// 출력 시작점 좌표
		SRCCOPY);	// 고속 복사


	BitBlt(_hdc,	//** 그림을 그려 넣을곳
		0,	//** 이미지가 출력될 시작점 X
		0,	//** 이미지가 출력될 시작점 Y
		WINSIZEX, WINSIZEY,				//** 복사할 이미지의 크기만큼 복사
		(*m_pImageList)["PressAnyKey"]->GetMemDC(),	//** 복사할 이미지
		0, 0,	// 출력 시작점 좌표
		SRCCOPY);	// 고속 복사

}

void Logo::Release(void)
{
}

