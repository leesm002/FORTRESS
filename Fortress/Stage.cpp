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
	pMonster->Initialize();
	pGround->Initialize();

	m_pImageList = BitmapManager::GetInstance()->GetImageList();

	m_pImageList->insert(make_pair("BackBuffer", m_pBackBuffer));

	m_pImageList->insert(make_pair("BackGround_Stage", (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/StageBG.bmp")));

	Object::SetImageList(m_pImageList);

}

int Stage::Progress(void)
{
	ObjectManager::GetInstance()->Progress();

	pPlayer->Progress();
	pMonster->Progress();
	pGround->Progress();

	return 0;
}


void Stage::Render(HDC _hdc)
{
	ObjectManager::GetInstance()->Render(m_pBackBuffer->GetMemDC());
	
	BitBlt(m_pBackBuffer->GetMemDC(),
		0,	
		0,	
		WINSIZEX, 
		WINSIZEY,				
		(*m_pImageList)["BackGround_Stage"]->GetMemDC(),	
		0, 0,
		SRCCOPY);	

	pGround->Render(m_pBackBuffer->GetMemDC());
	pPlayer->Render(m_pBackBuffer->GetMemDC());
	pMonster->Render(m_pBackBuffer->GetMemDC());

	BitBlt(_hdc,	
		0,	
		0,	
		WINSIZEX,
		WINSIZEY,			
		m_pBackBuffer->GetMemDC(),
		0, 0,
		SRCCOPY);	


}

void Stage::Release(void)
{
	ObjectManager::GetInstance()->Release();
}

