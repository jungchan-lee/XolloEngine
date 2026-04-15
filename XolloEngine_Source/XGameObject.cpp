#include "XGameObject.h"
#include "XInput.h"
#include "XTime.h"
#include "XTransform.h"

namespace xollo
{
	GameObject::GameObject()
	{
		InitializeTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : Components)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : Components)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		const int speed = 100.0f;


		//if (Input::GetKey(EKeyCode::A))	//문자열로 wasd로 변경 가능 'W'
		//{
		//	mX -= speed * Time::GetDeltaTime();
		//}
		//if (Input::GetKey(EKeyCode::D))
		//{
		//	mX += speed * Time::GetDeltaTime();
		//}
		//if (Input::GetKey(EKeyCode::W))
		//{
		//	mY -= speed * Time::GetDeltaTime();
		//}
		//if (Input::GetKey(EKeyCode::S))
		//{
		//	mY += speed * Time::GetDeltaTime();
		//}

		for (Component* comp : Components)
		{
			comp->Update();
		}

	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : Components)
		{
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : Components)
		{
			comp->Render(hdc);
		}
	}

	void GameObject::InitializeTransform()
	{
		AddComponent<Transform>();
	}
}