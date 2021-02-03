#pragma once
#include "Include.h"
#include "ObjectManager.h"

class TurnManager
{
private:
	static TurnManager* m_pInstance;
	ObjectManager* ObjManager = ObjectManager::GetInstance();
public:
	static TurnManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new TurnManager;
		return m_pInstance;
	}
public:
	void AddObject(void);
	void GetTurnValue(string _strKey, bool _turnValue);
	void Progress(void);
	void Render(HDC _hdc);
	void Release(void);
private:
	TurnManager();
public:
	~TurnManager();
};

