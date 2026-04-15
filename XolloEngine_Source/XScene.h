#pragma once
#include "XEntity.h"
#include "XGameObject.h"
#include "XLayer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObjcet, const enums::ELayerType Type);
		Layer* GetLayer(const enums::ELayerType Type) { return SceneLayer[(UINT)Type]; }

	private:
		void CreateLayer();

	private:
		std::vector<Layer*> SceneLayer;
	};
}


