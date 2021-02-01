#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"

#include "Bitmap.h"
#include "BitmapManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}


void MainUpdate::Initialize(void)
{
	//** 그림을 그릴 DC를 window에서 받아옴.
	m_hdc = GetDC(g_hWnd);

	/***************************
	*	  사운드 디바이스
	****************************/

	//** 사운드 디바이스 생성 및 초기화.
	SoundManager::GetInstance()->Initialize();

	//** 사운드 추가
	SoundManager::GetInstance()->AddSound("../Resource/Sound/dragon_flight.mp3", "BackGround");
	SoundManager::GetInstance()->AddSound("../Resource/Sound/dragon_flight2.mp3", "Logo");

	//** 마우스 포인터 안보이게 설정. (true/false)
	//ShowCursor(false);

	//** 타입값 초기화. 한번만 진행하면 됨.
	srand((int)GetTickCount64());

	//** 씬 매니저 초기화. 최초 로고로 진입하게 셋팅.
	SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
}

void MainUpdate::Progress(void)
{
	//** 매 프레임마다 키 입력 확인.
	InputManager::GetInstance()->UpdateKey();

	//** 재생중인 사운드가 종료되기 전인지 확인하기 위함.
	//SoundManager::GetInstance()->StreamingUpdate();

	SceneManager::GetInstance()->Progress();
}

void MainUpdate::Render(void)
{
	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release(void)
{
	//** window 에서 받아온 그림판을 삭제함.
	ReleaseDC(g_hWnd, m_hdc);
}


