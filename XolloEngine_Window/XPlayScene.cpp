#include "XPlayScene.h"
#include "XGameObject.h"
#include "XPlayer.h"
#include "XTransform.h"
#include "XSpriteRender.h"
#include "XInput.h"
#include "XTitleScene.h"
#include "XSceneManager.h"
#include "XObject.h"

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
		////플레이어 생성
		//bg = new Player();

		////플레이어에 트랜스폼 컴포넌트 등록
		//Transform* Tform = bg->AddComponent<Transform>();
		//Tform->SetPosition(Vector2(0, 0));
		//Tform->SetName(L"Transform");
		//
		////플레이어에 스프라이트 렌더 컴포넌트 등록
		//SpriteRender* SRender = bg->AddComponent<SpriteRender>();
		//SRender->SetName(L"SpriteRender");
		//SRender->ImageLoad(L"E:\\C++ Project\\Resources\\CloudOcean.png");

		////게임 오브젝트 배열에 추가
		//AddGameObject(bg, enums::ELayerType::BackGround);

		bg = object::Instantiate<Player>(enums::ELayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRender* SRender = bg->AddComponent<SpriteRender>();
		SRender->ImageLoad(L"E:\\C++ Project\\Resources\\CloudOcean.png");

		//게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 Init 함수 호출
		Scene::Initialize();

	}
	void PlayScene::Update()
	{
		//Super와 같음
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(EKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		/*Transform* Tform = bg->GetComponent<Transform>();
		Tform->SetPosition(Vector2(0, 0));*/
	}
}