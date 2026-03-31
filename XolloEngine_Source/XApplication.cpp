#include "XApplication.h"
#include "XInput.h"

namespace xollo
{
	Application::Application() : 
		mHwnd(nullptr), 
		mHdc(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND Hwnd)
	{
		//핸들과 dc는 다 주소로 돼있어서 포인터 x
		mHwnd = Hwnd;
		mHdc = GetDC(mHwnd);

		mPlayer.SetPosition(0, 0);
		mPlayer.SetObjectName(EObjectName::Blue);
		RedPlayer.SetPosition(0, 0);
		RedPlayer.SetObjectName(EObjectName::Red);

		Input::Initialize();
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

		mPlayer.Update();
		RedPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
		RedPlayer.Render(mHdc);
	}
}
