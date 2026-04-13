#pragma once
#include "CommonInclude.h"
#include "XComponent.h"

namespace xollo
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);
			Components.push_back(comp);

			return comp;

		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;

			for (Component* comp : Components)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		//게임 오브젝트의 좌표
		float mX;
		float mY;

		HBRUSH mBrush;
		HBRUSH OldBrush;
		HPEN mPen;
		HPEN OldPen;

		std::vector<Component*> Components;
	};

}

