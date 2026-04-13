#include "XGameObject.h"
#include "XInput.h"
#include "XTime.h"

namespace xollo
{
	GameObject::GameObject()
		: mX(0)
		, mY(0)
	{
	}
	GameObject::~GameObject()
	{
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


		if (Input::GetKey(EKeyCode::A))	//문자열로 wasd로 변경 가능 'W'
		{
			mX -= speed * Time::GetDeltaTime();
		}
		if (Input::GetKey(EKeyCode::D))
		{
			mX += speed * Time::GetDeltaTime();
		}
		if (Input::GetKey(EKeyCode::W))
		{
			mY -= speed * Time::GetDeltaTime();
		}
		if (Input::GetKey(EKeyCode::S))
		{
			mY += speed * Time::GetDeltaTime();
		}

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
		// 파랑 브러쉬 생성
		mBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)); // color 저장

		// 파랑 브러쉬 DC에 선택, 그리고 흰색 브러쉬 변환
		OldBrush = (HBRUSH)SelectObject(hdc, mBrush);   //hdc 의 컬러값 변경, 기본값을 해당 brush 색을오 변경

		mPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		OldPen = (HPEN)SelectObject(hdc, mPen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		//다시 흰색 원본 브러쉬로 선택
		SelectObject(hdc, OldBrush);

		// 파랑 브러쉬 삭제
		DeleteObject(mBrush);
		DeleteObject(mPen);

		for (Component* comp : Components)
		{
			comp->Render(hdc);
		}
	}
}