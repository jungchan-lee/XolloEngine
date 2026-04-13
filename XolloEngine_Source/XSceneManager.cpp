#include "XSceneManager.h"

namespace xollo
{
	std::map<std::wstring, Scene*> SceneManager::Scenes = {};
	Scene* SceneManager::ActiveScene = nullptr;

	void SceneManager::Initialize()
	{

	}

	void SceneManager::Update()
	{
		ActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		ActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		ActiveScene->Render(hdc);
	}
}

