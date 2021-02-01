#include "InputManager.h"

InputManager* InputManager::m_pInstance = NULL;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{

}

void InputManager::UpdateKey()
{
	m_dwKey = 0;

	if (GetAsyncKeyState(VK_UP))
	{
		m_dwKey |= KEY_UP;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		m_dwKey |= KEY_DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_dwKey |= KEY_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_dwKey |= KEY_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		m_dwKey |= KEY_SPACE;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		m_dwKey |= KEY_RETURN;
	}
	if (GetAsyncKeyState(VK_RBUTTON))
	{
		m_dwKey |= KEY_RBUTTON;
	}
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		m_dwKey |= KEY_LBUTTON;
	}
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		m_dwKey |= KEY_ESCAPE;
	}
}


