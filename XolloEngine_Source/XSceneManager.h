#pragma once
#include "XScene.h"

namespace xollo
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* Scene = new T();
			Scene->SetName(name);
			ActiveScene = Scene;
			Scene->Initialize();

			Scenes.insert(std::make_pair(name, Scene));

			return Scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return ActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		
		
	private:
		//static std::vector<Scene*> Scenes;
		static std::map<std::wstring, Scene*> Scenes;
		static Scene* ActiveScene;
	};
}


