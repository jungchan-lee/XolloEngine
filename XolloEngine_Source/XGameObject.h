#pragma once
#include "CommonInclude.h"

enum EObjectName
{
	Red,
	Blue
};


namespace xollo
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

		void SetObjectName(EObjectName PlayObjectName) { ObjectName = PlayObjectName; }

	private:
		//게임 오브젝트의 좌표
		float mX;
		float mY;
		EObjectName ObjectName;

		HBRUSH mBrush;
		HBRUSH OldBrush;
		HPEN mPen;
		HPEN OldPen;
	};

}

