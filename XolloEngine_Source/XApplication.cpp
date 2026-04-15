#include "XApplication.h"
#include "XInput.h"
#include "XTime.h"
#include "XSceneManager.h"

namespace xollo
{
	Application::Application() : 
		mHwnd(nullptr), 
		mHdc(nullptr),
		Width(0),
		Height(0),
		BackDC(NULL),
		BackBitMap(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND Hwnd, UINT width, UINT height)
	{
		//핸들과 dc는 다 주소로 돼있어서 포인터 x
		mHwnd = Hwnd;
		mHdc = GetDC(mHwnd);

		RECT Rect = { 0, 0, width, height};
		AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW, false);

		Width = Rect.right - Rect.left;
		Height = Rect.bottom - Rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, Width, Height, 0);
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 BackBuffer(도화지) 생성
		BackBitMap = CreateCompatibleBitmap(mHdc, Width, Height);

		//새로 생성한 BackBuffer를 가르킬 DC 생성
		BackDC = CreateCompatibleDC(mHdc);

		HBITMAP OldBitMap = (HBITMAP)SelectObject(BackDC, BackBitMap);
		DeleteObject(OldBitMap);

		SceneManager::Initialize();

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();

		Time::Render(BackDC);
		SceneManager::Render(BackDC);

		//backdc 그린거를 원본 dc에 옮겨야함
		CopyRenderTarget(BackDC, mHdc);
	}

	void Application::ClearRenderTarget()
	{
		Rectangle(BackDC, -1, -1, 1601, 901);
	}

	void Application::CopyRenderTarget(HDC Source, HDC Dest)
	{
		//back 버퍼에 복사한 그림을 main 버퍼에 올려
		BitBlt(Dest, 0, 0, Width, Height, Source, 0, 0, SRCCOPY);
	}
}
