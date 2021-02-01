#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::m_pInstance = NULL;

SceneManager::SceneManager() : m_SceneState(NULL)
{
}

SceneManager::~SceneManager()
{
}


void SceneManager::SetScene(SCENEIDS _state)
{
	if (m_SceneState != NULL)
	{
		delete m_SceneState;
		m_SceneState = NULL;
	}

	switch (_state)
	{
	case SCENEID_LOGO:
		m_SceneState = new Logo;
		break;

	case SCENEID_MENU:
		m_SceneState = new Menu;
		break;

	case SCENEID_STAGE:
		m_SceneState = new Stage;
		break;

	case SCENEID_EXIT:
		
		break;
	}
	m_SceneState->Initialize();
}

void SceneManager::Progress()
{
	m_SceneState->Progress();
}

void SceneManager::Render(HDC _hdc)
{
	m_SceneState->Render(_hdc);
}

