#include "TurnManager.h"

TurnManager* TurnManager::m_pInstance = NULL;

void TurnManager::AddObject(void)
{
}

void TurnManager::GetTurnValue(string _strKey,bool _turnValue)
{
	if (_strKey == "Player")
	{
		Object* pObj = ObjManager->GetObjectList()->find(_strKey)->second();

	}
	ObjManager->GetObjectList()->find(_strKey);
}

void TurnManager::Progress(void)
{
}

void TurnManager::Render(HDC _hdc)
{
}

void TurnManager::Release(void)
{
}

TurnManager::TurnManager()
{
}

TurnManager::~TurnManager()
{
}
