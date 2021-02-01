#pragma once
#include "Include.h"

class InputManager
{
private:
	static InputManager* m_pInstance;
public:
	static InputManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new InputManager;
		return m_pInstance;
	}
private:
	DWORD m_dwKey;
public:
	DWORD GetKey() const { return m_dwKey; }
	POINT GetMousePoint(void)
	{
		POINT	pt;
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);
		return pt;
	}


	void UpdateKey();

private:
	InputManager();
public:
	~InputManager();
};

