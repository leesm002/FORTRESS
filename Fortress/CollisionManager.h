#pragma once
#include "Include.h"
#include "Object.h"

class CollisionManager
{
public:
	static bool Collision(Object* _pTempObj, Object* _pDestObj)
	{
		float fX = _pTempObj->GetPosition().fX - _pDestObj->GetPosition().fX;
		float fY = _pTempObj->GetPosition().fY - _pDestObj->GetPosition().fY;

		float fSum = (_pTempObj->GetScale().fX / 2) + (_pDestObj->GetScale().fX / 2);

		float fLen = sqrt((fX * fX) + (fY * fY));

		if (fSum > fLen)
			return true;

		return false;
	}

	static bool CollRect(RECT* _pTempObj, RECT* _pDestObj)
	{
		if ( _pTempObj->left < _pDestObj->right &&
			 _pTempObj->top < _pDestObj->bottom &&
			 _pTempObj->right > _pDestObj->left &&
			 _pTempObj->bottom > _pDestObj->top )
		{
			return true;
		}
		return false;
	}
private:
	CollisionManager();
public:
	~CollisionManager();
};

