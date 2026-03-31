#include "XInput.h"

namespace xollo
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)EKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,

	};

	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)EKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.State = EKeyState::None;
			key.KeyCode = (EKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < Keys.size(); i++)
		{
			//키 눌림
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (Keys[i].bPressed == true)
				{
					Keys[i].State = EKeyState::Pressed;
				}
				else
				{
					Keys[i].State = EKeyState::Down;
				}

				Keys[i].bPressed = true;
			}
			//키 안눌림
			else
			{
				//이전 프레임에 눌러져 있었다 UP
				if (Keys[i].bPressed == true)
				{
					Keys[i].State = EKeyState::Up;
				}
				//이전 프레임도 지금도 눌러져 있지 않다 None
				else
				{
					Keys[i].State = EKeyState::None;
				}

				Keys[i].bPressed = false;
			}
		}
	}
}