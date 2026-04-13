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

		void Initialize(HWND Hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	
	private:
		void ClearRenderTarget();
		void CopyRenderTarget(HDC Source, HDC Dest);
	
	private:
		HWND mHwnd;
		HDC mHdc;

		//DC안에 도화지가 디폴트로 드가 있음 그게 비트맵 도화지
		//원본 그대로의 그림 파일이 비트맵 bitmap[1920][1080] 2차원 배열로 돼있음
		HDC BackDC;
		HBITMAP BackBitMap;

		UINT Width;
		UINT Height;


		//std::vector<Scene*> Scenes;
		//std::vector<GameObject*> GameObjects;
	};

}

