#pragma once
#include "XEntity.h"
#include "XGameObject.h"

namespace xollo
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObjcet);

	private:
		std::vector<GameObject*> GameObjects;

	};
}


