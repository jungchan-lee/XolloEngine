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
			Scene->Initialize();

			Scenes.insert(std::make_pair(name, Scene));

			return Scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter = Scenes.find(name);

			if (iter == Scenes.end())
			{
				return nullptr;
			}
			
			ActiveScene = iter->second;

			return iter->second; //first∞° map¿« key, second∞° value
			
		}

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


