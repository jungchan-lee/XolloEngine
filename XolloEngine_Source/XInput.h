#pragma once
#include "CommonInclude.h"

namespace xollo
{
	enum class EKeyState
	{
		Down,
		Pressed,
		Up,
		None,

	};

	enum class EKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End
	};
	
	class Input
	{
	public:
		struct Key
		{
			EKeyCode KeyCode;
			EKeyState State;
			bool bPressed;

		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(EKeyCode Code) { return mKeys[(UINT)Code].State == EKeyState::Down; }
		static bool GetKeyUp(EKeyCode Code) { return mKeys[(UINT)Code].State == EKeyState::Up; }
		static bool GetKey(EKeyCode Code) { return mKeys[(UINT)Code].State == EKeyState::Pressed; }

	private:
		static std::vector<Key> mKeys;

	};

}

