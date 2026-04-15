#include "XTitleScene.h"
#include "XInput.h"
#include "XPlayScene.h"
#include "XSceneManager.h"

namespace xollo
{
    TitleScene::TitleScene()
    {
    }
    TitleScene::~TitleScene()
    {
    }
    void TitleScene::Initialize()
    {
        Scene::Initialize();
    }
    void TitleScene::Update()
    {
        Scene::Update();
    }
    void TitleScene::LateUpdate()
    {
        Scene::LateUpdate();

        if (Input::GetKeyDown(EKeyCode::N))
        {
            SceneManager::LoadScene(L"PlayScene");
        }
    }
    void TitleScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
        wchar_t str[50] = L"Title Scene";
        TextOut(hdc, 0, 0, str, 11);
    }
    void TitleScene::OnEnter()
    {
    }
    void TitleScene::OnExit()
    {
    }
}