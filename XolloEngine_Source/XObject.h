#pragma once
#include "XComponent.h"
#include "XGameObject.h"
#include "XLayer.h"
#include "XScene.h"
#include "XSceneManager.h"
#include "XTransform.h"

namespace xollo::object
{
	template <typename T>
	static T* Instantiate(enums::ELayerType Type)
	{
		T* gameObject = new T();
		Scene* ActiveScene = SceneManager::GetActiveScene();
		Layer* layer = ActiveScene->GetLayer(Type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(enums::ELayerType Type, math::Vector2 Position)
	{
		T* gameObject = new T();
		Scene* ActiveScene = SceneManager::GetActiveScene();
		Layer* layer = ActiveScene->GetLayer(Type);
		layer->AddGameObject(gameObject);

		Transform* Tform = gameObject->GetComponent<Transform>();
		Tform->SetPosition(Position);

		return gameObject;

	}
}
