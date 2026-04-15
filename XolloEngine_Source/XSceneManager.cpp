#include "XSceneManager.h"

namespace xollo
{
	std::map<std::wstring, Scene*> SceneManager::Scenes = {};
	Scene* SceneManager::ActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (ActiveScene)
		{
			ActiveScene->OnExit();
		}

		std::map<std::wstring, Scene*>::iterator iter = Scenes.find(name);

		if (iter == Scenes.end())
		{
			return nullptr;
		}

		ActiveScene = iter->second;
		ActiveScene->OnEnter();

		return iter->second; //first°¡ mapÀÇ key, second°¡ value
	}

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

