#pragma once
#include "XEntity.h"
#include "CommonInclude.h"
#include "XGameObject.h"

namespace xollo
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* GameObj);

	private:
		std::vector<GameObject*> LayerGameObj;
	};
}


