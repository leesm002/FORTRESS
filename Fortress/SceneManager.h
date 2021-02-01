#pragma once
#include "Include.h"
#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* m_pInstance;
public:
	static SceneManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new SceneManager;
		return m_pInstance;
	}
private:
	Scene* m_SceneState;
public:
	void SetScene(SCENEIDS _state);
	void Progress();
	void Render(HDC _hdc);

private:
	SceneManager();
public:
	~SceneManager();
};

