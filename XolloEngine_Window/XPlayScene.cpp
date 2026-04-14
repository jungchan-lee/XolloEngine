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
		Player* player = new Player();

		Transform* Tform = player->AddComponent<Transform>();
		Tform->SetPos(800, 450);
		Tform->SetName(L"Transform");

		SpriteRender* SRender = player->AddComponent<SpriteRender>();
		SRender->SetName(L"SpriteRender");

		AddGameObject(player);
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