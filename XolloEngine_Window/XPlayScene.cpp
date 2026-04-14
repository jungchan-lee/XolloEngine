#include "XPlayScene.h"
#include "XGameObject.h"
#include "XPlayer.h"
#include "XTransform.h"
#include "XSpriteRender.h"

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
		//플레이어 생성
		Player* bg = new Player();

		//플레이어에 트랜스폼 컴포넌트 등록
		Transform* Tform = bg->AddComponent<Transform>();
		Tform->SetPos(Vector2(0, 0));
		Tform->SetName(L"Transform");
		
		//플레이어에 스프라이트 렌더 컴포넌트 등록
		SpriteRender* SRender = bg->AddComponent<SpriteRender>();
		SRender->SetName(L"SpriteRender");
		SRender->ImageLoad(L"C:\\Users\\chan1\\source\\repos\\XolloEngine\\Resources\\CloudOcean.png");

		//게임 오브젝트 배열에 추가
		AddGameObject(bg);

	}
	void PlayScene::Update()
	{
		//Super와 같음
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