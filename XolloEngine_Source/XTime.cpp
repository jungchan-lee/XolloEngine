#include "XTime.h"

namespace xollo
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTime = 0.0f;

	void Time::Initialize()
	{
		//CPU 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		//프로그램이 시작 했을 때 현재 진동 수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		// 8바이트 정수를 float에 맞게 캐스팅
		float DifferenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart); 
		DeltaTime = DifferenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float Time = 0.0f;

		Time += DeltaTime;
		float Fps = 1.0f / DeltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)Fps);
		int len = wcsnlen_s(str, 50);

		

		TextOut(hdc, 0, 0, str, len);
	}
}