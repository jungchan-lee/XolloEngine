#include "XGameObject.h"
#include "XInput.h"


namespace xollo
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		switch (ObjectName)
		{
		case Red:
			if (Input::GetKey(EKeyCode::A))	//문자열로 wasd로 변경 가능 'W'
			{
				mX -= 0.01f;
			}
			if (Input::GetKey(EKeyCode::D))
			{
				mX += 0.01f;
			}
			if (Input::GetKey(EKeyCode::W))
			{
				mY -= 0.01f;
			}
			if (Input::GetKey(EKeyCode::S))
			{
				mY += 0.01f;
			}
			break;
		case Blue:
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)	//문자열로 wasd로 변경 가능 'W'
			{
				mX -= 0.01f;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				mX += 0.01f;
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				mY -= 0.01f;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				mY += 0.01f;
			}
			break;
		default:
			break;
		}

		
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		

		switch (ObjectName)
		{
		case Red:
			// 파랑 브러쉬 생성
			mBrush = CreateSolidBrush(RGB(255, 0, 0)); // color 저장

			// 파랑 브러쉬 DC에 선택, 그리고 흰색 브러쉬 변환
			OldBrush = (HBRUSH)SelectObject(hdc, mBrush);   //hdc 의 컬러값 변경, 기본값을 해당 brush 색을오 변경

			mPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
			OldPen = (HPEN)SelectObject(hdc, mPen);

			Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

			//다시 흰색 원본 브러쉬로 선택
			SelectObject(hdc, OldBrush);

			// 파랑 브러쉬 삭제
			DeleteObject(mBrush);
			DeleteObject(mPen);
			break;
		case Blue:
			// 파랑 브러쉬 생성
			mBrush = CreateSolidBrush(RGB(0, 0, 255)); // color 저장

			// 파랑 브러쉬 DC에 선택, 그리고 흰색 브러쉬 변환
			OldBrush = (HBRUSH)SelectObject(hdc, mBrush);   //hdc 의 컬러값 변경, 기본값을 해당 brush 색을오 변경

			mPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			OldPen = (HPEN)SelectObject(hdc, mPen);

			Rectangle(hdc, 500 + mX, 500 + mY, 700 + mX, 700 + mY);

			//다시 흰색 원본 브러쉬로 선택
			SelectObject(hdc, OldBrush);

			// 파랑 브러쉬 삭제
			DeleteObject(mBrush);
			DeleteObject(mPen);
			break;
		default:
			break;
		}
	}
}