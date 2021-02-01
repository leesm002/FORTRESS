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
	//** �׸��� �׸� DC�� window���� �޾ƿ�.
	m_hdc = GetDC(g_hWnd);

	/***************************
	*	  ���� ����̽�
	****************************/

	//** ���� ����̽� ���� �� �ʱ�ȭ.
	SoundManager::GetInstance()->Initialize();

	//** ���� �߰�
	SoundManager::GetInstance()->AddSound("../Resource/Sound/dragon_flight.mp3", "BackGround");
	SoundManager::GetInstance()->AddSound("../Resource/Sound/dragon_flight2.mp3", "Logo");

	//** ���콺 ������ �Ⱥ��̰� ����. (true/false)
	//ShowCursor(false);

	//** Ÿ�԰� �ʱ�ȭ. �ѹ��� �����ϸ� ��.
	srand((int)GetTickCount64());

	//** �� �Ŵ��� �ʱ�ȭ. ���� �ΰ�� �����ϰ� ����.
	SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
}

void MainUpdate::Progress(void)
{
	//** �� �����Ӹ��� Ű �Է� Ȯ��.
	InputManager::GetInstance()->UpdateKey();

	//** ������� ���尡 ����Ǳ� ������ Ȯ���ϱ� ����.
	//SoundManager::GetInstance()->StreamingUpdate();

	SceneManager::GetInstance()->Progress();
}

void MainUpdate::Render(void)
{
	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release(void)
{
	//** window ���� �޾ƿ� �׸����� ������.
	ReleaseDC(g_hWnd, m_hdc);
}


