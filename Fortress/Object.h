#pragma once
#include "Include.h"
#include "Bitmap.h"
#include "InputManager.h"


class Object
{
protected:
	Transform m_tTransPos;
	Frame m_tFrame;
	RECT m_rc;
	string m_strKey;
	bool isDebugMode = false;
	float m_fSpeed;
	float m_fAngle;
	bool isExistGround = false;
	bool isMoved = false;
	ULONGLONG m_dwFrameTime;

	static map<string, Bitmap*>* m_pImageList;

public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { m_pImageList = _ImageList; }
public:
	virtual void Initialize()PURE;
	virtual int Progress()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
	void DebugMode()
	{
		DWORD dwKey = InputManager::GetInstance()->GetKey();

		if (KEY_TAB & dwKey)
			isDebugMode = true;
		else
			isDebugMode = false;
	}
public:
	string GetKey() const { return m_strKey; }
	void SetKey(string _Key) { m_strKey = _Key; }

	float GetAngle() const { return m_fAngle; }
	void SetAngle(float _Angle) { m_fAngle = _Angle; }

	Vector3 GetPosition() const { return m_tTransPos.Position; }
	void SetPosition(float _fx, float _fy) { m_tTransPos.Position.fX = _fx; m_tTransPos.Position.fY = _fy; }

	Vector3 GetScale() const { return m_tTransPos.Scale; }
	void SetScale(float _fx, float _fy) { m_tTransPos.Scale.fX = _fx; m_tTransPos.Scale.fY = _fy; }

	Transform* GetTransPos() { return &m_tTransPos; }
	RECT* GetRC() { return &m_rc; }

	bool GetIsExistGround() { return isExistGround; }
	void SetIsExistGround(bool _isExistGround) { isExistGround = _isExistGround; }

	bool GetIsMoved() { return isMoved; }
	void SetIsMoved(bool _isMoved) { isMoved = _isMoved; }



public:
	Object();
	virtual ~Object();
};

