#include "XScene.h"

namespace xollo
{
	Scene::Scene()
		: SceneLayer {}
	{
		CreateLayer();
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : SceneLayer)
		{
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : SceneLayer)
		{
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : SceneLayer)
		{
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : SceneLayer)
		{
			layer->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{
		
	}

	void Scene::OnExit()
	{
		
	}
	
	void Scene::AddGameObject(GameObject* gameObjcet, const enums::ELayerType Type)
	{
		SceneLayer[(UINT)Type]->AddGameObject(gameObjcet);
	}
	
	void Scene::CreateLayer()
	{
		SceneLayer.resize((UINT)enums::ELayerType::Max);
		for (size_t i = 0; i < (UINT)enums::ELayerType::Max; i++)
		{
			SceneLayer[i] = new Layer();
		}
	}
}