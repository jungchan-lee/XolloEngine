#pragma once
#include "XEntity.h"

namespace xollo
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* GOwner) { Owner = GOwner; }
		GameObject* GetOwner() { return Owner; }

	private:
		GameObject* Owner;
	};
}


