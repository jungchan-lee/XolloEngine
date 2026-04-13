#include "XPlayScene.h"
#include "XGameObject.h"

namespace xollo
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* Object = new GameObject();
			Object->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(Object);
		}

		

	}
	void PlayScene::Update()
	{
		//Super¿Í °°À½
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}