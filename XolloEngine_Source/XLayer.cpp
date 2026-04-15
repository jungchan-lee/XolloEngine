#include "XLayer.h"

namespace xollo
{
	Layer::Layer()
		: LayerGameObj{}
	{
	}
	Layer::~Layer()
	{
	}
	void Layer::Initialize()
	{
		for (GameObject* GameObj : LayerGameObj)
		{
			if (!GameObj)
			{
				continue;
			}

			GameObj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* GameObj : LayerGameObj)
		{
			if (!GameObj)
			{
				continue;
			}

			GameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* GameObj : LayerGameObj)
		{
			if (!GameObj)
			{
				continue;
			}

			GameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* GameObj : LayerGameObj)
		{
			if (!GameObj)
			{
				continue;
			}

			GameObj->Render(hdc);
		}
	}
	void Layer::AddGameObject(GameObject* GameObj)
	{
		if (!GameObj)
		{
			return;
		}

		LayerGameObj.push_back(GameObj);
	}
}
