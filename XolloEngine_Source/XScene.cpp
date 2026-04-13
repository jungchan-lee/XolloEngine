#include "XScene.h"

namespace xollo
{
	Scene::Scene()
		: GameObjects {}
	{
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		for (GameObject* GameObj : GameObjects)
		{
			GameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* GameObj : GameObjects)
		{
			GameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* GameObj : GameObjects)
		{
			GameObj->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObjcet)
	{
		GameObjects.push_back(gameObjcet);
	}
}