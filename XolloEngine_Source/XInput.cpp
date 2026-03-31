#include "XInput.h"

namespace xollo
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)EKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initialize()
	{
		//mKeys.resize(UINT)(EKeyCode::End);


		for (size_t i = 0; i < (UINT)EKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.State = EKeyState::None;
			key.KeyCode = (EKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			//키 눌림
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].State = EKeyState::Pressed;
				}
				else
				{
					mKeys[i].State = EKeyState::Down;
				}

				mKeys[i].bPressed = true;
			}
			//키 안눌림
			else
			{
				//이전 프레임에 눌러져 있었다 UP
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].State = EKeyState::Up;
				}
				//이전 프레임도 지금도 눌러져 있지 않다 None
				else
				{
					mKeys[i].State = EKeyState::None;
				}

				mKeys[i].bPressed = false;
			}
		}
	}
}