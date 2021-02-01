#pragma once
#include "Include.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* m_pInstance;
public:
	static ObjectManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new ObjectManager;
		return m_pInstance;
	}
private:
	map<string, list<Object*>> m_mapObjectList;
public:
	map<string, list<Object*>>* GetObjectList() { return &m_mapObjectList; }
public:
	void AddObject(string _strKey, Object* _Object);
	void Progress(void);
	void Render(HDC _hdc);
	void Release(void);
private:
	ObjectManager();
public:
	~ObjectManager();
};

