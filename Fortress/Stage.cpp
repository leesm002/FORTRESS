#include "Stage.h"
#include "Monster.h"
#include "BackGround.h"

#include "Bitmap.h"
#include "ObjectManager.h"
#include "BitmapManager.h"


Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize(void)
{
	iBG_fx = 0;

	pPlayer->Initialize();

	m_pImageList = BitmapManager::GetInstance()->GetImageList();

	m_pImageList->insert(make_pair("BackBuffer", m_pBackBuffer));

	m_pImageList->insert(make_pair("BackGround_Stage", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/StageBG.bmp")));
		
	Object::SetImageList(m_pImageList);

}

int Stage::Progress(void)
{
	ObjectManager::GetInstance()->Progress();

	pPlayer->Progress();



	return 0;
}


void Stage::Render(HDC _hdc)
{
	ObjectManager::GetInstance()->Render(m_pBackBuffer->GetMemDC());

	BitBlt(m_pBackBuffer->GetMemDC(),	//** 그림을 그려 넣을곳
		0,	//** 이미지가 출력될 시작점 X
		0,	//** 이미지가 출력될 시작점 Y
		WINSIZEX, 
		WINSIZEY,				//** 복사할 이미지의 크기만큼 복사
		(*m_pImageList)["BackGround_Stage"]->GetMemDC(),	//** 복사할 이미지
		0, 0,
		SRCCOPY);	// 고속 복사

	pPlayer->Render(m_pBackBuffer->GetMemDC());

	BitBlt(_hdc,	//** 그림을 그려 넣을곳
		0,	//** 이미지가 출력될 시작점 X
		0,	//** 이미지가 출력될 시작점 Y
		WINSIZEX,
		WINSIZEY,				//** 복사할 이미지의 크기만큼 복사
		m_pBackBuffer->GetMemDC(),	//** 복사할 이미지
		0, 0,
		SRCCOPY);	// 고속 복사

}

void Stage::Release(void)
{
	ObjectManager::GetInstance()->Release();
}

