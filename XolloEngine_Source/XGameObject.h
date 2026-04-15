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

		//게임 오브젝트에 컴포넌트 추가 템플릿
		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			Components.push_back(comp);

			return comp;

		}

		//게임 오브젝트가 가지고 있는 컴포넌트와 비교하여 반환
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

	private:
		void InitializeTransform();
		
	private:
		std::vector<Component*> Components;
	};

}

