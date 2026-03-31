#pragma once
#include "CommonInclude.h"
#include "XGameObject.h"

namespace xollo
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND Hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
	
	
	
	private:
		HWND mHwnd;
		HDC mHdc;
		//플레이어
		GameObject mPlayer;
		GameObject RedPlayer;
	};

}

