#pragma once
#include "../XolloEngine_Source/XSceneManager.h"
#include "XPlayScene.h"
#include "XTitleScene.h"

namespace xollo
{
	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");
		//SceneManager::CreateScene<PlayScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}

